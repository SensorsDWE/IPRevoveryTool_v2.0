/*!
 * \file tcpclient.cpp
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
#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QMessageBox>

//--------------------------------------
// Creator/destructor
//--------------------------------------

Tcpclient::Tcpclient(bool interactive, QThread *parentThread, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tcpclient)
{
    /* UI needs to stay in view thread, but not objects */
    if (parentThread){
        socket.moveToThread(parentThread);
    }

    /* Link error messages when possible */
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            parent, SLOT(messageFromLowerLayer(int, QString)));

    if (interactive)
        ui->setupUi(this);
}

Tcpclient::~Tcpclient()
{
    delete ui;
}


//----------------------------------
// Public methods
//----------------------------------
bool Tcpclient::open(QString ip, int port){
    return open(ip, port, 1000);
}

bool Tcpclient::open(QString ip, int port, int timeoutms){
    bool success = false;

    host.setAddress(ip);
    if (host.setAddress(ip)){
        socket.connectToHost(host,port);
        success = socket.waitForConnected(timeoutms);
    }

    qDebug() << "[TCPCLIENT] Connected to" << ip << ":" << port << success;
    if (!success){
        qDebug() << "[TCPCLIENT] Socket error" << socket.error();
        emit sigMessageToUpperLayer(0,tr("Cannot open TCP connection"));
    }
    return success;
}

bool Tcpclient::isConnected(){
    QAbstractSocket::SocketState state = socket.state();
    return (socket.isValid() && QAbstractSocket::ConnectedState == state);
}

qint64 Tcpclient::send(QByteArray data){
    qint64 sent = -1;

    if (socket.isValid()){
        sent = socket.write(data);
    }
    else{
        qDebug() << "[TCPCLIENT] Data send failed";
        emit sigMessageToUpperLayer(0,tr("Cannot send data over TCP connection"));
    }

    return sent;
}

qint64 Tcpclient::read(char *data, qint64 size, int timeoutms){
    qint64 read = -1;

    if (socket.isValid()){
        if (socket.bytesAvailable() > 0 ||
            socket.waitForReadyRead(timeoutms)){
            read = socket.read(data, size);
        }
    }
    else{
        qDebug() << "[TCPCLIENT] Data read failed";
        emit sigMessageToUpperLayer(0,tr("Cannot receive data over TCP connection"));
    }

    return read;
}

void Tcpclient::close(){
    qDebug() << "[TCPCLIENT] Connection closed";
    return socket.close();
}

bool Tcpclient::unitTest(){

    QString ip("192.168.10.20");
    int port = 1234;
    char data[128];
    qint64 bytes;
    bool success;

    success = this->open(ip, port); // expect true if peer ready
    bytes = send(QByteArray("Hello"));
    bytes = read(data, sizeof(data), 1000);
    this->close();

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

void Tcpclient::on_pushButton_send_clicked()
{
    QByteArray data;
    data.append(ui->textBrowser_tx->toPlainText());
    qint64 sent = this->send(data);
}

void Tcpclient::on_pushButton_receive_clicked()
{
    char data[128];
    qint64 read = this->read(data, sizeof(data), 1000);
    if (read>0){
        QByteArray dataArray(data,read);
        ui->textBrowser_rx->append(QString(dataArray));
    }
}

void Tcpclient::on_pushButton_connect_clicked()
{
    QString port = ui->lineEdit_port->text();
    this->open(ui->lineEdit_ip->text(), port.toInt());
}

void Tcpclient::on_pushButton_disconnect_clicked()
{
    this->close();
}
