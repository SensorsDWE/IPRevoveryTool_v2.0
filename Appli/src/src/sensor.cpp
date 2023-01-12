/*!
 * \file sensor.cpp
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
#include "sensor.h"
#include "ui_sensor.h"
#include <QNetworkAddressEntry>
#include <QDebug>
#include <QtEndian>


//--------------------------------------
// Creator/destructor
//--------------------------------------

Sensor::Sensor(QString mac, QObject *ctrl, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Sensor)
{
    macaddr = mac;
    qDebug() << "[SENSOR] New sensor: " << macaddr;

    /* Link sensor to controller */
    if (ctrl){
        managed = true;
        connect(this, SIGNAL(sigSensorRequestNetworkChange(QString, QString)),
                ctrl, SLOT(sensorEventRequestNetworkChange(QString, QString)));
        connect(this, SIGNAL(sigSensorRequestNetworkRestore()),
                ctrl, SLOT(sensorEventRequestNetworkRestore()));
        connect(this, SIGNAL(sigSensorConfigChanged(QString)),
                ctrl, SLOT(sensorEventConfigChanged(QString)));
        connect(ctrl, SIGNAL(sigControllerNetworkReady(bool)),
                this, SLOT(controllerEventNetworkReady(bool)));

    }
    else
        managed = false;

    /* Forward error messages from handler */
    connect(&handler, SIGNAL(sigMessageToUpperLayer(int, QString)),
            this, SLOT(errorPopUp(int, QString)));

    /* Link error messages when possible */
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            ctrl, SLOT(messageFromLowerLayer(int, QString)));
    connect(this, SIGNAL(sigMessageToUpperLayer(int, QString)),
            parent, SLOT(errorPopUp(int, QString)));

    /* Avoid closing app when Config windows is closed */
    setAttribute(Qt::WA_QuitOnClose, false);

    ui->setupUi(this);
    setWindowTitle(tr("Configuration", "Device configuration window title"));
}

Sensor::~Sensor()
{
    close();
    delete ui;
}

//----------------------------------
// Public methods
//----------------------------------
/*!
 * \brief mirrorTest
 * \param mac MAC address to test
 * \return true if the MAC addres is the sensor's one
 */
bool Sensor::mirrorTest(QString mac){
    bool myself = false;
    if (mac == macaddr)
        myself = true;
    return myself;
}

/*!
 * \brief Check compatibility between sensor and given interface params
 * \param ip IP address of interface
 * \param mask MASK of interface
 * \return true when compatible
 */
bool Sensor::networkCompatibility(QString ip, QString mask){
    QNetworkAddressEntry network;
    network.setIp(QHostAddress(ip));
    network.setNetmask(QHostAddress(mask));

    return ipaddr.isInSubnet(network.ip(), network.prefixLength());
}

bool Sensor::setCurrentConfig(QString ip, QString mask, QString gw){
    bool success = false;
    QHostAddress check;
    /* Check validity of parameters before applying */
    if (3 == ip.count(".") &&
        3 == mask.count(".") &&
        true == check.setAddress(ip) &&
        true == check.setAddress(mask)){
        ipaddr.setAddress(ip);
        netmask.setAddress(mask);
        if (3 == gw.count(".") &&
            true == check.setAddress(gw))
            gateway.setAddress(gw);
        else
            gateway.setAddress(QString("0.0.0.0"));
        success = true;

        /* Update UI */
        ui->lineEdit_ip->setText(ipaddr.toString());
        ui->lineEdit_mask->setText(netmask.toString());
        ui->lineEdit_gw->setText(gateway.toString());
    }
    return success;
}

bool Sensor::saveCurrentConfig(){
    bool success = false;

    QString filename(macaddr);
    filename.remove(':');
    filename.append(SENSOR_CONFIG_FILE_EXTENSION);

    /* Save current config */
    if (config.logOpen(filename)){
        config.logClear();
        success = config.logWriteData(macaddr + " " + ipaddr.toString() + " " + netmask.toString() + " " + gateway.toString() + " \r\n");
        config.logClose();
    }

    return success;
}

bool Sensor::saveNewConfig(){
    bool success = false;

    QString filename(macaddr);
    filename.remove(':');
    filename.append(SENSOR_CONFIG_FILE_EXTENSION);

    /* If a current config file exists, keep it as .bak */
    if (config.logExists(filename)){
        success = config.logRename(filename + SENSOR_BACKUP_FILE_EXTENSION);
        config.logClose();
    }

    /* Save current config */
    if (config.logOpen(filename)){
        config.logClear();
        success = config.logWriteData(macaddr + " " + newipaddr.toString() + " " + newnetmask.toString() + " " + newgateway.toString() + " \r\n");
        config.logClose();
    }

    return success;
}

