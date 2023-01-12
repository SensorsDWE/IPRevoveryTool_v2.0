/*!
 * \file modbustcp.cpp
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
#include "modbustcp.h"
#include <QtEndian>

//--------------------------------------
// Creator/destructor
//--------------------------------------

Modbustcp::Modbustcp(QObject *parent) :
    QObject(parent)
{
    remote = new Tcpclient(false);

    /* Link error messages when possible */
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            parent, SLOT(messageFromLowerLayer(int, QString)));
}

Modbustcp::~Modbustcp(){
    delete remote;
}


//----------------------------------
// Public methods
//----------------------------------
bool Modbustcp::open(QString ipaddr, quint8 protocol, quint8 unit){
    return open(ipaddr, protocol, unit, 0);
}

bool Modbustcp::open(QString ipaddr, quint8 protocol, quint8 unit, int timeoutms){
    transId = 0;
    protId = protocol;
    unitId = unit;
    bool success = remote->open(ipaddr,MODBUSTCP_PORT,timeoutms);
    qDebug() << "[MODBUSTCP] Open (" << timeoutms << ") " << ipaddr << " : " << success;
    return success;
}

void Modbustcp::close(){
    qDebug() << "[MODBUSTCP] Close";
    return remote->close();
}

/*!
 * \brief Modbustcp::readRegisters
 * \param start Starting address
 * \param nb Quantity of registers
 * \param result Bytes read when success (BigEndian format)
 * \return true if success
 * \warning Blocking function
 */
bool Modbustcp::readRegisters(quint16 start, quint16 nb, QByteArray *result){
    /* Code 0x03 Read Holding Registers
     * Format of data is:
     * | StartAddress | NbRegisters |
     * |  2Bytes      |  2Bytes     |
     * Warning : the different fields are encoded in Big-endian.
     */
    QByteArray packet;

    /* byte.size() must match size of item to convert
     * otherwise ToBigEndian(quint16) returns empty */
    QByteArray byte(2,0);
    qToBigEndian(start, (uchar *)byte.data());
    packet.append(byte);
    qToBigEndian(nb, (uchar *)byte.data());
    packet.append(byte);

    bool success = sendModbusRequest(0x03, packet);
    if (success){
        quint8 cmd = 0;
        success = receiveModbusResponse(&cmd, result);
        if (success && cmd < 0x80)
            qDebug() << "[MODBUSTCP] Read OK";
        else{
            success = false;
            qDebug() << "[MODBUSTCP] Read: " << success << " Error: " << cmd;
            emit sigMessageToUpperLayer(0,tr("ModBus Error occurred "));
        }
    }

    return success;
}

/*!
 * \brief Modbustcp::writeRegisters
 * \param start Starting address
 * \param nb Quantity of registers
 * \param data Bytes to write (BigEndian format)
 * \return true if success
 */
bool Modbustcp::writeRegisters(quint16 start, quint16 nb, QByteArray data){
    /* Code 0x10 Write Multiple registers
     * Format of data is:
     * | StartAddress | NbRegisters | ByteCount | Values |
     * |  2Bytes      |  2Bytes     |  1Bytes   | XBytes |
     * Warning : the different fields are encoded in Big-endian.
     */
    QByteArray packet;

    /* byte.size() must match size of item to convert
     * otherwise ToBigEndian(quint16) returns empty */
    QByteArray byte(2,0);
    qToBigEndian(start, (uchar *)byte.data());
    packet.append(byte);
    qToBigEndian(nb, (uchar *)byte.data());
    packet.append(byte);
    byte.resize(1);
    qToBigEndian((quint8)(data.size()), (uchar *)byte.data());
    packet.append(byte);
    packet.append(data);

    bool success = sendModbusRequest(0x10, packet);
    if (success){
        quint8 cmd;
        QByteArray result;
        success = receiveModbusResponse(&cmd, &result);
        if (success && cmd < 0x80)
            qDebug() << "[MODBUSTCP] Read OK";
        else{
            success = false;
            qDebug() << "[MODBUSTCP] Read: " << success << " Error: " << cmd;
            emit sigMessageToUpperLayer(0,tr("ModBus Error occurred "));
        }
    }

    return success;
}

bool Modbustcp::unitTest(){
    bool success = false;

    //QString ipaddr("192.168.10.83");
    QString ipaddr("192.168.0.10");
    quint8 protocol = 0x00;
    quint8 unit = 0xff;
    success = this->open(ipaddr, protocol, unit);

    QByteArray result;
    success = this->readRegisters(0xFA10, 6, &result);

    if (success){
        QByteArray data;
        QByteArray byte(2,0);
        qToBigEndian((qint16)(0xc0A8), (uchar *)byte.data());
        data.append(byte);
        qToBigEndian((qint16)(0x0007), (uchar *)byte.data());
        data.append(byte);
        success = this->writeRegisters(0xFA14, 2, data);
    }

    this->close();

    return success;
}

//----------------------------------
// Private methods
//----------------------------------
bool Modbustcp::sendModbusRequest(quint8 cmd, QByteArray data){
    /* Format of packet is:
     * | TransId | Protocol | Length | UnitId | Function | Data   |
     * |  2Bytes |  2Bytes  | 2Bytes |  1Byte |  1Byte   | XBytes |
     * Note: The length field is a byte count of the following fields (UnitId + Function + Data)
     * Warning : the different fields are encoded in Big-endian.
     */
    QByteArray packet;
    qint16 len = data.size() + 2;


    /* byte.size() must match size of item to convert
     * otherwise ToBigEndian(quint16) returns empty */
    QByteArray byte(2,0);
    qToBigEndian(transId, (uchar *)byte.data());
    packet.append(byte);
    qToBigEndian(protId, (uchar *)byte.data());
    packet.append(byte);
    qToBigEndian(len, (uchar *)byte.data());
    packet.append(byte);
    byte.resize(1);
    qToBigEndian(unitId, (uchar *)byte.data());
    packet.append(byte);
    qToBigEndian(cmd, (uchar *)byte.data());
    packet.append(byte);
    packet.append(data);

    bool success = false;
    len = packet.size();
    qint64 bytes = remote->send(packet);
    while (bytes != -1 &&
           !success){
        len -= bytes;

        if (len <= 0)
            success = true;
        else
            bytes = remote->send(packet.right(packet.size()-len));

    };

    transId++;
    return success;
}

bool Modbustcp::receiveModbusResponse(quint8 *cmd, QByteArray *result){
    /* Format of response is:
     * | TransId | Protocol | Length | UnitId | Function | Data   |
     * |  2Bytes |  2Bytes  | 2Bytes |  1Byte |  1Byte   | XBytes |
     * Format of error is
     * | TransId | Protocol | Length | UnitId | ErrorCode (0x80+Function) | Exception |
     * |  2Bytes |  2Bytes  | 2Bytes |  1Byte |  1Byte                    |  1Byte    |
     * Warning : the different fields are encoded in Big-endian.
     */

    bool success = false;
    char data[MODBUSTCP_RSP_MAXSIZE];
    qint64 bytes = remote->read(data, sizeof(data), 5000);
    if (bytes != -1 &&
        bytes > MODBUSTCP_MBAPHEADER_SIZE+1 ){

        *cmd = qFromBigEndian((uchar)(data[MODBUSTCP_MBAPHEADER_SIZE]));
        result->append(&data[MODBUSTCP_MBAPHEADER_SIZE+1],bytes-(MODBUSTCP_MBAPHEADER_SIZE + 1));
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
