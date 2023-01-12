/********************************************************************************
** Form generated from reading UI file 'sensor.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSOR_H
#define UI_SENSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sensor
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_ipparameters;
    QGridLayout *gridLayout;
    QLabel *label_mask;
    QLabel *label_ip;
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_mask;
    QLineEdit *lineEdit_gw;
    QLabel *label_gw;
    QCheckBox *checkBox;
    QCheckBox *checkBox_autoconfig;
    QPushButton *pushButton_Done;
    QPushButton *pushButton_apply;
    QPushButton *pushButton_Undo;

    void setupUi(QWidget *Sensor)
    {
        if (Sensor->objectName().isEmpty())
            Sensor->setObjectName(QStringLiteral("Sensor"));
        Sensor->resize(298, 198);
        Sensor->setAutoFillBackground(false);
        Sensor->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(Sensor);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_ipparameters = new QGroupBox(Sensor);
        groupBox_ipparameters->setObjectName(QStringLiteral("groupBox_ipparameters"));
        gridLayout = new QGridLayout(groupBox_ipparameters);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_mask = new QLabel(groupBox_ipparameters);
        label_mask->setObjectName(QStringLiteral("label_mask"));

        gridLayout->addWidget(label_mask, 1, 0, 1, 1);

        label_ip = new QLabel(groupBox_ipparameters);
        label_ip->setObjectName(QStringLiteral("label_ip"));

        gridLayout->addWidget(label_ip, 0, 0, 1, 1);

        lineEdit_ip = new QLineEdit(groupBox_ipparameters);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        gridLayout->addWidget(lineEdit_ip, 0, 1, 1, 1);

        lineEdit_mask = new QLineEdit(groupBox_ipparameters);
        lineEdit_mask->setObjectName(QStringLiteral("lineEdit_mask"));

        gridLayout->addWidget(lineEdit_mask, 1, 1, 1, 1);

        lineEdit_gw = new QLineEdit(groupBox_ipparameters);
        lineEdit_gw->setObjectName(QStringLiteral("lineEdit_gw"));

        gridLayout->addWidget(lineEdit_gw, 2, 1, 1, 1);

        label_gw = new QLabel(groupBox_ipparameters);
        label_gw->setObjectName(QStringLiteral("label_gw"));

        gridLayout->addWidget(label_gw, 2, 0, 1, 1);

        checkBox = new QCheckBox(groupBox_ipparameters);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        gridLayout->addWidget(checkBox, 3, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_ipparameters, 0, 0, 1, 3);

        checkBox_autoconfig = new QCheckBox(Sensor);
        checkBox_autoconfig->setObjectName(QStringLiteral("checkBox_autoconfig"));
        checkBox_autoconfig->setChecked(true);

        gridLayout_2->addWidget(checkBox_autoconfig, 2, 0, 1, 3);

        pushButton_Done = new QPushButton(Sensor);
        pushButton_Done->setObjectName(QStringLiteral("pushButton_Done"));

        gridLayout_2->addWidget(pushButton_Done, 3, 2, 1, 1);

        pushButton_apply = new QPushButton(Sensor);
        pushButton_apply->setObjectName(QStringLiteral("pushButton_apply"));

        gridLayout_2->addWidget(pushButton_apply, 3, 0, 1, 1);

        pushButton_Undo = new QPushButton(Sensor);
        pushButton_Undo->setObjectName(QStringLiteral("pushButton_Undo"));

        gridLayout_2->addWidget(pushButton_Undo, 3, 1, 1, 1);


        retranslateUi(Sensor);

        QMetaObject::connectSlotsByName(Sensor);
    } // setupUi

    void retranslateUi(QWidget *Sensor)
    {
        Sensor->setWindowTitle(QApplication::translate("Sensor", "Form", 0));
        groupBox_ipparameters->setTitle(QApplication::translate("Sensor", "IP parameters", 0));
        label_mask->setText(QApplication::translate("Sensor", "Subnet mask:", 0));
        label_ip->setText(QApplication::translate("Sensor", "IP address:", 0));
        lineEdit_ip->setText(QApplication::translate("Sensor", "192.168.0.10", 0));
        lineEdit_mask->setText(QApplication::translate("Sensor", "255.255.255.0", 0));
        lineEdit_gw->setText(QApplication::translate("Sensor", "192.168.0.2", 0));
        label_gw->setText(QApplication::translate("Sensor", "Gateway", 0));
        checkBox->setText(QApplication::translate("Sensor", "Factory settings", 0));
        checkBox_autoconfig->setText(QApplication::translate("Sensor", "Configure local address automatically (recommended)", 0));
        pushButton_Done->setText(QApplication::translate("Sensor", "Done", 0));
        pushButton_apply->setText(QApplication::translate("Sensor", "Apply", 0));
        pushButton_Undo->setText(QApplication::translate("Sensor", "Undo", 0));
    } // retranslateUi

};

namespace Ui {
    class Sensor: public Ui_Sensor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSOR_H
