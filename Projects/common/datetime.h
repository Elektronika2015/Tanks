#ifndef DATETIME_H
#define DATETIME_H

/*
*   This class implements are own structure for holding both date and time.
*   It is done this way because I've experienced problems with QT dateTime structure.
*   Additionally this class is capable of translating QDate and QTime to QString.
*/

#include "common_lib.h"
#include <QDate>
#include <QTime>

class COMMON_LIBSHARED_EXPORT dateTime
{
private:
    QDate itsDate;
    QTime itsTime;

    QString dateFormat, timeFormat;
public:
    dateTime();
    dateTime(QDate date, QTime time);
    ~dateTime();

    QDate getDate() const;
    void setDate(const QDate &value);
    QTime getTime() const;
    void setTime(const QTime &value);
    dateTime getDateTime()const;
    void setDateTime(const dateTime &value);
    void setDatetime(const QDate &date, const QTime &time);

    static dateTime getCurrentDateTime();

    void clear();

    void setCurrentTime();

    QString toString();

    QString timeToString();
    QString dateToString();
    bool isNull();

    inline bool operator==(const dateTime &l) const{
        return (this->itsDate == l.getDate() &&
               this->itsTime == l.getTime());
    }
    QString getDateFormat() const;
    QString getTimeFormat() const;
};


#endif // DATETIME_H
