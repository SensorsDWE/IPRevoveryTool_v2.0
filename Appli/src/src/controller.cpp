/*!
 * \file controller.cpp
 *
 * \brief
 *
 * \version 0.1
 * \date 2014/01/21
 * \author Ana Loizeau - ana.loizeau@eseo.fr
 *
 * \warning
 * \bug
 * \todo
 */
#include "controller.h"
#include "logger.h"
#include <QByteArrayMatcher>
#include <QDebug>
#include <QThread>
#include <QDir>
#include <QTime>
#include <QCoreApplication>

//--------------------------------------
// Creator/destructor
//--------------------------------------

Controller::Controller(QObject *parent) :
    QThread(parent)
{
    /* Initialize params */
    selectedSensor = -1;
    restoreInterface = 0;

    /* Prepare toolboxes (model) */
    netconfig = new NetConfig(this);
    netsh = new Netsh(this);
    sniffer = new Windump(this);
    logger = new Logger(this);

    /* Link Model to Controller */
    connect(sniffer, SIGNAL(sigWindumpCaptureEvent(int)),
            this, SLOT(windumpEventHandler(int)));

    /* Link Controller to Model */

    /* Link error messages when possible */
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            parent, SLOT(messageFromLowerLayer(int, QString)));

}


//----------------------------------
// Public methods
//----------------------------------

bool Controller::unitTest(){
    bool success = false;

    this->start(QThread::InheritPriority);

    windumpEventHandler(0); // Expect graceful error handling

    QByteArray fakeEvent("08:54:25.767362 b4:b5:2f:83:91:58 (oui Unknown) > Broadcast, ethertype ARP (0x0806), length 42: arp who-has 192.168.0.10 tell 192.168.0.10");
    success = this->windumpEventParser(fakeEvent);

    QByteArray filter;
    success = windumpGenerateMacFilter(&filter);

    //this->clearSensorList();

    return success;
}

Controller::~Controller(){
    clearSensorList();
}

//----------------------------------
// Private methods
//----------------------------------
void Controller::run(){

    qDebug() << "[CONTROLLER] Thread started !";

    //QString path("D:/Tools");
    QString path(QDir::currentPath());
    if ( sniffer->setPath(path) ) {
        /* Start Sniffer thread */
        sniffer->start(QThread::InheritPriority);

        /* Nothing more to do here, this is a thread for event processing only */
        this->exec();
    }
}

bool Controller::windumpEventParser(QByteArray event){

    bool ok, success = false;
    QString mac,ip;
    static QByteArray fullevent; /* Event may be splitted */
    QByteArray pattern("arp who-has");
    QByteArrayMatcher matcher(pattern);

    fullevent.append(event);
    int pos = matcher.indexIn(fullevent, 0);
    if (pos != -1){
        /* This event is ARP - check if it is gratuitous */
        pos = pos + pattern.size() + 1;

        /* Extract ip address
         * Format: ...arp who-has 169.254.37.20 tell ...*/
        QList<QByteArray> eventExtract = fullevent.mid(pos,16).split(' ');
        if (!eventExtract.at(0).isEmpty()){

            /* Check if this seems to be an IP (could be an alias) */
            eventExtract.at(0).left(1).toInt(&ok);
            pos = pos + eventExtract.at(0).size();

            /* IP found - Look for a duplicate (meaning gratuitous)*/
            matcher.setPattern(eventExtract.at(0));
            pos = matcher.indexIn(fullevent, pos);
            if (ok && pos!= -1 ){

                /* Duplicate found, but may be a longer addr... */
                fullevent.mid(pos+eventExtract.at(0).size(),1).toInt(&ok);
                if (!ok){

                    /* Duplicate found */
                    ip.append(eventExtract.at(0));

                    /* Get MAC addr */
                    eventExtract = fullevent.left(pos).split(' ');
                    if (eventExtract.size()>=2 &&
                        eventExtract.at(1).size() == 17){
                        /* Extract mac address
                         * Format: 08:54:25.519651 b4:b5:2f:83:91:58 (oui...*/
                       mac.append(eventExtract.at(1));

                       /* Update Sensor list */
                       success = updateSensorList(mac, ip);
                    }
                }
            }
        }
    }
    if (fullevent.at(fullevent.size()-1) == '\n')
        fullevent.clear();

    return success;
}

void Controller::clearSensorList(){

    while (sensorList.size()>0){
        delete sensorList.first();
        sensorList.removeFirst();
    }
    return;
}