/*!
 * \brief Sensor::getConfigFromSensor
 * \param store Store retrieved parameters as current ones. Default is true.
 * \return
 */
bool Sensor::getConfigFromSensor(bool store){
    bool success = false;

    if (!ipaddr.isNull()){
        success = handler.open(ipaddr.toString(),
                               SENSOR_MODBUSTCP_PROTOID,
                               SENSOR_MODBUSTCP_UNITID);
    }

    if (success){
        QByteArray result;
        success = handler.readRegisters(SENSOR_MODBUSTCP_STARTADDR,
                                        SENSOR_MODBUSTCP_NBREGS,
                                        &result);
        if (success && result.size()>0){
            quint8 len = result.at(0);
            result.remove(0,1);

            QByteArray itemArray;
            QHostAddress tmpAddr;
            quint32 value;

            itemArray = result.mid(SENSOR_MODBUSTCP_POSB_IP, SENSOR_MODBUSTCP_ITEMSIZE_B);
            value = qFromBigEndian<quint32>((uchar*)itemArray.data());
            if (store){
                ipaddr.setAddress(value);
                ui->lineEdit_ip->setText(ipaddr.toString());
            }
            else{
                tmpAddr.setAddress(value);
                ui->lineEdit_ip->setText(tmpAddr.toString());
            }
            qDebug() << "[SENSOR] Current IP address: " << ipaddr.toString();

            itemArray = result.mid(SENSOR_MODBUSTCP_POSB_MASK, SENSOR_MODBUSTCP_ITEMSIZE_B);
            value = qFromBigEndian<quint32>((uchar*)itemArray.data());
            if (store){
                netmask.setAddress(value);
                ui->lineEdit_mask->setText(netmask.toString());
            }
            else{
                tmpAddr.setAddress(value);
                ui->lineEdit_mask->setText(tmpAddr.toString());
            }
            qDebug() << "[SENSOR] Current Netmask: " << netmask.toString();

            itemArray = result.mid(SENSOR_MODBUSTCP_POSB_GW, SENSOR_MODBUSTCP_ITEMSIZE_B);
            value = qFromBigEndian<quint32>((uchar*)itemArray.data());
            if (store){
                gateway.setAddress(value);
                ui->lineEdit_gw->setText(gateway.toString());
            }
            else{
                tmpAddr.setAddress(value);
                ui->lineEdit_gw->setText(tmpAddr.toString());
            }
            qDebug() << "[SENSOR] Current gateway: " << gateway.toString();

            handler.close();
            success = true;
        }
    }

    return success;
}

/*!
 * \brief Sensor::loadNewConfigFromFile
 * \return true if success
 */
bool Sensor::loadNewConfigFromFile(QString extension){
    bool success = false;

    QString filename(macaddr);
    filename.remove(':');
    filename.append(extension);
    if (config.logExists(filename) &&
        config.logOpen(filename)){
        QString data;
        config.logRead(&data);
        QStringList items = data.split(' ');
        if (items.size() >= 4){
            /* Check MAC addr validity */
            if (items.at(0)==macaddr){
                newipaddr.setAddress(items.at(1));
                newnetmask.setAddress(items.at(2));
                newgateway.setAddress(items.at(3));
                success = true;
            }
        }
        config.logClose();
    }
    return success;
}

bool Sensor::loadNewConfig(QString ip, QString mask, QString gw){
    bool success = false;

    QHostAddress check;
    /* Check validity of parameters before applying
     * Warning, setAdress detects malformed digits but not incomplete addresses */
    if (3 == ip.count(".") &&
        3 == mask.count(".") &&
        true == check.setAddress(ip) &&
        true == check.setAddress(mask)){
        newipaddr.setAddress(ip);
        newnetmask.setAddress(mask);
        if (3 == gw.count(".") &&
            true == check.setAddress(gw))
            newgateway.setAddress(gw);
        else
            newgateway.setAddress(QString("0.0.0.0"));
        success = true;
    }

    return success;
}

