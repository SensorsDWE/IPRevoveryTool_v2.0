/*!
 * \file windump.h
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
#ifndef WINDUMP_H
#define WINDUMP_H

#include <QThread>
#include <QFile>
#include <QProcess>



class Windump : public QThread
{
    Q_OBJECT
public:
    explicit Windump(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Windump();
    void run();

    enum mode{
        WINDUMP_EMIT_MODE_FIRST,    /**< Emit on first event received */
        WINDUMP_EMIT_MODE_ALL,      /**< Emit on all events received (may block QProcess if too verbose, prefer END)*/
        WINDUMP_EMIT_MODE_END      /**< Emit when capture ends (stop or timeout) */
    };

    bool setPath(QString path);
    bool selectInterface(QString name);
    bool startCapture(QFile *capture, QString filter, Windump::mode mode, int timeout);
    bool isRunning();
    bool isInterfaceSelected();
    bool getCaptureEvent(int eventId, QByteArray *event);
    bool unitTest();

public slots:
    void stopCapture(void);

signals:
    void sigMessageToUpperLayer(int level, QString error);
    void sigWindumpCaptureEvent(int eventId); /**< EventId = event numer / nb of events */

private:
    bool startWindump();
    int readLines();
    void notify(bool reset);
    bool saveCapture();

private:
    bool go;                /**< Capture has been enabled */
    int selectedInterface;  /**< Windump ID for selected interface */
    QString pathToWindump;  /**< Path to Windump.exe */
    QProcess cmdshell;      /**< Shell to Windump execution */

    QList<QByteArray> captureResults;   /**< List of results */
    QFile *captureFile;                 /**< Store capture on this file */
    QString captureFilter;              /**< Filter used for capture */
    Windump::mode captureMode;          /**< Notification mode */
    int captureTo;                      /**< Timer to stop capture */

};

#endif // WINDUMP_H
