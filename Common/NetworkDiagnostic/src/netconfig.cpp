/*!
 * \file netsh.cpp
 *
 * \brief
 *
 * \version 0.1
 * \date 2014/01/29
 * \author Ana Loizeau - ana.loizeau@eseo.fr
 *
 * \warning QT cannot assign IP address because this task is not platform independent
 * \warning Use Native APIs or QProcess to launch external program
 * \bug
 * \todo
 */
#include "netconfig.h"
#include <QNetworkAccessManager>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>


//--------------------------------------
// Creator/destructor
//--------------------------------------
NetConfig::NetConfig(QObject *parent) :
    QObject(parent)
{
}

NetConfig::~NetConfig()
{
}

//----------------------------------
// Public methods
//----------------------------------
/*!
 * \brief NetConfig::getInterfaceNameList
 * \return
 */
QList<QString> NetConfig::getInterfaceNameList(){
    int i;
    // list == netsh interface ip show config
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();
    InterfaceNameList.clear();
    for (i=0;i<interfaceList.size();i++)
        InterfaceNameList.append(interfaceList[i].humanReadableName());
    return InterfaceNameList;
}

/*!
 * \brief NetConfig::getInterfaceId
 * \param name Friendly name of the interface to search for
 * \return Returns the interface system index (0 if unknown).
 */
int NetConfig::getInterfaceId(QString friendlyName){
    int i;
    int index = 0;
    // index == netsh interface ip show interfaces
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();
    for (i=0;i<interfaceList.size() && 0==index ;i++){
        if (interfaceList[i].isValid() &&
            friendlyName == interfaceList[i].humanReadableName())
            index = interfaceList[i].index();
    }
    return index;
}

/*!
 * \brief NetConfig::getInterfaceFriendlyName
 * \param index
 * \return Friendly name of the interface to search for
 */
QString NetConfig::getInterfaceFriendlyName(int index){
    QString name;
    // name == netsh interface ip show interfaces
    QNetworkInterface interface = QNetworkInterface::interfaceFromIndex(index);
    if (interface.isValid())
        name = interface.humanReadableName();
    return name;
}

/*!
 * \brief NetConfig::getInterfaceSystemName
 * \param index
 * \return Friendly name of the interface to search for
 */
QString NetConfig::getInterfaceSystemName(int index){
    QString name;
    // name == netsh interface ip show interfaces
    QNetworkInterface interface = QNetworkInterface::interfaceFromIndex(index);
    if (interface.isValid())
        name = interface.name();
    return name;
}

/*!
 * \brief NetConfig::getMacAddress
 * \param index
 * \return Friendly name of the interface to search for
 */
QString NetConfig::getMacAddress(int index){
    QString macaddr;
    QNetworkInterface interface = QNetworkInterface::interfaceFromIndex(index);
    if (interface.isValid())
        macaddr = interface.hardwareAddress();
    return macaddr;
}

/*!
 * \brief NetConfig::getInterfaceIp
 * \param id
 * \return
 */
QString NetConfig::getInterfaceIp(int index){
    QString addr;
    // ip == netsh interface ip show ipaddresses

    QNetworkAddressEntry entry;
    if (getInterfaceAddress(index, &entry))
        addr = entry.ip().toString();

    return addr;
}

/*!
 * \brief NetConfig::getInterfaceRawIp
 * \param id
 * \return
 */
quint32 NetConfig::getInterfaceRawIp(int index){
    quint32 addr = 0;
    // ip == netsh interface ip show ipaddresses

    QNetworkAddressEntry entry;
    if (getInterfaceAddress(index, &entry))
        addr = entry.ip().toIPv4Address();

    return addr;
}



/*!
 * \brief NetConfig::getInterfaceNetmask
 * \param index
 * \return
 */
QString NetConfig::getInterfaceNetmask(int index){
    QString netmask;    
    // ip == netsh interface ip show address

    QNetworkAddressEntry entry;
    if (getInterfaceAddress(index, &entry))
        netmask = entry.netmask().toString();

    return netmask;
}

bool NetConfig::getInterfaceAddress(int &index, QNetworkAddressEntry *entry){
    int i;
    bool found = false;
    QNetworkInterface interface = QNetworkInterface::interfaceFromIndex(index);
    if (entry &&
        interface.isValid()){
        QList<QNetworkAddressEntry> addressEntryList = interface.addressEntries();
        for (i=0;i<addressEntryList.size() && !found; i++){
            if (QAbstractSocket::IPv4Protocol == addressEntryList[i].ip().protocol()){
                *entry = addressEntryList.at(i);
                found = true;
            }
        }
    }
    return found;
}

bool NetConfig::isInSubnet(int index, QString ip, QString netmask){
    bool isinsubnet;
    QNetworkAddressEntry entry;
    if (getInterfaceAddress(index, &entry)){
        QHostAddress newip(ip);
        isinsubnet = newip.isInSubnet(entry.ip(), entry.prefixLength());
    }
    else {
        /* Assume that no info means same subnet */
        isinsubnet = true;
    }
    return isinsubnet;
}

/*!
 * \brief NetConfig::unitTest
 * \return true if success
 */
bool NetConfig::unitTest(){
    bool success;
    int i, index;
    QString tmpString;
    QList<QString> list = getInterfaceNameList();
    for (i=0;i<list.size();i++){
        index = getInterfaceId(list[i]);
        tmpString = getInterfaceFriendlyName(index);
        tmpString = getInterfaceSystemName(index);
        tmpString = getMacAddress(index);
        tmpString = getInterfaceIp(index);
        tmpString = getInterfaceNetmask(index);
    }

    index = getInterfaceId("Connexion au réseau local");
    return true;
}

/*!
 * \brief NetConfig::discoveryTest
 * \return
 */
bool NetConfig::discoveryTest(){

    QNetworkConfigurationManager netConfig;
    QList<QNetworkConfiguration> configList = netConfig.allConfigurations();
    QList<QNetworkInterface> interfaceList = QNetworkInterface::allInterfaces();

    bool active;
    int i,j, index, bearer;
    QString name;
    QString macAddr;
    QHostAddress addr;
    QList<QNetworkAddressEntry>  addressEntryList;

    for (i=0;i<configList.size(); i++){
        name = configList[i].name(); // Physical connections and visible WiFi AP
        bearer = configList[i].bearerType(); // 1 eth, 2 WiFi
    }

    for (i=0;i<interfaceList.size(); i++){
        active = interfaceList[i].isValid(); // true for active
        index = interfaceList[i].index();
        active = interfaceList[i].flags(); // 1 = isUp
        name = interfaceList[i].humanReadableName(); // "Connexion au réseau local 7"
        name = interfaceList[i].name();             // {18BF9FD8-A5A3-40F7-897C-C2775BA34A27}
        macAddr = interfaceList[i].hardwareAddress(); // 00:1F:B5:21:D2:FB
        addressEntryList = interfaceList[i].addressEntries();
        for (j=0;j<addressEntryList.size();j++){
            if (QAbstractSocket::IPv4Protocol == addressEntryList[j].ip().protocol())
                name = addressEntryList[j].ip().toString();
            addr = addressEntryList[j].ip();
            addr = addressEntryList[j].netmask();
        }
    }
    return true;
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
