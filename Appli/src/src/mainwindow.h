/*!
 * \file mainwindow.h
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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Controller* controller, QWidget *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~MainWindow();

signals:
    void sigMainWindowCmd(Controller::cmdId cmd, QString name);

public slots:
    void controllerNewItemHandler(Controller::itemId item, QString name);
    void messageFromLowerLayer(int level, QString error);

private slots:
    void on_pushButton_Scan_clicked();
    void on_pushButton_StopScan_clicked();
    void on_pushButton_Clear_clicked();
    void on_pushButton_ConfigDevice_clicked();
    void on_listWidget_ScanResults_itemClicked(QListWidgetItem *item);
    void on_pushButton_Exit_clicked();
    void on_actionAbout_triggered();
    void on_actionLicenseQt_triggered();
    void on_actionLicenseWinDump_triggered();
    void on_actionLicenseWinPcap_triggered();
    void on_actionExit_triggered();
    void on_comboBox_NetInterfaceSelector_activated(const QString &arg1);
    void on_actionLoadSensor_triggered();
private:
    Ui::MainWindow *ui;
    Controller *ctrl;

    void showLicence(QString licensefile);

};

#endif // MAINWINDOW_H
