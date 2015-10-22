#include "datetime.h"
#include "logger.h"

QDate dateTime::getDate() const
{
    return itsDate;
}

void dateTime::setDate(const QDate &value)
{
    itsDate = value;
}

QTime dateTime::getTime() const
{
    return itsTime;
}

void dateTime::setTime(const QTime &value)
{
    itsTime = value;
}

dateTime dateTime::getDateTime() const
{
    return *this;
}

void dateTime::setDateTime(const dateTime &value)
{
    this->itsDate = value.getDate();
    this->itsTime = value.getTime();
}

void dateTime::setDatetime(const QDate &date, const QTime &time)
{
    this->itsDate = date;
    this->itsTime = time;
}

dateTime dateTime::getCurrentDateTime()
{
    dateTime mdt;
    mdt.setDate(QDate::currentDate());
    mdt.setTime(QTime::currentTime());
    return mdt;
}

void dateTime::setCurrentTime()
{
    itsDate = QDate::currentDate();
    itsTime = QTime::currentTime();
}

QString dateTime::toString()
{
    if(this->isNull())
        return "";

    QString result;
    result.append(itsDate.toString("dd.MM.yyyy"));
    result.append(" ");
    result.append(itsTime.toString("hh:mm:ss"));
    return result;
}

QString dateTime::timeToString()
{
    if(this->isNull())
        return "";
    return itsTime.toString("hh:mm:ss");
}

QString dateTime::dateToString()
{
    if(this->isNull())
        return "";
    return itsDate.toString("dd.MM.yyyy");
}

bool dateTime::isNull()
{
    return (itsDate.isNull() && itsTime.isNull());
}

void dateTime::clear()
{
    //itsDate.
    //itsTime = NULL;
}


QString dateTime::getDateFormat() const
{
    return dateFormat;
}

QString dateTime::getTimeFormat() const
{
    return timeFormat;
}

dateTime::dateTime()
{
    dateFormat = "dd.MM.yyyy";
    timeFormat = "hh:mm:ss";
}

dateTime::dateTime(QDate date, QTime time)
{
    itsDate = date;
    itsTime = time;
    dateFormat = "dd.MM.yyyy";
    timeFormat = "hh:mm:ss";
}

dateTime::~dateTime()
{

}

