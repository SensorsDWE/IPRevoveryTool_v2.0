#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T17:34:07
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 0867_Schneider_IpRetrieval
TEMPLATE = app
INCLUDEPATH += .

SOURCES +=  \
    ../../src/src/main.cpp \
    ../../src/src/mainwindow.cpp \
    ../../src/src/sensor.cpp \
    ../../src/src/controller.cpp \
    ../../src/src/logger.cpp \
    ../../../Common/NetworkDiagnostic/src/netconfig.cpp \
    ../../../Common/NetworkDiagnostic/src/netsh.cpp \
    ../../../Common/NetworkDiagnostic/src/windump.cpp \
    ../../../Common/Modbus/src/modbustcp.cpp \
    ../../../Common/Tcp/src/tcpclient.cpp \
    ../../../Common/Tcp/src/tcpserver.cpp \
    ../../src/src/LogBrowser/logbrowser.cpp \
    ../../src/src/LogBrowser/logbrowserdialog.cpp \
    ../../src/src/aboutdialog.cpp

HEADERS  +=  \
    ../../src/src/mainwindow.h \
    ../../src/src/sensor.h \
    ../../src/src/controller.h \
    ../../src/src/logger.h \
    ../../../Common/NetworkDiagnostic/src/netconfig.h \
    ../../../Common/NetworkDiagnostic/src/netsh.h \
    ../../../Common/NetworkDiagnostic/src/windump.h \
    ../../../Common/Modbus/src/modbustcp.h \
    ../../../Common/Tcp/src/tcpclient.h \
    ../../../Common/Tcp/src/tcpserver.h \
    ../../src/src/messagewindow.h \
    ../../src/src/LogBrowser/logbrowser.h \
    ../../src/src/LogBrowser/logbrowserdialog.h \
    ../../src/src/aboutdialog.h

FORMS    +=  \
    ../../src/src/mainwindow.ui \
    ../../src/src/sensor.ui \
    ../../../Common/Tcp/src/tcpclient.ui \
    ../../../Common/Tcp/src/tcpserver.ui \
    ../../src/src/aboutdialog.ui

OTHER_FILES +=  \
    ../../src/config/config.xml

RESOURCES += \
    ../../src/images/Images.qrc \
    ../../src/licences/Licences.qrc

TRANSLATIONS = ../../src/translations/fr.ts \
               ../../src/translations/en.ts

RC_FILE += \
    ../../src/images/WinSpecific.rc
