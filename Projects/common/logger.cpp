#include "logger.h"


callbackFunction logger::getCallbackFunc()
{
    return callbackFunc;
}

void logger::setCallbackFunc(callbackFunction value)
{
    callbackFunc = value;
    callbackIsSet = true;
}

logger::logger()
{

}

bool logger::logToqDebug = 0;
bool logger::callbackIsSet = 0;

QString logger::itsLog;
callbackFunction logger::callbackFunc = 0;
//QString logger::newMsg;

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
    QString msg = mdt.timeToString() + " " + txt + "\n";
    itsLog += msg;

    if(logToqDebug == true)
    {
        qDebug() << msg;
        if(callbackIsSet == true)
            callbackFunc(msg);
        //emit newLogMsg(mdt.timeToString() + " " + txt);
        //emit newMsgSignal(newMsg);
    }
}

