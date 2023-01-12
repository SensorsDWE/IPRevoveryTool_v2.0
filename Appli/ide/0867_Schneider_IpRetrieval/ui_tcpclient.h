/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tcpclient
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QLabel *label_port;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QTextBrowser *textBrowser_rx;
    QTextBrowser *textBrowser_tx;
    QPushButton *pushButton_send;

    void setupUi(QWidget *Tcpclient)
    {
        if (Tcpclient->objectName().isEmpty())
            Tcpclient->setObjectName(QStringLiteral("Tcpclient"));
        Tcpclient->resize(354, 288);
        gridLayout = new QGridLayout(Tcpclient);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(Tcpclient);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_ip = new QLabel(Tcpclient);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_ip);

        lineEdit_ip = new QLineEdit(Tcpclient);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_ip);

        label_port = new QLabel(Tcpclient);
        label_port->setObjectName(QStringLiteral("label_port"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_port);

        lineEdit_port = new QLineEdit(Tcpclient);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_port);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_connect = new QPushButton(Tcpclient);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);

        pushButton_disconnect = new QPushButton(Tcpclient);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));

        horizontalLayout->addWidget(pushButton_disconnect);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        textBrowser_rx = new QTextBrowser(Tcpclient);
        textBrowser_rx->setObjectName(QStringLiteral("textBrowser_rx"));

        gridLayout->addWidget(textBrowser_rx, 3, 0, 1, 2);

        textBrowser_tx = new QTextBrowser(Tcpclient);
        textBrowser_tx->setObjectName(QStringLiteral("textBrowser_tx"));

        gridLayout->addWidget(textBrowser_tx, 4, 0, 1, 1);

        pushButton_send = new QPushButton(Tcpclient);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        gridLayout->addWidget(pushButton_send, 4, 1, 1, 1);


        retranslateUi(Tcpclient);

        QMetaObject::connectSlotsByName(Tcpclient);
    } // setupUi

    void retranslateUi(QWidget *Tcpclient)
    {
        Tcpclient->setWindowTitle(QApplication::translate("Tcpclient", "Form", 0));
        label->setText(QApplication::translate("Tcpclient", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">TCP client</span></p></body></html>", 0));
        label_ip->setText(QApplication::translate("Tcpclient", "Remote IP", 0));
        lineEdit_ip->setText(QApplication::translate("Tcpclient", "192.168.0.1", 0));
        label_port->setText(QApplication::translate("Tcpclient", "Remote Port", 0));
        lineEdit_port->setText(QApplication::translate("Tcpclient", "1234", 0));
        pushButton_connect->setText(QApplication::translate("Tcpclient", "Connect", 0));
        pushButton_disconnect->setText(QApplication::translate("Tcpclient", "Disconnect", 0));
        pushButton_send->setText(QApplication::translate("Tcpclient", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class Tcpclient: public Ui_Tcpclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
