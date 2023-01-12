/*!
 * \file netsh.h
 *
 * \brief
 *
 * \version 0.1
 * \date 2014/01/29
 * \author Ana Loizeau - ana.loizeau@eseo.fr
 *
 * \warning
 * \bug
 * \todo
 */
#ifndef NETCONFIG_H
#define NETCONFIG_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QNetworkInterface>

class NetConfig : public QObject
{
    Q_OBJECT
public:
    explicit NetConfig(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~NetConfig();
    QList<QString> getInterfaceNameList();
    int getInterfaceId(QString friendlyName);
    QString getInterfaceFriendlyName(int index);
    QString getInterfaceSystemName(int index);
    QString getMacAddress(int index);
    QString getInterfaceIp(int index);
    quint32 getInterfaceRawIp(int index);
    QString getInterfaceNetmask(int index);
    bool isInSubnet(int index, QString ip, QString netmask);
    bool discoveryTest();
    bool unitTest();

private:
    QList<QString> InterfaceNameList;
    bool getInterfaceAddress(int &index, QNetworkAddressEntry *entry);

};

#endif // NETCONFIG_H
