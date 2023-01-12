/*!
 * \file windump.cpp
 *
 * \brief
 *
 * \version 0.1
 * \date 2014/01/21
 * \author Ana Loizeau - ana.loizeau@eseo.fr
 *
 * \warning
 * \bug
 * \todo startCapture do not support auto stop on timeout
 * \todo add function to filter a raw capture file afterwards (pcap format)
 */
#include "windump.h"
#include "netconfig.h"
#include "netsh.h"
#include <QDir>
#include <QByteArrayMatcher>

//--------------------------------------
// Creator/destructor
//--------------------------------------

/*!
 * \brief Windump::Windump
 * \warning Do not allocate heap objects (using new) in this constructor
 */
Windump::Windump(QObject *parent) :
    QThread(parent)
{
    /* Initialize params */
    selectedInterface = 0;
    //pathToWindump = default;
    captureFile = NULL;
    //removeFile = false;
    //QString captureFilter;
    captureMode = WINDUMP_EMIT_MODE_ALL;
    go = false;

    /* Link error messages when possible */
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            parent, SLOT(messageFromLowerLayer(int, QString)));
}

Windump::~Windump(){
    /* Kill terminal */
    cmdshell.close();
}

//----------------------------------
// Public methods
//----------------------------------
/*!
 * \brief Windump::setPath
 * \param path
 * \return
 * \warning path SHALL NOT contain special ASCII chars (à, ü, ó ...)
 */
bool Windump::setPath(QString path){
    bool success = false;
    QFile filename(path + "/WinDump.exe");
    if (filename.exists()){
        pathToWindump = path;
        qDebug() << "[WINDUMP] Set path : " << path;
        success = true;
    }
    else{
        emit sigMessageToUpperLayer(0,tr("Windump not found at ") + path);
        qDebug() << "[WINDUMP] Invalid path : " << path;
    }
    return success;
}

/*!
 * \brief Windump::selectInterface
 * \param name
 * \return
 * \warning Supports up to 9 interfaces
 */
bool Windump::selectInterface(QString name){
    bool success = false;

    // Get system information for interface
    NetConfig inferface;
    int systemIndex = inferface.getInterfaceId(name);
    QString systemName = inferface.getInterfaceSystemName(systemIndex);

    // execute windump -D and find out interfaceId
    QByteArray result;
    Netsh netsh;
    QString cmd = "/WinDump.exe -D \r\n";
    cmd.prepend(pathToWindump);
    success = netsh.sendCmdOnShellUtf8(cmd, &result);
    if (success){
        int pos, i;
        QList<QByteArray> resultlines = result.split('\n');
        QByteArrayMatcher matcher(systemName.toUtf8());
        for (i=0; i<resultlines.size(); i++){
            pos = matcher.indexIn(resultlines[i], 0);
            if (pos != -1){
                // Extract number from beginning of line
                selectedInterface = resultlines[i].left(1).toInt(&success);
                qDebug() << "[WINDUMP] Interface selected : " << name;
                // force exit
                i=resultlines.size();
            }
        }
    }
    return success;
}

bool Windump::isInterfaceSelected(){
    return (selectedInterface != 0);
}


/*!
 * \brief Windump::startCapture
 * \param capture
 * \param filter Store results on file (NO SPACES ALLOWED)
 * \param mode Emit mode
 * \param timeout Capture duration in ms (-1 stands for infinite)
 * \return true if capture started
 */
bool Windump::startCapture(QFile *capture, QString filter, Windump::mode mode, int timeout){
    bool success = false;

    if (!go){
        if (NULL != capture)
            captureFile = capture;
        captureFilter = filter;
        captureMode = mode;
        captureTo = timeout;

        go = true;
        success = true;
    }
    return success;
}


bool Windump::isRunning(){
    return go;
}

bool Windump::getCaptureEvent(int eventId, QByteArray *event){
    bool success = false;

    if (eventId < captureResults.size()){
        *event = captureResults.at(eventId);
        success = true;
    }
    return success;
}


bool Windump::unitTest(){
    bool success = false;

    this->start(QThread::InheritPriority);

    success = setPath("D:/Tools"); // expect true - Windump is at this location
    //success = selectInterface("Connexion au réseau local 7");
    success = selectInterface("Connexion au réseau local");

    QFile *capture = new QFile("D:/Temp/network/captureFile.log", this); // C:/Windows/Temp/windump.log
    success = startCapture(capture, QString("arp"), WINDUMP_EMIT_MODE_ALL, 1000);
    //success = startCapture(capture, QString("tcp[0:2]==80"), WINDUMP_EMIT_MODE_ALL, 1000);
    //success = startCapture(NULL, QString("arp[14:4]==arp[24:4]"), WINDUMP_EMIT_MODE_ALL, 1000); // KO
    //success = startCapture(capture, QString("ether[6:2]==0x00C0&&ether[8:1]==0xB7"), WINDUMP_EMIT_MODE_ALL, 1000);
    //runCapture();
    success = isRunning();

    while (success);
    stopCapture();
    //QByteArray event;
    //success = getCaptureEvent(0, &event);

    return success;
}

//----------------------------------
// Private methods
//----------------------------------
/*!
 * \brief Windump::run
 */
