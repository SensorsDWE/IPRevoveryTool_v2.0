/*!
 * \file netsh.cpp
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
#include "netsh.h"
#include <QTextStream>
#include <QProcess>
#include <QByteArray>
#include <QByteArrayMatcher>
#include <QDir>
#include <QTextCodec>
#include <QNetworkAccessManager>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>
#include <QSysInfo>


//--------------------------------------
// Creator/destructor
//--------------------------------------

Netsh::Netsh(QObject *parent) :
    QObject(parent)
{
    QSysInfo sysInfo;
    QSysInfo::WinVersion version = sysInfo.windowsVersion();
    if (version > QSysInfo::WV_XP)
        win7 = true;
    else
        win7 = false;
}

//----------------------------------
// Public methods
//----------------------------------
/*!
 * \brief Netsh::saveNetworkConfig
 * \param cfg
 * \return true if network config was saved successfully
 */
bool Netsh::saveNetworkConfig(QFile *cfg){
    bool success;

    QByteArray result;
    QString cmd = "netsh interface dump > ";

    cmd.append(cfg->fileName() + " \r\n");
    success = sendCmdOnShell(cmd, &result);

    return success;
}

/*!
 * \brief Netsh::applyNetworkConfig
 * \param cfg
 * \return true if network config was applied successfully
 */
bool Netsh::applyNetworkConfig(QFile *cfg){
    bool success;

    QByteArray result;
    QString cmd = "netsh -f ";

    cmd.append(cfg->fileName() + " \r\n");
    success = sendCmdOnShell(cmd, &result);

    return success;
}

/*!
 * \brief Netsh::setInterface
 * \param name Friendly name of the interface
 * \param ip New IP address
 * \param mask New netmask
 * \param gw New gateway
 * \param dhcp New mode (true for DHCP, false for static IP)
 * \param restore path to recovery file (to be reapplied after operation)
 * \return true if success
 */
bool Netsh::setInterface(QString name, QString ip, QString mask, QString gw, bool dhcp, QFile *restore){
    bool success;
    bool restoredhcp = false;
    QByteArray result;
    QByteArrayMatcher matcher;

    // Get current codepage to tune the codec accordingly
    // Windows FR (Latin1) = 850, Windows US = 437, UTF-8 = 65001
    char currentCodepage[16];
    success = sendCmdOnShell("chcp \r\n", &result);
    if (success){
        int pos;
         matcher.setPattern(QByteArray("chcp"));
         pos = matcher.indexIn(result, 0);
         if (pos != -1){
             QChar tmpChar = result.at(pos);
             while (!tmpChar.isDigit() &&
                    pos<result.size()){
                 pos++;
                 tmpChar = result.at(pos);
             }
             int i = 0;
             while (tmpChar.isDigit() &&
                    pos<result.size() &&
                    i<15){
                 currentCodepage[i] = result.at(pos);
                 i++;
                 pos++;
                 tmpChar = result.at(pos);
             }
             currentCodepage[i]='\0';
         }
         else{
            // ELSE Cannot get codepage - abort
             success = false;
         }
    }

    // Get config and verity dhcp settings
    if (success){
        QByteArray nameByteArray("name=\"");
        nameByteArray.append(name);
        matcher.setPattern(nameByteArray);
        // Use Utf8 to ensure that strings are checked properly
        success = sendCmdOnShellUtf8("netsh interface ip dump \r\n", &result);
        if (success){
            // look for a manual config for this interface, otherwise it is DHCP
            int pos = matcher.indexIn(result, 0);
            if ( pos == -1)
                restoredhcp = true;
            else{
                /* check that this is an static entry */
                matcher.setPattern(QByteArray("dhcp"));
                int eol = result.indexOf('\n',pos);
                pos = matcher.indexIn(result, pos);
                if ( pos != -1 &&
                    (eol == -1 || pos < eol) )
                    restoredhcp = true;
            }
        }
        // ELSE Cannot access to config - abort
    }

    // Prepare restore file
    QTextStream datastream;
    if (success){
        success = restore->open(QIODevice::WriteOnly | QIODevice::Text);
        if (success){
            datastream.setDevice(restore);
            datastream.setCodec(currentCodepage);
            datastream << "pushd interface ip \r\n"; /* ip = Windows XP compatibility, vs ipv4 */
            /* Do not add "reset" in order to preserve current config as much as possible */
            if (restoredhcp)
                datastream << "set address name=\"" << name << "\" dhcp \r\n"; /* Do this operation first, otherwise XP rejects delete*/
            datastream << "delete address name=\"" << name << "\" addr=" << ip << "\r\n";  /* addr = WinXP compat, vs adddress */
            datastream << "popd \r\n";
            restore->close();
        }
        // ELSE Cannot create backup file - abort

    }

    // Create temporary file used for setting the interface
    QFileInfo restoreFileInfo(*restore);
    QFile cfg(restoreFileInfo.absolutePath() + "/tmp.txt");
    if (success){
        success = cfg.open(QIODevice::WriteOnly | QIODevice::Text);
        if (success){
            datastream.setDevice(&cfg);
            datastream.setCodec(currentCodepage);
            datastream << "pushd interface ip \r\n"; /* ip = Windows XP compatibility, vs ipv4 */
            /* Do not add "reset" in order to preserve current config as much as possible */
            if (dhcp)
                datastream << "set address name=\"" << name << "\" dhcp \r\n";
            else{
                datastream << "add address name=\"" << name << "\" addr=" << ip << " mask=" << mask; /* addr = WinXP compat, vs adddress */
                if (win7)
                    datastream << " store=active "; /* Nice option supported only on > WinXP */
                datastream << "\r\n";
            }
            datastream << "popd \r\n";
            cfg.close();
        }
        // ELSE Cannot create config file - abort
    }

    // Set new config
    if (success){
        success = applyNetworkConfig(&cfg);
        if (success)
            qDebug() << "[NETSH] Interface reconfiguration OK";
        else
            qDebug() << "[NETSH] Interface reconfiguration failed";
        //cfg.remove();
    }
    else{
        qDebug() << "[NETSH] Interface reconfiguration aborted";
    }

    return success;
}


