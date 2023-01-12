/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionLicenseQt;
    QAction *actionLoadSensor;
    QAction *actionExit;
    QAction *actionLicenseWinDump;
    QAction *actionLicenseWinPcap;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Logo;
    QLabel *label_Title;
    QFrame *frame_NetInterfaceSelector;
    QVBoxLayout *verticalLayout;
    QLabel *label_NetInterfaceSelector;
    QComboBox *comboBox_NetInterfaceSelector;
    QFrame *frame_Scan;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Clear;
    QPushButton *pushButton_Exit;
    QLabel *label_capturing;
    QPushButton *pushButton_StopScan;
    QPushButton *pushButton_ConfigDevice;
    QScrollArea *scrollArea_ScanResults;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_ScanResults;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Scan;
    QProgressBar *progressBar_capturing;
    QLabel *label_Copyright;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(503, 475);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(234, 234, 234);"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionLicenseQt = new QAction(MainWindow);
        actionLicenseQt->setObjectName(QStringLiteral("actionLicenseQt"));
        actionLoadSensor = new QAction(MainWindow);
        actionLoadSensor->setObjectName(QStringLiteral("actionLoadSensor"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionLicenseWinDump = new QAction(MainWindow);
        actionLicenseWinDump->setObjectName(QStringLiteral("actionLicenseWinDump"));
        actionLicenseWinPcap = new QAction(MainWindow);
        actionLicenseWinPcap->setObjectName(QStringLiteral("actionLicenseWinPcap"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_Logo = new QLabel(frame);
        label_Logo->setObjectName(QStringLiteral("label_Logo"));

        horizontalLayout_2->addWidget(label_Logo);

        label_Title = new QLabel(frame);
        label_Title->setObjectName(QStringLiteral("label_Title"));
        label_Title->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_Title->setScaledContents(false);

        horizontalLayout_2->addWidget(label_Title);


        gridLayout_2->addWidget(frame, 0, 0, 1, 1);

        frame_NetInterfaceSelector = new QFrame(centralWidget);
        frame_NetInterfaceSelector->setObjectName(QStringLiteral("frame_NetInterfaceSelector"));
        frame_NetInterfaceSelector->setFrameShape(QFrame::Box);
        frame_NetInterfaceSelector->setFrameShadow(QFrame::Raised);
        frame_NetInterfaceSelector->setLineWidth(1);
        frame_NetInterfaceSelector->setMidLineWidth(0);
        verticalLayout = new QVBoxLayout(frame_NetInterfaceSelector);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_NetInterfaceSelector = new QLabel(frame_NetInterfaceSelector);
        label_NetInterfaceSelector->setObjectName(QStringLiteral("label_NetInterfaceSelector"));

        verticalLayout->addWidget(label_NetInterfaceSelector);

        comboBox_NetInterfaceSelector = new QComboBox(frame_NetInterfaceSelector);
        comboBox_NetInterfaceSelector->setObjectName(QStringLiteral("comboBox_NetInterfaceSelector"));
        comboBox_NetInterfaceSelector->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(comboBox_NetInterfaceSelector);


        gridLayout_2->addWidget(frame_NetInterfaceSelector, 1, 0, 1, 1);

        frame_Scan = new QFrame(centralWidget);
        frame_Scan->setObjectName(QStringLiteral("frame_Scan"));
        frame_Scan->setFrameShape(QFrame::StyledPanel);
        frame_Scan->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_Scan);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(333, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 1, 1, 5);

        pushButton_Clear = new QPushButton(frame_Scan);
        pushButton_Clear->setObjectName(QStringLiteral("pushButton_Clear"));

        gridLayout->addWidget(pushButton_Clear, 0, 3, 1, 1);

        pushButton_Exit = new QPushButton(frame_Scan);
        pushButton_Exit->setObjectName(QStringLiteral("pushButton_Exit"));

        gridLayout->addWidget(pushButton_Exit, 3, 6, 1, 1);

        label_capturing = new QLabel(frame_Scan);
        label_capturing->setObjectName(QStringLiteral("label_capturing"));
        label_capturing->setFrameShape(QFrame::NoFrame);
        label_capturing->setLineWidth(2);

        gridLayout->addWidget(label_capturing, 3, 0, 1, 1);

        pushButton_StopScan = new QPushButton(frame_Scan);
        pushButton_StopScan->setObjectName(QStringLiteral("pushButton_StopScan"));

        gridLayout->addWidget(pushButton_StopScan, 0, 2, 1, 1);

        pushButton_ConfigDevice = new QPushButton(frame_Scan);
        pushButton_ConfigDevice->setObjectName(QStringLiteral("pushButton_ConfigDevice"));

        gridLayout->addWidget(pushButton_ConfigDevice, 0, 5, 1, 2);

        scrollArea_ScanResults = new QScrollArea(frame_Scan);
        scrollArea_ScanResults->setObjectName(QStringLiteral("scrollArea_ScanResults"));
        scrollArea_ScanResults->setAutoFillBackground(false);
        scrollArea_ScanResults->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        scrollArea_ScanResults->setWidgetResizable(true);
        scrollArea_ScanResults->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 463, 135));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_ScanResults = new QListWidget(scrollAreaWidgetContents);
        listWidget_ScanResults->setObjectName(QStringLiteral("listWidget_ScanResults"));

        horizontalLayout->addWidget(listWidget_ScanResults);

        scrollArea_ScanResults->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea_ScanResults, 1, 0, 1, 7);

        horizontalSpacer = new QSpacerItem(59, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        pushButton_Scan = new QPushButton(frame_Scan);
        pushButton_Scan->setObjectName(QStringLiteral("pushButton_Scan"));

        gridLayout->addWidget(pushButton_Scan, 0, 0, 1, 2);

        progressBar_capturing = new QProgressBar(frame_Scan);
        progressBar_capturing->setObjectName(QStringLiteral("progressBar_capturing"));
        progressBar_capturing->setStyleSheet(QStringLiteral("QProgressBar::chunk {background-color: #0a79c9;}"));
        progressBar_capturing->setMaximum(10);
        progressBar_capturing->setValue(0);
        progressBar_capturing->setTextVisible(false);

        gridLayout->addWidget(progressBar_capturing, 2, 0, 1, 7);


        gridLayout_2->addWidget(frame_Scan, 2, 0, 1, 1);

        label_Copyright = new QLabel(centralWidget);
        label_Copyright->setObjectName(QStringLiteral("label_Copyright"));
        label_Copyright->setLineWidth(1);

        gridLayout_2->addWidget(label_Copyright, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 503, 21));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionAbout);
        menuHelp->addSeparator();
        menuHelp->addAction(actionLicenseQt);
        menuHelp->addAction(actionLicenseWinDump);
        menuHelp->addAction(actionLicenseWinPcap);
        menuFile->addAction(actionLoadSensor);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionLicenseQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        actionLoadSensor->setText(QApplication::translate("MainWindow", "Load Device", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionLicenseWinDump->setText(QApplication::translate("MainWindow", "About WinDump", 0));
        actionLicenseWinPcap->setText(QApplication::translate("MainWindow", "About WinPcap", 0));
        label_Logo->setText(QApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/Images/Logo_TESensors_4cm.jpg\"/></p></body></html>", 0));
        label_Title->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-family:'arial,sans-serif'; font-size:18pt; font-weight:600; color:#0a79c9;\">IP Recovery Tool </span></p></body></html>", 0));
        label_NetInterfaceSelector->setText(QApplication::translate("MainWindow", "Please select a network interface", 0));
        pushButton_Clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        pushButton_Exit->setText(QApplication::translate("MainWindow", "EXIT", 0));
        label_capturing->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:bold;\">Stopped</span></p></body></html>", 0));
        pushButton_StopScan->setText(QApplication::translate("MainWindow", "STOP SCAN", 0));
        pushButton_ConfigDevice->setText(QApplication::translate("MainWindow", "CONFIGURE DEVICE", 0));
        pushButton_Scan->setText(QApplication::translate("MainWindow", "SCAN", 0));
        label_Copyright->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Copyright (c) 2020, Schneider Electric. All Rights Reserved</p></body></html>", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