bool Sensor::applyNewConfig(QString ip, QString mask, QString gw){
    bool success = false;
    int retries = SENSOR_MODBUSTCP_CONN_RETRIES;

    if (!ipaddr.isNull()){
        while (false == success &&
               retries > 0){
            /* Network interface may be freshly configured, give some time to the operation */
            success = handler.open(ipaddr.toString(),
                                   SENSOR_MODBUSTCP_PROTOID,
                                   SENSOR_MODBUSTCP_UNITID,
                                   SENSOR_MODBUSTCP_CONN_TIMEOUT);
            retries--;
        }
    }

    if (success){
        /* Update internal config */
        success = loadNewConfig(ip, mask, gw);
    }

    if (success){

        /* Save current config */
        saveCurrentConfig();

        /* Send new config to sensor */
        QByteArray data;
        QByteArray byte(4,0);
        qToBigEndian((quint32)(newipaddr.toIPv4Address()), (uchar *)byte.data());
        data.append(byte);
        qToBigEndian((quint32)(newnetmask.toIPv4Address()), (uchar *)byte.data());
        data.append(byte);
        qToBigEndian((quint32)(newgateway.toIPv4Address()), (uchar *)byte.data());
        data.append(byte);
        success = handler.writeRegisters(SENSOR_MODBUSTCP_STARTADDR, 6, data);

        handler.close();
    }

    if (success){
        /* Save new config */
        saveNewConfig();
        QApplication::restoreOverrideCursor();
        this->hide();
        emit sigMessageToUpperLayer(2,tr("Reconfiguration succeded - New IP parameters active after reboot"));
        emit sigSensorConfigChanged(macaddr);
    }
    else{
        QApplication::restoreOverrideCursor();
        this->hide();
        emit sigMessageToUpperLayer(0,tr("Reconfiguration failed"));
    }

    if (managed &&
        ui->checkBox_autoconfig->isChecked()){
        emit sigSensorRequestNetworkRestore();
    }

    return success;
}


QString Sensor::getMacAddress(){
    return macaddr;
}

QString Sensor::getCurrentIpAddress(){
    return ipaddr.toString();
}


bool Sensor::unitTest(){
    bool success = false;

    success = this->mirrorTest("22:33:55:66:88:99"); // expect false
    success = this->mirrorTest("00:11:22:33:44:55"); // expect true

    success = this->setCurrentConfig("192.168.0.10", "255.255.255.0", ""); // expect true
    success = this->networkCompatibility("192.168.0.3", "255.255.0.0");  // expect true
    success = this->networkCompatibility("192.168.1.3", "255.255.255.0");  // expect false

    success = this->getConfigFromSensor(true);
    success = this->applyNewConfig("192.168.0.10","255.255.0.0", ""); // expect true
    //bool Sensor::saveCurrentConfig(){

    return success;

}

//----------------------------------
// Private methods
//----------------------------------

//----------------------------------
// Signals
//----------------------------------

//----------------------------------
// Public Slots
//----------------------------------
/*!
 * \brief Sensor::messageFromLowerLayer
 * \param level 0=ERROR, 1=WARNING, 2=INFO
 * \param error message
 */
void Sensor::messageFromLowerLayer(int level, QString error)
{
    /* Forward Error to upper layers */
    emit sigMessageToUpperLayer(level, error);
}


void Sensor::controllerEventNetworkReady(bool success)
{
    /* This event applies only to visible sensor */
    if (this->isVisible()){
        if (success){
            applyNewConfig(ui->lineEdit_ip->text(),
                           ui->lineEdit_mask->text(),
                           ui->lineEdit_gw->text());
        }
        QApplication::restoreOverrideCursor();
    }
}

//----------------------------------
// Private Slots
//----------------------------------
void Sensor::on_pushButton_apply_clicked()
{
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    if (managed &&
        ui->checkBox_autoconfig->isChecked()){
        emit sigSensorRequestNetworkChange(ipaddr.toString(),
                                           netmask.toString());
        /* Inform the user that this may take some time */
    }
    else {
       applyNewConfig(ui->lineEdit_ip->text(),
                      ui->lineEdit_mask->text(),
                      ui->lineEdit_gw->text());
       QApplication::restoreOverrideCursor();
    }
}

void Sensor::on_pushButton_Undo_clicked()
{
    if (loadNewConfigFromFile(SENSOR_CONFIG_FILE_EXTENSION)){
        ui->lineEdit_ip->setText(newipaddr.toString());
        ui->lineEdit_mask->setText(newnetmask.toString());
        ui->lineEdit_gw->setText(newgateway.toString());
        //on_pushButton_apply_clicked();
    }
}

void Sensor::on_pushButton_Done_clicked()
{
    this->hide();
}

void Sensor::on_checkBox_clicked(bool checked)
{
    if (checked){
        ui->lineEdit_ip->setText("192.168.0.10");
        ui->lineEdit_mask->setText("255.255.255.0");
        ui->lineEdit_gw->setText("192.168.0.2");
    }
}

void Sensor::on_lineEdit_ip_textEdited(const QString &arg1)
{
    ui->checkBox->setChecked(false);
}

void Sensor::on_lineEdit_mask_textEdited(const QString &arg1)
{
    ui->checkBox->setChecked(false);
}

void Sensor::on_lineEdit_gw_textEdited(const QString &arg1)
{
    ui->checkBox->setChecked(false);
}