bool Controller::updateSensorList(QString mac, QString ip){
    bool found = false;

    int i;
    Sensor *check;
    for (i=0; i<sensorList.size() && !found ;i++){
        check = sensorList.at(i);
        found = check->mirrorTest(mac);
    }

    if (found){
        /* Update existing item when needed */
        if (check->getCurrentIpAddress() != ip){
           if ( check->setCurrentConfig(ip, QString("255.255.255.0"),QString("0.0.0.0")) ){
                QString entry;
                entry.setNum(sensorHashList.value(mac));
                entry.append(" - MAC " + mac + " - IP " + ip);
                emit sigControllerNewItem(CTRL_ITEM_SENSOR_UPDATE, entry);
                qDebug() << "[CONTROLLER] Updated Entry : " << entry;
           }
           else
               found = false;
        }
    }
    else{
        /* Create new item */
        Sensor *newsensor= new Sensor(mac, this);

        /* Configure and notify */
        if (newsensor->setCurrentConfig(ip, QString("255.255.255.0"),QString("0.0.0.0"))){
            sensorList.append(newsensor);
            sensorHashList.insert(mac,sensorList.size()-1);
            QString entry;
            entry.setNum(sensorList.size()-1);
            entry.append(" - MAC " + mac + " - IP " + ip);
            emit sigControllerNewItem(CTRL_ITEM_SENSOR, entry);
            qDebug() << "[CONTROLLER] New Entry : " << entry;
            found = true;
        }
        else
            delete newsensor;
    }

    return found;
}

void Controller::sensorShow(){
    if (selectedSensor >= 0){
        Sensor *item = sensorList.at(selectedSensor);
        item->getConfigFromSensor(true);
        item->saveCurrentConfig();
        item->show();
        item->raise();
    }
    else
        emit sigMessageToUpperLayer(1,tr("Please select one device"));
}

bool Controller::windumpGenerateMacFilter(QByteArray *filter){
    bool success = false;

    Logger configfile;
    QString result;
    QByteArray tmpfilter;

    if (configfile.logExists("config.xml") &&
        configfile.logOpen("config.xml")){
        if (configfile.logRead(&result)){
            /* Search for <macfilter> token */
            int start, end, i;
            QByteArray data(result.toUtf8());
            QByteArray starttoken("<macfilter>");
            QByteArray endtoken("</macfilter>");
            QByteArrayMatcher matcher;

            tmpfilter.append("(");
            matcher.setPattern(starttoken);
            start = matcher.indexIn(data,0);
            while (start!=-1){
                /* Found start token */
                start = start + starttoken.size();
                matcher.setPattern(endtoken);
                end = matcher.indexIn(data,start);
                if (end!=-1){
                    /* Found end token */
                    /* Parse a MAC address - Format 00:11:22:33:44:55 */
                    QList<QByteArray> list = data.mid(start,end-start).split(':');
                    if (list.size()>0 &&
                        !list.at(0).isEmpty() &&
                        list.size() <=6){
                        tmpfilter.append("(");
                        for (i=0; i<list.size(); i++ ){
                            //QString filter("ether[6:2]==0x00C0&&ether[8:1]==0xB7");
                            tmpfilter.append("ether[" + QByteArray::number(6+i) + ":1]==0x");
                            tmpfilter.append(list.at(i));
                            tmpfilter.append("&&");
                        }
                        tmpfilter.remove(tmpfilter.size()-2,2); /* remove trailing "&&" */
                        tmpfilter.append(")||");
                    }
                }

                /* Search again */
                matcher.setPattern(starttoken);
                start = matcher.indexIn(data,start);
            }

            /* Check if tmp filter has stuff in it */
            if (tmpfilter.size()>1){
                tmpfilter.remove(tmpfilter.size()-2,2); /* remove trailing "||" */
                tmpfilter.append(")");
                filter->clear();
                *filter = tmpfilter;
                qDebug() << "[CONTROLLER] Windump filter : " << tmpfilter.data();
                success = true;
            }
        }
        else
            qDebug() << "[CONTROLLER] No data read on config.xml";

        configfile.logClose();
    }
    else
        qDebug() << "[CONTROLLER] config.xml not found";


    return success;
}



void Controller::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

//----------------------------------
// Signals
//----------------------------------



//----------------------------------
// Public Slots
//----------------------------------
/*!
 * \brief Controller::messageFromLowerLayer
 * \param level 0=ERROR, 1=WARNING, 2=INFO
 * \param error message
 */
void Controller::messageFromLowerLayer(int level, QString error)
{
    /* Forward Error to View */
    emit sigMessageToUpperLayer(level, error);
}

