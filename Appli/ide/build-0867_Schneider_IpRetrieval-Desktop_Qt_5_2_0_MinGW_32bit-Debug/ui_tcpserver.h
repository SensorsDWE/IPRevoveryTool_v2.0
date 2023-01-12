/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcpserver
{
public:

    void setupUi(QWidget *Tcpserver)
    {
        if (Tcpserver->objectName().isEmpty())
            Tcpserver->setObjectName(QStringLiteral("Tcpserver"));
        Tcpserver->resize(400, 300);

        retranslateUi(Tcpserver);

        QMetaObject::connectSlotsByName(Tcpserver);
    } // setupUi

    void retranslateUi(QWidget *Tcpserver)
    {
        Tcpserver->setWindowTitle(QApplication::translate("Tcpserver", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Tcpserver: public Ui_Tcpserver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
