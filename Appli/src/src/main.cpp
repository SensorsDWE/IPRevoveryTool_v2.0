/*!
 * \file main.cpp
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
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDir>

#include "logger.h"
#include "sensor.h"
#include "controller.h"


//#define TEST_MODE
//#define DEBUG_MAINWINDOW

#ifdef TEST_MODE
#include "../../../Common/NetworkDiagnostic/src/netsh.h"
#include "../../../Common/NetworkDiagnostic/src/netconfig.h"
#include "../../../Common/NetworkDiagnostic/src/windump.h"
#include "../../../Common/Tcp/src/tcpclient.h"
#include "../../../Common/Modbus/src/modbustcp.h"
#endif


#ifdef DEBUG_MAINWINDOW
#include "LogBrowser/logbrowser.h"
#include <QPointer>

QPointer<LogBrowser> logBrowser;
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logBrowser)
        logBrowser->outputMessage( type, msg );
}
#endif


void test(){
    // Unitary tests
    //Logger t1;
    //t1.unitTest();
    //NetConfig t3;
    //t3.unitTest();
    //Netsh t2;
    //t2.unitTest();
    //Windump t4;
    /* Start Sniffer thread */
    //t4.unitTest();
    //Sensor t5("00:11:22:33:44:55");
    //t5.unitTest();
    Controller t6;
    //t6.start(QThread::InheritPriority);
    t6.unitTest();
    //controller->unitTest();
    //Tcpclient *t7 = new Tcpclient(true);
    //QObject::connect(t7, SIGNAL(sigMessageToUpperLayer(int, QString)),
    //                mainWindow, SLOT(messageFromLowerLayer(int, QString)));
    //t7->show();
    //Modbustcp t8;
    //t8.unitTest();
}

int main(int argc, char *argv[])
{
    // QApplication object must be created before any window-system parts of Qt are used.
    QApplication app(argc, argv);
    QString locale = QLocale::system().name();

#ifdef DEBUG_MAINWINDOW
    /* Install the browser asap, otherwise init messages are lost */
    logBrowser = new LogBrowser;
    qInstallMessageHandler(myMessageOutput);
#endif

    // Load translations
    QTranslator translator;
    translator.load(locale,QDir::currentPath() + "/translations");
    app.installTranslator(&translator);

#ifdef TEST_MODE
    test();
#endif

    // MVC architecture
    // Controller: Event handler
    Controller* controller = new Controller();
    controller->start(QThread::InheritPriority);

    // Model : What app does? - Handled by controller

    // View: Show app to user
    MainWindow* mainWindow = new MainWindow(controller);
    QIcon icon(":icons/Icon.ico");
    mainWindow->setWindowIcon(icon);
    mainWindow->show();

    // This is where main() passes control to Qt
    return app.exec();
}