void Windump::run(){
    bool ready = false;
    qDebug() << "[WINDUMP] Thread started !";

    while (true){

        /* Windump configuration verification */
        if (!ready){
            /* Check path and interface validity */
            if ((!pathToWindump.isEmpty()) &&
                (0 != selectedInterface) ){
                qDebug() << "[WINDUMP] Windump configured !";
                ready = true;
            }
        }

        if (ready && go){
            /* Start capture */
            qDebug() << "[WINDUMP] Start Capture !";

            /* Start WinDump */
            if (true == startWindump())
            {
                captureResults.clear();
                notify(true);
                //sendCmd(&cmdshell, &cmd); /* retval ignored */
                while (go){
                    /* Capture and treat data */
                    if (readLines() > 0){
                        notify(false);
                    }
                    else
                        msleep(100);
                }

                /* Notify on stop - may renotify last event depending on mode */
                notify(false);

                /* Store results */
                if (saveCapture()){
                    qDebug() << "[WINDUMP] Capture saved !";
                }
                else {
                    qDebug() << "[WINDUMP] Capture not saved !";
                }

                /* Kill terminal */
                cmdshell.close();
            }
        }

        /* loop until ready && go are set again */
    }
}

bool Windump::startWindump(){
    // Open shell - inspired from Netsh::sendCmdOnShellUtf8

    QStringList paramlist;
    /* -e  : Print MAC address
     * -vv : Be verbose
     * -n  : Do not resolve DNS names
     * -l  : Make stdout line buffered. Useful if you want to see the data while capturing
     * -U  : Make the printed packet output ``packet-buffered''; i.e., as the description of the contents of each packet is printed, it will be written to the standard output, rather than, when not writing to a terminal, being written only when the output buffer fills.
     * -s  : store packet data up to size (bytes)
     * -i  : Interface to use */
    paramlist.append(QString("-e"));
    paramlist.append(QString("-vv"));
    paramlist.append(QString("-n"));
    //paramlist.append(QString("-s 128"));
    QString interface("-i ");
    /* On Windows, arguments that contain spaces are wrapped in quotes.*/
    interface.append(static_cast<QChar>(selectedInterface + '0'));
    paramlist.append(interface);
    paramlist.append(QString("-l"));

    paramlist.append(captureFilter);
    //paramlist.append(QString("ether[6:2]==0x00C0 && ether[8:1]==0xB7")); // ok

    //cmdshell.start(QString("D:/Tools/WinDump.exe"),paramlist, QIODevice::Unbuffered | QIODevice::Text | QIODevice::ReadWrite);
    cmdshell.start(QString(pathToWindump + "/WinDump.exe"),paramlist, QIODevice::Unbuffered | QIODevice::Text | QIODevice::ReadWrite);
    return cmdshell.waitForStarted(1000);
}

int Windump::readLines(){
    int nblines = 0;

    int i;
    QByteArray result;
    QList<QByteArray> resultlines;
    /* The Windows implementation of QProcess is hard-coded
     * to check once every 100 milliseconds for stdout/stderr
     * from the external process --> no need to check more often */
    if (cmdshell.bytesAvailable()>0 ||
        cmdshell.waitForReadyRead(500)){
        result = cmdshell.readAll();
        qDebug() << "[WINDUMP] ReadLines " << result.size();
        resultlines = result.split('\n');
        for (i=0; i<resultlines.size(); i++)
            if (!resultlines.at(i).isNull()){
                captureResults.append(resultlines.at(i)+"\n");
                nblines++;
            }
        /* Check if last item is a complete line, otherwise, remove trailing \n */
        if (result.size()>0 &&
            result.at(result.size()-1) != '\n'){
            i = captureResults.at(captureResults.size()-1).size(); /* Size of last stored line */
            if (i>0){
                QByteArray tmp = captureResults.at(captureResults.size()-1);
                tmp.remove(i-1,1);
            }
        }
    }
    else{
        qDebug() << "[WINDUMP] ReadLines -1";
    }
    return nblines;
}


void Windump::notify(bool reset){

    int i = 0;
    static int lastevent = -1; /* Keep count of last notified event */

    /* Reset event counter */
    if (reset){
        lastevent = -1;
    }
    else {
        switch (captureMode){
            case WINDUMP_EMIT_MODE_FIRST:
                /* Emit - Only if this event is the fist one */
                if (lastevent == -1){
                    lastevent = 0;
                    emit sigWindumpCaptureEvent(lastevent);
                    qDebug() << "[WINDUMP] Notify " << lastevent;
                }
                /* Event has no timestamps - do not notify */
            break;

            case WINDUMP_EMIT_MODE_ALL:
                /* Emit on every event */
                for (i=lastevent+1; i<captureResults.size(); i++){
                    emit sigWindumpCaptureEvent(i);
                    qDebug() << "[WINDUMP] Notify " << i;
                }
                lastevent = i-1;

            break;

            case WINDUMP_EMIT_MODE_END:
                if (!go){
                    /* Emit once capture has stopped */
                    emit sigWindumpCaptureEvent(captureResults.size());
                    qDebug() << "[WINDUMP] Notify " << '0' + captureResults.size();
                }
            break;

            default:
                // Nothing to do
                qDebug() << "[WINDUMP] Nothing to notify !";
                break;
        }
    }
    return;
}

bool Windump::saveCapture(){
    bool success = false;
    // Flush results on file
    if (captureFile != NULL && captureFile->open(QIODevice::WriteOnly)){
        int len;
        QTextStream datastream(captureFile);
        for (len=0;len<captureResults.size();len++)
            datastream << captureResults.at(len);
        captureFile->close();
        success = true;
    }
    return success;
}


//----------------------------------
// Signals
//----------------------------------

//----------------------------------
// Public Slots
//----------------------------------
void Windump::stopCapture(void){
    qDebug() << "[WINDUMP] Stop Capture !";
    go = false;
}
