#include "messagemanager.h"

QStringList messageManager::typeList;

messageManager::messageManager()
{

    typeList<<"name"<<"what"<<"position"<<"direction";
}

int messageManager::createDefaultPartOfMessage(QString what, QPoint position, direction tankDirection, QString name, QString &dst)
{
    dst.clear();
    for(int i = 0; i < typeList.length(); i++)
    {
        QString frontMarker, endMarker;
        createTypeMarkerFront(typeList[i],frontMarker);
        createTypeMarkerEnd(typeList[i],endMarker);

        switch(i)
        {
        case 0:
        {
            dst.append(frontMarker);
            dst.append(name);
            dst.append(endMarker);
            break;
        }
        case 1:
        {
            dst.append(frontMarker);
            dst.append(what);
            dst.append(endMarker);
            break;
        }
        case 2:
        {
            dst.append(frontMarker);
            QByteArray posByteArray;
            if(qPointToByteArray(position,posByteArray))
            {
                logger::log("Could not translate QPoint to byte array.");
                return 1;
            }
            dst.append(QString(posByteArray));
            dst.append(endMarker);
            break;
        }
        case 3:
        {
            dst.append(frontMarker);
            QString dirString;

            if(directionToString(tankDirection,dirString))
            {
                logger::log("Could not translate direction to string.");
                return 1;
            }

            dst.append(dirString);
            dst.append(endMarker);
            break;
        }
        default:
        {
            return 1;
        }
        }
    }
    return 0;
}

int messageManager::createTypeMarkerFront(QString type, QString &dst)
{
    dst.clear();
    dst.append("[");
    dst.append(type);
    dst.append("]");
    return 0;
}

int messageManager::createTypeMarkerEnd(QString type, QString &dst)
{
    createTypeMarkerFront(type,dst);
    dst.insert(1,"/");
    return 0;
}

int messageManager::createTankMovedMessage(QPoint position, direction tankDirection, QString name, QString& dst)
{
    return createDefaultPartOfMessage("moved",position,tankDirection,name,dst);
}

int messageManager::createTankFiredMessage(QPoint position, direction tankDirection, QString name, QString& dst)
{
    return createDefaultPartOfMessage("fired",position,tankDirection,name,dst);
}

int messageManager::createTankDestroyedMessage(QPoint position, direction tankDirection, QString name, QString& dst)
{
    return createDefaultPartOfMessage("destroyed",position,tankDirection,name,dst);
}

 //     [name]nazwa[/name][what]co_zrobil[/what][position]pozycja[/position][direction]kierunek[/direction]
