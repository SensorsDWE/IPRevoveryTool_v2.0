/*!
 * \file logger.h
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
#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = 0); /**< The "explicit" keyword prevents type conversion. */
    ~Logger();
    bool logExists(QString filename);
    bool logOpen(QString filename, QIODevice::OpenModeFlag mode = QIODevice::ReadWrite);
    bool logOpenAbsolute(QString fullfilename, QIODevice::OpenModeFlag mode = QIODevice::ReadWrite);
    bool logRename(QString fullfilename);
    bool logClear();
    bool logWriteHeader();
    bool logWriteData(QString data);
    bool logRead(QString *data);
    bool logClose();
    bool logRemove();
    bool unitTest();

signals:

public slots:

private:
    QFile *logFile;
    QString logFileName;
    QString logFilePath;

};

#endif // LOGGER_H
