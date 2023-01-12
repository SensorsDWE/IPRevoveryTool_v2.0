/*!
 * \file tcpserver.cpp
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
#include "tcpserver.h"
#include "ui_tcpserver.h"

//--------------------------------------
// Creator/destructor
//--------------------------------------

Tcpserver::Tcpserver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tcpserver)
{
    ui->setupUi(this);
}

Tcpserver::~Tcpserver()
{
    delete ui;
}


//----------------------------------
// Public methods
//----------------------------------

//----------------------------------
// Private methods
//----------------------------------

//----------------------------------
// Signals
//----------------------------------

//----------------------------------
// Public Slots
//----------------------------------
