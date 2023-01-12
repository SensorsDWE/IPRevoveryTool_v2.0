/*!
 * \file tcpserver.h
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
#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>

namespace Ui {
class Tcpserver;
}

class Tcpserver : public QWidget
{
    Q_OBJECT

public:
    explicit Tcpserver(QWidget *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Tcpserver();

private:
    Ui::Tcpserver *ui;
};

#endif // TCPSERVER_H
