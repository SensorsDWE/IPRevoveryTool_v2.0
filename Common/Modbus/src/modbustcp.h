/*!
 * \file modbustcp.h
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
#ifndef MODBUSTCP_H
#define MODBUSTCP_H

#include <QObject>
#include "../../Tcp/src/tcpclient.h"

/** All MODBUS/TCP ADU are sent via TCP to registered port 502 */
#define MODBUSTCP_PORT 502

/** MBAP Header size (TransId | Protocol | Length | UnitId) */
#define MODBUSTCP_MBAPHEADER_SIZE 7

/** TCP MODBUS ADU = 253 bytes + MBAP (7 bytes) = 260 bytes. */
#define MODBUSTCP_RSP_MAXSIZE 260

class Modbustcp : public QObject
{
    Q_OBJECT
public:
    explicit Modbustcp(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Modbustcp();

signals:
    void sigMessageToUpperLayer(int level, QString error);

public slots:

public:
    bool open(QString ipaddr, quint8 protocol, quint8 unit);
    bool open(QString ipaddr, quint8 protocol, quint8 unit, int timeoutms);
    void close();
    bool readRegisters(quint16 start, quint16 nb, QByteArray *result);
    bool writeRegisters(quint16 start, quint16 nb, QByteArray data);
    bool unitTest();

private:
    Tcpclient *remote;  /* TCP connection to remote peer */
    quint16 transId;    /* Transaction ID - dynamic */
    quint16 protId;     /* Protocol ID - spec defined */
    quint8 unitId;      /* Unit ID - appl defined */

    bool sendModbusRequest(quint8 cmd, QByteArray data);
    bool receiveModbusResponse(quint8 *cmd, QByteArray *result);
};

#endif // MODBUSTCP_H
