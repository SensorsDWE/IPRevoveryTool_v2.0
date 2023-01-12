/*!
 * \file controller.h
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
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QThread>
#include <QMutex>
#include <QHash>
#include "sensor.h"
#include "logger.h"
#include "../../../Common/NetworkDiagnostic/src/netsh.h"
#include "../../../Common/NetworkDiagnostic/src/netconfig.h"
#include "../../../Common/NetworkDiagnostic/src/windump.h"

class Controller : public QThread
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Controller();
    void run();
    void sensorShow();
    bool unitTest();

    enum cmdId{
        CTRL_CMD_REFRESH_INTERFACES,
        CTRL_CMD_SELECT_INTERFACE,
        CTRL_CMD_SCAN_START,
        CTRL_CMD_SCAN_STOP,
        CTRL_CMD_SCAN_CLEAR,
        CTRL_CMD_LOAD_SENSOR,
        CTRL_CMD_SELECT_SENSOR,
        CTRL_CMD_CONFIG_SENSOR
    };
    enum itemId{
        CTRL_ITEM_INTERFACE,
        CTRL_ITEM_SENSOR,
        CTRL_ITEM_SENSOR_UPDATE,
        CTRL_ITEM_SENSOR_ALARM,
        CTRL_ITEM_SCAN_ERROR
    };

signals:
    void sigControllerNewItem(Controller::itemId item, QString name);
    void sigControllerNetworkReady(bool success);
    void sigMessageToUpperLayer(int level, QString error);

public slots:   
    void mainWindowCmdHandler(Controller::cmdId cmd, QString name);
    void windumpEventHandler(int eventId);
    void sensorEventRequestNetworkRestore();
    void sensorEventRequestNetworkChange(QString ip, QString mask);
    void sensorEventConfigChanged(QString mac);
    void messageFromLowerLayer(int level, QString error);

private:
    QString selectedInterfaceName;
    QFile *restoreInterface;
    QMutex cfgMutex; /* Protect SLOT functions that may be called from UI */

    QHash<QString, int> sensorHashList;
    QList<Sensor*> sensorList;
    int selectedSensor;

    NetConfig *netconfig;
    Netsh *netsh;
    Windump *sniffer;
    Logger *logger;

    bool windumpEventParser(QByteArray event);
    bool windumpGenerateMacFilter(QByteArray *filter);
    void clearSensorList();
    bool updateSensorList(QString mac, QString ip);
    void delay(int millisecondsToWait);

};

#endif // CONTROLLER_H
