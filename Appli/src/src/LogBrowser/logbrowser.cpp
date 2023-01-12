#include "logbrowser.h"
 
#include <QMetaType>
 
#include "logbrowserdialog.h"
 
LogBrowser::LogBrowser(QObject *parent) :
    QObject(parent)
{
    qRegisterMetaType<QtMsgType>("QtMsgType");
    browserDialog = new LogBrowserDialog();
    connect(this, SIGNAL(sendMessage(QtMsgType,QString)), browserDialog, SLOT(outputMessage(QtMsgType,QString)), Qt::QueuedConnection);
    browserDialog->setWindowTitle(tr("Log browser", "Log Browser window title"));
    browserDialog->show();
}
 
 
LogBrowser::~LogBrowser()
{
    delete browserDialog;
}
 
 
void LogBrowser::outputMessage(QtMsgType type, const QString &msg)
{
    emit sendMessage( type, msg );
}
