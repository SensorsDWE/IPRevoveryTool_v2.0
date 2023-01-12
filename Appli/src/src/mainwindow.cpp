/*!
 * \file mainwindow.cpp
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
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include "logger.h"

//--------------------------------------
// Creator/destructor
//--------------------------------------
MainWindow::MainWindow(Controller* controller, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ctrl = controller;

    /* Link Model to View (via Controller)*/
    qRegisterMetaType<Controller::itemId>("Controller::itemId");
    connect(ctrl, SIGNAL(sigControllerNewItem(Controller::itemId,QString)),
            this, SLOT(controllerNewItemHandler(Controller::itemId,QString)));
    connect(ctrl, SIGNAL(sigMessageToUpperLayer(int, QString)),
            this, SLOT(messageFromLowerLayer(int, QString)));


    /* Link View to Model (via Controller) */
    qRegisterMetaType<Controller::itemId>("Controller::cmdId");
    connect(this, SIGNAL(sigMainWindowCmd(Controller::cmdId, QString)),
            ctrl, SLOT(mainWindowCmdHandler(Controller::cmdId, QString)));

    ui->setupUi(this);
    setWindowTitle(tr("IP Recovery Tool", "Main window title"));

    /* Initialize interface list */
    emit sigMainWindowCmd(Controller::CTRL_CMD_REFRESH_INTERFACES, NULL);
}

MainWindow::~MainWindow()
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
// Public slots
//----------------------------------
void MainWindow::controllerNewItemHandler(Controller::itemId item, QString name){

    switch (item){
        case Controller::CTRL_ITEM_INTERFACE:
            ui->comboBox_NetInterfaceSelector->addItem(name);
        break;

        case Controller::CTRL_ITEM_SCAN_ERROR:
            ui->label_capturing->setText("<span style=\" font-weight:bold;\">"+tr("Stopped")+"</span>");
            ui->progressBar_capturing->setMaximum(10); /* Make the progress bar stop */
        break;

        case Controller::CTRL_ITEM_SENSOR:
            //QString mac = ctrl->sensorList.at(index)->macaddr;
            //QString ip = ctrl->netconfig->getInterfaceIp(index);
            /* Print name + IP */
            ui->listWidget_ScanResults->addItem(name);
        break;

        case Controller::CTRL_ITEM_SENSOR_ALARM:
        case Controller::CTRL_ITEM_SENSOR_UPDATE:
        {
            bool success;
            int evtItemNb = name.left(1).toInt(&success);
            if (success){
                int i;
                for (i=0; i<ui->listWidget_ScanResults->count(); i++){
                    int listItemNb = ui->listWidget_ScanResults->item(i)->text().left(1).toInt(&success);
                    if (success &&
                        evtItemNb == listItemNb){
                        ui->listWidget_ScanResults->item(i)->setText(name);
                        if (Controller::CTRL_ITEM_SENSOR_ALARM == item)
                            ui->listWidget_ScanResults->item(i)->setTextColor(Qt::red);
                        else
                            ui->listWidget_ScanResults->item(i)->setTextColor(Qt::black);
                    }
                }
            }
        }
        break;

        default:
        break;
    }
}


//----------------------------------
// Qt Application public SLOTS
//----------------------------------
/*!
 * \brief MainWindow::messageFromLowerLayer
 * \param level 0=ERROR, 1=WARNING, 2=INFO
 * \param error message
 */
void MainWindow::messageFromLowerLayer(int level, QString error)
{
    // Create msgBox as child, otherwise popup closure will terminate the whole application
    QMessageBox *msgBox = new QMessageBox(this);
    switch (level){
        case 0:
            /* ERROR */
            msgBox->setText(tr("ERROR: ","Text on ERROR pop ups")+error);
        break;

        case 1:
            /* WARNING */
             msgBox->setText(tr("WARNING: ","Text on WARNING pop ups")+error);
        break;

        case 2:
            /* INFO */
            msgBox->setText(tr("INFO: ","Text on INFO pop ups")+error);
        break;
    }
    msgBox->exec();
}
//----------------------------------
// Qt Application internal SLOTS
//----------------------------------
void MainWindow::on_comboBox_NetInterfaceSelector_activated(const QString &arg1)
{
    emit sigMainWindowCmd(Controller::CTRL_CMD_SELECT_INTERFACE, arg1);
}

void MainWindow::on_pushButton_Scan_clicked()
{
    ui->label_capturing->setText("<span style=\" font-weight:bold; color:#0A79C9;\">"+tr("Scanning")+"</span>");
    ui->progressBar_capturing->setMaximum(0); /* Make the progress bar move */
    emit sigMainWindowCmd(Controller::CTRL_CMD_SCAN_START, NULL);
}

void MainWindow::on_pushButton_StopScan_clicked()
{
    emit sigMainWindowCmd(Controller::CTRL_CMD_SCAN_STOP, NULL);
    ui->label_capturing->setText("<span style=\" font-weight:bold;\">"+tr("Stopped")+"</span>");
    ui->progressBar_capturing->setMaximum(10); /* Make the progress bar stop */
}

void MainWindow::on_pushButton_Clear_clicked()
{
    emit sigMainWindowCmd(Controller::CTRL_CMD_SCAN_CLEAR, NULL);
    ui->listWidget_ScanResults->clear();
}

void MainWindow::on_pushButton_ConfigDevice_clicked()
{
    // Stop scan if running
    on_pushButton_StopScan_clicked();

    //emit sigMainWindowCmd(Controller::CTRL_CMD_CONFIG_SENSOR, currentSensor);
    // This is going to be IHM, so run it from MainWindow Thread
    ctrl->sensorShow();
}


void MainWindow::on_listWidget_ScanResults_itemClicked(QListWidgetItem *item)
{
    emit sigMainWindowCmd(Controller::CTRL_CMD_SELECT_SENSOR, item->text());
}

void MainWindow::on_pushButton_Exit_clicked()
{
    exit(0);
}

void MainWindow::on_actionAbout_triggered()
{
    Logger file;
    if (file.logOpenAbsolute(":/Licences/General.txt", QIODevice::ReadOnly)){
        QString data;
        if (file.logRead(&data)){
            AboutDialog *about = new AboutDialog(data, this);
            about->setModal(false);
            about->show();
        }
        file.logClose();
    }
}

void MainWindow::showLicence(QString licensefile)
{
    Logger file;
    if (file.logOpenAbsolute(licensefile, QIODevice::ReadOnly)){
        QString data;
        if (file.logRead(&data)){
            AboutDialog *about = new AboutDialog(data, this);
            about->setModal(false);
            about->show();
        }
        file.logClose();
    }
}

void MainWindow::on_actionLicenseQt_triggered()
{
    showLicence(":/Licences/Qt.txt");
}

void MainWindow::on_actionLicenseWinDump_triggered()
{
    showLicence(":/Licences/WinDump.txt");

}

void MainWindow::on_actionLicenseWinPcap_triggered()
{
    showLicence(":/Licences/WinPcap.txt");
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_actionLoadSensor_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Load Device"),
                tr("%1/device.log").arg(QDir::currentPath()),
                tr("Log Files (*.log);;All Files (*)")
                );

    if(filename.isEmpty())
        return;
    else {
        emit sigMainWindowCmd(Controller::CTRL_CMD_LOAD_SENSOR, filename);
    }
}
