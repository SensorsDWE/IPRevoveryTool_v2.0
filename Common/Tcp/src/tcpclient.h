/*!
 * \file tcpclient.h
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
#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>

namespace Ui {
class Tcpclient;
}

class Tcpclient : public QWidget
{
    Q_OBJECT

public:
    explicit Tcpclient(bool interactive = false, QThread *parentThread = 0, QWidget *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Tcpclient();

    bool open(QString ip, int port);
    bool open(QString ip, int port, int timeoutms);
    bool isConnected();
    qint64 send(QByteArray data);
    qint64 read(char *data, qint64 size, int timeoutms);
    void close();
    bool unitTest();

signals:
    void sigMessageToUpperLayer(int level, QString error);


private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_receive_clicked();
    void on_pushButton_connect_clicked();
    void on_pushButton_disconnect_clicked();

private:
    Ui::Tcpclient *ui;
    QTcpSocket socket;
    QHostAddress host;
};

#endif // TCPCLIENT_H
