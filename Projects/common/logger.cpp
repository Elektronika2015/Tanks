#include "logger.h"

logger::logger()
{

}

bool logger::logToqDebug = 0;
QString logger::itsLog;

bool logger::getLogToqDebug()
{
    return logToqDebug;
}

void logger::setLogToqDebug(bool value)
{
    logToqDebug = value;
}

void logger::log(QString txt)
{
    dateTime mdt;
    mdt.setCurrentTime();

    itsLog += mdt.timeToString() + " " + txt + "\n";

    if(logToqDebug == true)
        qDebug() << mdt.timeToString() + " " + txt;
}

