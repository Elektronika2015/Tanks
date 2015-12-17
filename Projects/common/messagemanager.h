#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include "common_lib.h"
#include "common_codes.h"
#include "logger.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QPoint>





//     [name]nazwa[/name][what]co_zrobil[/what][position]pozycja[/position][direction]kierunek[/direction]

class messageManager
{
public:
    messageManager();

    static int createTankMovedMessage(QPoint position,direction tankDirection,QString name, QString& dst);
    static int createTankFiredMessage(QPoint position, direction tankDirection, QString name, QString& dst);
    static int createTankShownMessage(QPoint position, direction tankDirection, QString name, QString& dst);
    static int createTankDestroyedMessage(QPoint position, direction tankDirection, QString name, QString& dst);
    static int createPlayerJoinedMessage(QString name, QString &dst);
    static int createPlayerLeftGameMessage(QString name, QString &dst);


    static int createMessage(standardTankInfo info, QString &dst);

    static int parseMessage(QString message, standardTankInfo &dst);
    static int parseMultipleMessages(QString message, QList<standardTankInfo> &dst);


    static QStringList getTypeList();

private:
    static QStringList typeList;
    static unsigned int frontMarkerLen, endMarkerLen;

    static int createDefaultPartOfMessage(activity tankActivity, QPoint position, direction tankDirection, QString name, QString& dst);
    static int createTypeMarkerFront(QString type, QString& dst);
    static int createTypeMarkerEnd(QString type, QString& dst);

    static int parseMessageForType(QString message, QString type, standardTankInfo &info);
    static int fillStandardTankInfo(QString param, QString type, standardTankInfo &info);

    //for testing purposes.
    friend class mock_messageManager;
};

#endif // MESSAGEMANAGER_H
