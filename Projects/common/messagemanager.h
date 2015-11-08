#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include "common_lib.h"
#include "common_codes.h"
#include "logger.h"
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

    static int createTankDestroyedMessage(QPoint position, direction tankDirection, QString name, QString& dst);

private:
    static QStringList typeList;

    static int createDefaultPartOfMessage(QString what, QPoint position, direction tankDirection, QString name, QString& dst);
    static int createTypeMarkerFront(QString type, QString& dst);
    static int createTypeMarkerEnd(QString type, QString& dst);


    //for testing purposes.
    friend class mock_messageManager;

};

#endif // MESSAGEMANAGER_H