/*!
 * \brief Netsh::unitTest
 * \return true if success
 */
bool Netsh::unitTest(){
    qDebug() << "[NETSH] Running unitTest";

    bool success;
    QFile cfg;

    cfg.setFileName("D:/Temp/network/save.txt");
    success = saveNetworkConfig(&cfg); // Expect true + data on file

    cfg.setFileName("D:/Temp/network/restore.txt");
    success = setInterface("Connexion au réseau local",
                           "192.168.49.85",
                           "255.255.255.0",
                           "192.168.49.33",
                           false, &cfg); // Expect true + restore on interface
    success = applyNetworkConfig(&cfg); // Expect true + restore on interface

    success = setInterface("Connexion au réseau local",
                           NULL,NULL, NULL,
                           true, &cfg); // Expect true + restore on interface
    success = applyNetworkConfig(&cfg); // Expect true + restore on interface


    cfg.setFileName("D:/Temp/network/save.txt");
    success = applyNetworkConfig(&cfg); // Expect true + restore on interface

    return success;
}

bool Netsh::sendCmdOnShellUtf8(QString cmd, QByteArray *result){
    // Prepend chcp 65001 to change charset to UTF-8
    cmd.prepend("chcp 65001 && ");
    return sendCmdOnShell(cmd, result);
}


bool Netsh::sendCmdOnShell(QString cmd, QByteArray *result){
    bool success = false;

    QProcess cmdshell;
    cmdshell.start("cmd"); // do not use option "/c"
    if (cmdshell.waitForStarted(1000)){
        QByteArray cmdByteArray;
        cmdByteArray.append(cmd.toLatin1());
        cmdshell.write(cmdByteArray);
        //cmdshell.write("ipconfig \r\n");
        cmdshell.closeWriteChannel();

        if (cmdshell.waitForFinished(8000)){
            *result = cmdshell.readAll();
            success = true;
        }
    }
    return success;
}

//----------------------------------
// Private methods
//----------------------------------

//----------------------------------
// Signals
//----------------------------------

//----------------------------------
// Public Slots
//----------------------------------
