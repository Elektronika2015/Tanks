#ifndef LOGGER_H
#define LOGGER_H

/* This class implements an object that can be used to log messages from whole application.*/

#include "common_lib.h"
#include <QString>
#include "datetime.h"
#include <QDebug>
#include <QObject>

typedef void (*callbackFunction)(QString msg);


class logger
{
private:
    static QString itsLog;
    static bool callbackIsSet;

    static bool logToqDebug;

    static callbackFunction callbackFunc;

public:
    logger();

    /**
     * @brief log function. Function logs message with current dateTime.
     * @param txt - text of message to be logged
     */
    static void log(QString txt);

    /**
     * @brief getLogToqDebug - returns wheter logger passes log output to qDebug() as well.
     * @return
     */
    static bool getLogToqDebug();

    /**
     * @brief setLogToqDebug. Sets wheter logger passes log output to qDebug() as well.
     * @param value - set to True to pass logger output to qDebug().
     */
    static void setLogToqDebug(bool value);

    static callbackFunction getCallbackFunc();
    static void setCallbackFunc(callbackFunction value);
};

//class logger:public QObject
//{
//    Q_OBJECT
//private:
//    static QString itsLog;
//    static QString newMsg;

//    static bool logToqDebug;

//public:
//    logger();

//    /**
//     * @brief log function. Function logs message with current dateTime.
//     * @param txt - text of message to be logged
//     */
//    void log(QString txt);

//    /**
//     * @brief getLogToqDebug - returns wheter logger passes log output to qDebug() as well.
//     * @return
//     */
//    static bool getLogToqDebug();

//    /**
//     * @brief setLogToqDebug. Sets wheter logger passes log output to qDebug() as well.
//     * @param value - set to True to pass logger output to qDebug().
//     */
//    static void setLogToqDebug(bool value);
//public signals:
//    void newMsgSignal(QString msg);

//};

#endif // LOGGER_H
