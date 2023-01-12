/*!
 * \file netsh.h
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
#ifndef NETSH_H
#define NETSH_H

#include <QObject>
#include <QHostAddress>
#include <QNetworkAddressEntry>
#include <QFile>
#include <QHash>


class Netsh : public QObject
{
    Q_OBJECT
public:
    explicit Netsh(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    bool saveNetworkConfig(QFile *cfg);
    bool applyNetworkConfig(QFile *cfg);
    bool setInterface(QString name, QString ip, QString mask, QString gw, bool dhcp, QFile *restore);
    bool sendCmdOnShellUtf8(QString cmd, QByteArray *result);
    bool sendCmdOnShell(QString cmd, QByteArray *result);
    bool unitTest();
signals:

public slots:

private:
    bool win7;
};

#endif // NETSH_H
