#include "messagemanager.h"

QStringList messageManager::typeList;
unsigned int messageManager::frontMarkerLen;
unsigned int messageManager::endMarkerLen;

messageManager::messageManager()
{
    typeList<<"name"<<"what"<<"posi"<<"dire";
}

int messageManager::createDefaultPartOfMessage(activity tankActivity, QPoint position, direction tankDirection, QString name, QString &dst)
{
    dst.clear();
    for(int i = 0; i < typeList.length(); i++)
    {
        QString frontMarker, endMarker;
        createTypeMarkerFront(typeList[i],frontMarker);
        createTypeMarkerEnd(typeList[i],endMarker);

        switch(i)
        {
        case 0:   //name
        {
            dst.append(frontMarker);
            dst.append(name);
            dst.append(endMarker);
            break;
        }
        case 1: //what
        {
            dst.append(frontMarker);
            QString actString;
            if(activityToString(tankActivity,actString))
            {
                logger::log("Could not translate direction to string.");
                return 1;
            }
            dst.append(actString);
            dst.append(endMarker);
            break;
        }
        case 2: //position
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
        case 3: //direction
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
    return createDefaultPartOfMessage(moved,position,tankDirection,name,dst);
}

int messageManager::createTankFiredMessage(QPoint position, direction tankDirection, QString name, QString& dst)
{
    return createDefaultPartOfMessage(fired,position,tankDirection,name,dst);
}

int messageManager::createTankShownMessage(QPoint position, direction tankDirection, QString name, QString &dst)
{
    return createDefaultPartOfMessage(shown,position,tankDirection,name,dst);
}

int messageManager::createTankDestroyedMessage(QPoint position, direction tankDirection, QString name, QString& dst)
{
    return createDefaultPartOfMessage(tankDestroyed,position,tankDirection,name,dst);
}

int messageManager::createPlayerJoinedMessage(QString name, QString &dst)
{
//    dst.clear();
//    QString frontMarker, endMarker;
//    createTypeMarkerFront("name",frontMarker);
//    createTypeMarkerEnd("name",endMarker);

//    dst.append(frontMarker);
//    dst.append(name);
//    dst.append(endMarker);

//    createTypeMarkerFront("what",frontMarker);
//    createTypeMarkerEnd("what",endMarker);

//    dst.append(frontMarker);
//    QString actString;
//    if(activityToString(joined,actString))
//    {
//        logger::log("Could not translate direction to string.");
//        return 1;
//    }
//    dst.append(actString);
//    dst.append(endMarker);


    return createDefaultPartOfMessage(joined,QPoint(1,1),north,name,dst);
}

int messageManager::createPlayerLeftGameMessage(QString name, QString &dst)
{
//    dst.clear();
//    QString frontMarker, endMarker;
//    createTypeMarkerFront("name",frontMarker);
//    createTypeMarkerEnd("name",endMarker);

//    dst.append(frontMarker);
//    dst.append(name);
//    dst.append(endMarker);

//    createTypeMarkerFront("what",frontMarker);
//    createTypeMarkerEnd("what",endMarker);

//    dst.append(frontMarker);
//    QString actString;
//    if(activityToString(leftGame,actString))
//    {
//        logger::log("Could not translate activity to string.");
//        return 1;
//    }
//    dst.append(actString);
//    dst.append(endMarker);

    return createDefaultPartOfMessage(leftGame,QPoint(1,1),north,name,dst);
}

int messageManager::parseMessageForType(QString message, QString type, standardTankInfo& info)
{
    int badRet=1;

    QString pattern, parseResult;
    pattern = "\\["+type+"\](.*?)\\[\/"+type+"\]";

    QRegularExpression re(pattern);
    QRegularExpressionMatch match = re.match(message);
    if(match.hasMatch())
    {
        parseResult = match.captured();
        parseResult = parseResult.remove(0,6);
        parseResult = parseResult.remove(parseResult.length()-7,7);

        if(parseResult==JOIN_ACTIVITY_STRING || parseResult == LEFT_GAME_ACTIVITY_STRING)
            badRet = -1;

        if(fillStandardTankInfo(parseResult, type,info))
        {
            logger::log("Could not fill standard tank info structure. Parse result: "+parseResult);
            return badRet;
        }
    }
    return !(match.hasMatch());
}

int messageManager::fillStandardTankInfo(QString param, QString type, standardTankInfo &info)
{
    if(type== typeList[0])
        info.name = param;
    else if(type == typeList[1])
    {
        activity act;
        if(stringToActivity(param,act))
        {
            logger::log("Could not parse given param to activity. Given param: "+param);
            return 1;
        }
        info.tankActivity=act;
    }
    else if(type == typeList[2])
    {
        QPoint pos;
        if(byteArrayToQPoint(param.toStdString().c_str(),pos))
        {
            logger::log("Could not parse given param to position. Given param: "+param);
            return 1;
        }
        info.position=pos;
    }
    else if(type == typeList[3])
    {
        direction dir;
        if(stringToDirection(param,dir))
        {
            logger::log("Could not parse given param to direction. Given param: "+param);
            return 1;
        }
        info.tankDirection=dir;
    }
    else
        return 1;


    return 0;
}



int messageManager::parseMessage(QString message, standardTankInfo& dst)
{
    for(int i = 0; i<typeList.count(); i++)
    {
        int ret = parseMessageForType(message,typeList[i],dst);
        if(ret)
        {
            logger::log("Something went wrong during parsing message for type: "+typeList[i]+" and given message: "+message);
            return 1;
        }
    }
    return 0;
}

 //     [name]nazwa[/name][what]co_zrobil[/what][posi]pozycja[/posi][dire]kierunek[/dire]

QStringList messageManager::getTypeList()
{
    return typeList;
}
