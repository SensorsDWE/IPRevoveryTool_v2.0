#include "logbrowserdialog.h"
 
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QPushButton>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QCloseEvent>
#include <QKeyEvent>
 
LogBrowserDialog::LogBrowserDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);
 
    browser = new QTextBrowser(this);
    layout->addWidget(browser);
 
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setContentsMargins(0, 0, 0, 0);
    layout->addLayout(buttonLayout);
 
    buttonLayout->addStretch(10);
 
    clearButton = new QPushButton(this);
    clearButton->setText("clear");
    buttonLayout->addWidget(clearButton);
    connect(clearButton, SIGNAL(clicked()), browser, SLOT(clear()));
 
    saveButton = new QPushButton(this);
    saveButton->setText("save output");
    buttonLayout->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
 
    resize(200, 400);
}
 
 
LogBrowserDialog::~LogBrowserDialog()
{
 
}
 
 
void LogBrowserDialog::outputMessage(QtMsgType type, const QString &msg)
{
    switch (type) {
    case QtDebugMsg:
        browser->append(msg);
        break;
 
    case QtWarningMsg:
        browser->append(tr("-- WARNING: %1").arg(msg));
        break;
 
    case QtCriticalMsg:
        browser->append(tr("-- CRITICAL: %1").arg(msg));
        break;
 
    case QtFatalMsg:
        browser->append(tr("-- FATAL: %1").arg(msg));
        break;
    }
}
 
 
void LogBrowserDialog::save()
{
    QString saveFileName = QFileDialog::getSaveFileName(
                this,
                tr("Save Log Output"),
                tr("%1/logfile.txt").arg(QDir::homePath()),
                tr("Text Files (*.txt);;All Files (*)")
                );
 
    if(saveFileName.isEmpty())
        return;
 
    QFile file(saveFileName);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(
                    this,
                    tr("Error"),
                    QString(tr("<nobr>File '%1'<br/>cannot be opened for writing.<br/><br/>"
                               "The log output could <b>not</b> be saved!</nobr>"))
                    .arg(saveFileName));
        return;
    }
 
    QTextStream stream(&file);
    stream << browser->toPlainText();
    file.close();
}
 
 
void LogBrowserDialog::closeEvent(QCloseEvent *e)
{
    e->accept();
#if 0
    QMessageBox::StandardButton answer = QMessageBox::question(
                this,
                tr("Close Log Browser?"),
                tr("Do you really want to close the log browser?"),
                QMessageBox::Yes | QMessageBox::No
                );
 
    if (answer == QMessageBox::Yes)
        e->accept();
    else
        e->ignore();
#endif
}
 
 
void LogBrowserDialog::keyPressEvent(QKeyEvent *e)
{
    // ignore all keyboard events
    // protects against accidentally closing of the dialog
    // without asking the user
    e->ignore();
}