void Controller::mainWindowCmdHandler(Controller::cmdId cmd, QString name){

    switch (cmd){
        case CTRL_CMD_REFRESH_INTERFACES:
            if(netconfig){
                QList<QString> list = netconfig->getInterfaceNameList();
                int i;
                for (i=0; i<list.size(); i++){
                    emit sigControllerNewItem(CTRL_ITEM_INTERFACE,list.at(i));
                }
            }
        break;

        case CTRL_CMD_SELECT_INTERFACE:
            if (sniffer){
                if (sniffer->selectInterface(name))
                    selectedInterfaceName = name;
            }
        break;

        case CTRL_CMD_SCAN_START:
        if (sniffer){
            if (sniffer->isInterfaceSelected()){
                QString filter("arp&&ether[6:2]==0x00C0&&ether[8:1]==0xB7");
                //               QString filter("arp");

                /* Add MAC filter when possible */
                QByteArray macfilter;
                if (windumpGenerateMacFilter(&macfilter)){
                    filter.append("&&");
                    filter.append(macfilter);
                }

                /* Start capture */
                sniffer->startCapture(NULL, filter, Windump::WINDUMP_EMIT_MODE_ALL,1000);

                emit sigMessageToUpperLayer(2,tr("Scanning started, please reboot the device"));
            }
            else {
                emit sigControllerNewItem(CTRL_ITEM_SCAN_ERROR, 0);
                emit sigMessageToUpperLayer(1,tr("Please select one interface"));
            }
        }
        break;

        case CTRL_CMD_SCAN_STOP:
        if (sniffer)
            sniffer->stopCapture();
        break;

        case CTRL_CMD_SCAN_CLEAR:
            selectedSensor = -1;
            clearSensorList();
        break;

        case CTRL_CMD_CONFIG_SENSOR:

        break;

        case CTRL_CMD_SELECT_SENSOR:
        {
            bool success;
            QStringList items = name.split(' ');
            selectedSensor = items.at(0).toInt(&success);
            if (!success)
                selectedSensor = -1;
        }
        break;

        case CTRL_CMD_LOAD_SENSOR:
        {
            QString data;
            Logger cfg;
            if (cfg.logOpenAbsolute(name)){
                if (cfg.logRead(&data)){
                    QStringList items = data.split(' ');
                    if (items.size()>=2)
                        updateSensorList(items.at(0),items.at(1));
                    else
                        emit sigMessageToUpperLayer(1,tr("Cannot load device"));
                }
                cfg.logClose();
            }
        }
        break;

        default:
        break;
    }

}

void Controller::windumpEventHandler(int eventId){

    QString mac, ip;
    QByteArray event;

    // Get event
    if (NULL != sniffer &&
        sniffer->getCaptureEvent(eventId, &event)){
        qDebug() << "[CONTROLLER] Event : " << eventId;
        bool success = this->windumpEventParser(event);
    }
}

/*!
 * \brief Controller::sensorEventRequestNetworkChange
 * \brief Configure selectedInterface to be compatible with parameters below
 * \param ip
 * \param mask
 */
void Controller::sensorEventRequestNetworkChange(QString ip, QString mask){
    bool success = false;
    restoreInterface = 0;

    if (!selectedInterfaceName.isEmpty()){
        if (cfgMutex.tryLock()){
            int index = netconfig->getInterfaceId(selectedInterfaceName);
            if (index>0){
                success = netconfig->isInSubnet(index, ip, mask);
                if (!success){
                    /* Need to change interface parameters */
                    QString newip(ip);
                    if (newip.at(newip.size()-1) != '7')
                        newip[newip.size()-1] = '7';
                    else
                        newip[newip.size()-1] = '9';
                    restoreInterface = new QFile(QDir::currentPath()+"/restore.txt");
                    if (restoreInterface->exists()){
                        qDebug() << "[CONTROLLER] Warning: Restoration file detected!";
                    }
                    success = netsh->setInterface(selectedInterfaceName,
                                                  newip, mask, QString(""),
                                                  false, restoreInterface);
                    if (success){
                        qDebug() << "[CONTROLLER] Network change OK - restore file at: " << restoreInterface->fileName();
                        /* Introduce a 1sec delay to allow interface to start reconfiguration procedure */
                        sleep(1);
                    }
                    else{
                        qDebug() << "[CONTROLLER] Network change failed";
                        emit sigMessageToUpperLayer(0, tr("Network change failed, please configure local address manually"));
                    }
                }
                else{
                    qDebug() << "[CONTROLLER] Network change unnecessary";
                }
            }
            else{
                emit sigMessageToUpperLayer(0, tr("Invalid interface, please check that connection is up"));
            }
            cfgMutex.unlock();
        }
        else
            qDebug() << "[CONTROLLER] Cfg mutex not available - please wait";
    }
    else{
        emit sigMessageToUpperLayer(1,tr("Please select one interface"));
    }
    emit sigControllerNetworkReady(success);
}


void Controller::sensorEventRequestNetworkRestore(){
    bool success;
    if (restoreInterface &&
        cfgMutex.tryLock()){
        success = netsh->applyNetworkConfig(restoreInterface);
        qDebug() << "[CONTROLLER] Network restore :" << success;
        delete restoreInterface;
        restoreInterface = 0;
        cfgMutex.unlock();
    }
}

void Controller::sensorEventConfigChanged(QString mac){

    QString entry;
    Sensor *sensor = sensorList.at(sensorHashList.value(mac));
    if (sensor->mirrorTest(mac)){
        entry.setNum(sensorHashList.value(mac));
        entry.append(" - MAC " + sensor->getMacAddress() + " - IP " + sensor->getCurrentIpAddress()+ tr(" - scan required"));
        emit sigControllerNewItem(CTRL_ITEM_SENSOR_ALARM, entry);
    }

}
