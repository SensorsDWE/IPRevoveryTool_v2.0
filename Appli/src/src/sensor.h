/*!
 * \file sensor.h
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
#ifndef SENSOR_H
#define SENSOR_H


#include <QWidget>
#include <QFile>
#include <QHostAddress>
#include "../../../Common/Modbus/src/modbustcp.h"
#include "logger.h"
#include <QMessageBox>

#define SENSOR_MODBUSTCP_UNITID         0xFF
#define SENSOR_MODBUSTCP_PROTOID        0x00
#define SENSOR_MODBUSTCP_STARTADDR      0xFA10
#define SENSOR_MODBUSTCP_NBREGS         0x6

/* Position of items relative to SENSOR_MODBUSTCP_STARTADDR
 * Expresed in bytes not in regs */
#define SENSOR_MODBUSTCP_REGSIZE_B      (0x2)
#define SENSOR_MODBUSTCP_ITEMSIZE_B     (0x2 << 1)
#define SENSOR_MODBUSTCP_POSB_IP        (0x0 << 1)
#define SENSOR_MODBUSTCP_POSB_MASK      (0x2 << 1)
#define SENSOR_MODBUSTCP_POSB_GW        (0x4 << 1)

#define SENSOR_BACKUP_FILE_EXTENSION    ".bak"
#define SENSOR_CONFIG_FILE_EXTENSION    ".log"

/* Number of tentatives to send a config */
#define SENSOR_MODBUSTCP_CONN_RETRIES  5
/* Timeout for TCP connection of each tentative */
#define SENSOR_MODBUSTCP_CONN_TIMEOUT  5000

namespace Ui {
class Sensor;
}

class Sensor : public QWidget
{
    Q_OBJECT
public:
    explicit Sensor(QString mac, QObject *ctrl = 0, QWidget *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Sensor();

    bool mirrorTest(QString mac);
    bool networkCompatibility(QString ip, QString mask);
    bool setCurrentConfig(QString ip, QString mask, QString gw);
    bool saveCurrentConfig();
    bool saveNewConfig();
    bool getConfigFromSensor(bool store);
    bool loadNewConfigFromFile(QString extension);
    bool loadNewConfig(QString ip, QString mask, QString gw);
    bool applyNewConfig(QString ip, QString mask, QString gw);
    QString getMacAddress();
    QString getCurrentIpAddress();
    bool unitTest();

signals:
    void sigMessageToUpperLayer(int level, QString error);
    void sigSensorRequestNetworkChange(QString ip, QString mask);
    void sigSensorRequestNetworkRestore();
    void sigSensorConfigChanged(QString mac);

public slots:
    void messageFromLowerLayer(int level, QString error);
    void controllerEventNetworkReady(bool success);

private slots:
    void on_pushButton_apply_clicked();
    void on_pushButton_Undo_clicked();
    void on_pushButton_Done_clicked();
    void on_checkBox_clicked(bool checked);
    void on_lineEdit_ip_textEdited(const QString &arg1);
    void on_lineEdit_mask_textEdited(const QString &arg1);
    void on_lineEdit_gw_textEdited(const QString &arg1);

private:
    Ui::Sensor *ui;
    QString macaddr; /* Main identifier */
    QHostAddress ipaddr;
    QHostAddress netmask;
    QHostAddress gateway;
    QHostAddress newipaddr;
    QHostAddress newnetmask;
    QHostAddress newgateway;

    bool managed; /* Sensor is managed by an upper layer controller */
    Logger config;
    Modbustcp handler;    
};

#endif // SENSOR_H
