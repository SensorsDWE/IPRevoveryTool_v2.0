/*!
 * \file logger.cpp
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
#include "logger.h"
#include <QString>
#include <QDir>
#include <QDate>
#include <QTime>
#include <QTextStream>

//--------------------------------------
// Creator/destructor
//--------------------------------------
Logger::Logger(QObject *parent) :
    QObject(parent)
{
    logFile = NULL;
    logFileName = "";
    logFilePath = "";
}

Logger::~Logger()
{
    // Close log file if needed - delete not needed
    if (logFile)
        logFile->close();
}

//----------------------------------
// Public methods
//----------------------------------
/*!
 * \brief Logger::logExists
 * \return true if file exists
 */
bool Logger::logExists(QString filename)
{
    return QFile::exists(QDir::currentPath() + "/" + filename);
}

/*!
 * \brief Logger::logOpen
 * \brief Open a log file in current path
 * \param filename Name of file
 * \return true if file successfully opened
 */
bool Logger::logOpen(QString filename, QIODevice::OpenModeFlag mode){
    return logOpenAbsolute(QDir::currentPath() + "/" + filename);
}

/*!
 * \brief Logger::logOpenAbsolute
 * \brief Open a log file
 * \param filename Name of file + full absolute path
 * \return true if file successfully opened
 */
bool Logger::logOpenAbsolute(QString fullfilename, QIODevice::OpenModeFlag mode)
{
    bool success = false;

    // Close log file if needed
    if (logFile){
        logFile->close();
        delete logFile;
        logFile = NULL;
    }

    // Create file
    logFile = new QFile(fullfilename, this);

    // Retrieve parameters
    QFileInfo fileInfo(*logFile);
    logFilePath = fileInfo.absolutePath();
    logFileName = fileInfo.fileName();

    // Open file
    success = logFile->open(mode | QIODevice::Text);

    return success;
}

/*!
 * \brief Logger::logRename
 * \brief Rename a log file in current path
 * \param filename New name of file
 * \return true if file successfully renamed
 */
bool Logger::logRename(QString filename){

    bool success = false;

    if (logFile){

        QString fullfilename(QDir::currentPath() + "/" + filename);

        /* Remove destination if exists */
        if (QFile::exists(fullfilename)){
            QFile tmp(fullfilename);
            success = tmp.remove();
        }

        /* Rename file */
        success = logFile->rename(fullfilename);
        if (success){
            // Update parameters
            QFileInfo fileInfo(*logFile);
            logFilePath = fileInfo.absolutePath();
            logFileName = fileInfo.fileName();
        }
    }

    return success;
}

/*!
 * \brief Logger::logClear
 * \return true if file successfully cleared
 */
bool Logger::logClear()
{
    bool success = false;
    if (logFile){
        success = logFile->resize(0);
    }
    return success;
}

/*!
 * \brief Logger::logWriteHeader
 * \return true if header successfully written
 */
bool Logger::logWriteHeader()
{
    bool success = false;
    QString version = "1.0";

    // Get runtime data
    QDateTime dateTime = QDateTime::currentDateTime();

    if (logFile){
        QTextStream out(logFile);
        out << "#Version: " << version << "\n";
        out << "#Date: " << dateTime.toString() << "\n";
        success = true;
    }
    return success;
}

/*!
 * \brief Logger::logWriteData
 * \param data
 * \return true if line successfully written
 */
bool Logger::logWriteData(QString data)
{
    bool success = false;

    if (logFile){
        QTextStream out(logFile);
        out << data << "\n";
        success = true;
    }
    return success;
}

/*!
 * \brief Logger::logReadData
 * \param data
 * \return true if line successfully read
 */
bool Logger::logRead(QString *data)
{
    bool success = false;

    if (logFile){
        QTextStream in(logFile);
        *data = in.readAll();
        success = true;
    }
    return success;
}

/*!
 * \brief Logger::logClose
 * \return true if file successfully closed
 */
bool Logger::logClose()
{
    bool success = false;
    if (logFile){
        logFile->close();
        success = true;
    }
    return success;
}

/*!
 * \brief Logger::logRemove
 * \return true if file successfully removed
 */
bool Logger::logRemove()
{
    bool success = false;
    if (logFile){
        success = logFile->remove();
    }
    return success;
}

/*!
 * \brief Logger::unitTest
 * \brief Logger unitary tests
 */
bool Logger::unitTest(){

    bool success;

    success = this->logExists("test.log");  // expects FALSE
    success = this->logOpen("test.log");    // expects true
    success = this->logExists("test.log");  // expects true
    success = this->logClose();             // expects true
    // file created

    success = this->logOpen("test.log");    // expects true
    success = this->logWriteHeader();       // expects true
    success = this->logClose();             // expects true
    // file contains header

    success = this->logOpen("test.log");            // expects true
    success = this->logWriteHeader();               // expects true
    success = this->logWriteData("Hello !");        // expects true
    success = this->logWriteData("This is a test"); // expects true
    success = this->logClose();                     // expects true
    // file contains header + data

    success = this->logOpen("test.log");    // expects true
    success = this->logClear();             // expects true
    success = this->logClose();             // expects true
    // file is empty

    success = this->logRemove();            // expects true
    // file is removed

    return success;
}
