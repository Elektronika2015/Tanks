#ifndef COMMON_CODES_H
#define COMMON_CODES_H
#include <QPoint>
#include <QByteArray>
#include <QStringList>
#include "common_lib.h"

#define TANK_LENGTH 50
#define TANK_WIDTH 40

#define DATA_RECEIVED "Data received"

#define NO_DATA_RECEIVED "No data was received"

#define CONNECTION_ACCEPTED "Connection accepted"

#define NAME_ALREADY_EXISTS "Name already exists"

#define NEW_POSITION_TXT "NEW_POS"

#define CLIENT_DISCONNECTED_TXT "CLI_DIS"

#define MSG_TXT_LENGTH 7

#define MAP_EAST_EDGE       795
#define MAP_WEST_EDGE      -375
#define MAP_NORTH_EDGE     -90
#define MAP_SOUTH_EDGE      495

/**
 * @brief qPointToByteArray takes QPoint and returns its string version in format x:y
 * @param src - Qpoint
 * @param dst - reference to destination QByteArray
 * @return if succeds returns 0, otherwise 1.
 */
static int qPointToByteArray(QPoint src, QByteArray& dst)
{
//    if(src.isNull())
//        return 1;

//    if(src.x() < 0 || src.y() < 0)
//        return 1;

    QString tmp = QString::number(src.x()) +":"+ QString::number(src.y());
    dst = tmp.toStdString().c_str();
    return 0;
}


/**
 * @brief byteArrayToQPoint takes byteArray and returns QPoint. String must have format x:y.
 * @param src
 * @param dst
 * @return if succeds returns 0, otherwise 1.
 */
static int byteArrayToQPoint(QByteArray src, QPoint& dst)
{
    if(src.isEmpty())// || src.isNull())
        return 1;

    QString tmp;
    for(int i = 0;i < src.count(); i++)
    {
        if(src[i] == ':')
        {
            bool ok;
            int result = tmp.toInt(&ok);

            if(ok == true)
                dst.setX(result);
            else
                return 1;

            tmp.clear();
            continue;
        }

        if(src[i+1] == '\0')
        {
            tmp.append(src.at(i));
            bool ok;
            int result = tmp.toInt(&ok);

            if(ok == true)
                dst.setY(result);
            else
                return 1;

            break;
        }

        tmp.append(src.at(i));
    }

    return 0;
}


/**
 * @brief makePositionChangedMsg takes position and returns a ready message to pass to server.
 * @param pos
 * @param dst
 * @return if succeds returns 0, otherwise 1.
 */
static int makeNewPositionMSG(QPoint pos, QByteArray& dst)
{
    if(pos.isNull())
        return 1;

//    if(pos.x() < 0 || pos.y() < 0)
//        return 1;

    dst=NEW_POSITION_TXT;

    QByteArray tmp;
    if(qPointToByteArray(pos, tmp))
    {
        dst.clear();
        dst = "Error while parsing from QPoint to QByteArray.";
        return 1;
    }

    dst.append(tmp);
    return 0;
}

/**
 * @brief getPosStringFromData retrieves position string from NEW_POSITION_TXT
 * @param src
 * @param dst
 * @return if succeds returns 0, otherwise 1.
 */
static int getPosStringFromData(QByteArray src, QByteArray &dst)
{
    for(int i = MSG_TXT_LENGTH; i<src.count(); i++)
        dst.append(src.at(i));

    return 0;
}


enum direction
{
    north = 1,
    east,
    south,
    west
};


static int directionToString(direction dir, QString& dst)
{
    switch(dir)
    {
    case north:
        dst = "north";
        break;
    case south:
        dst="south";
        break;
    case east:
        dst="east";
        break;
    case west:
        dst="west";
        break;
    default:
        return 1;
    }
    return 0;
}

static int stringToDirection(QString dirString, direction &dst)
{
    if(dirString == "north")
        dst = north;
    else if(dirString == "east")
        dst=east;
    else if(dirString == "south")
        dst=south;
    else if(dirString == "west")
        dst=west;
    else
        return 1;

    return 0;
}

enum activity
{
    joined= 1,
    leftGame,
    moved,
    fired,
    tankDestroyed,
    shown,    //shown on map, after joined and destroyed
    inGame,
    scored,
    killBullet
};

#define JOIN_ACTIVITY_STRING "joined"
#define LEFT_GAME_ACTIVITY_STRING "leftGame"
#define MOVED_ACTIVITY_STRING "moved"
#define FIRED_ACTIVITY_STRING "fired"
#define DESTROYED_ACTIVITY_STRING "destroyed"
#define SHOWN_ACTIVITY_STRING "shown"
#define IN_GAME_ACTIVITY_STRING "inGame"
#define SCORED_ACTIVITY_STRING "scored"
#define KILL_BULLET_ACTIVITY_STRING "killBullet"

static int activityToString(activity act, QString &dst)
{
    switch(act)
    {
    case joined:
        dst = JOIN_ACTIVITY_STRING;
        break;
    case leftGame:
        dst=LEFT_GAME_ACTIVITY_STRING;
        break;
    case moved:
        dst=MOVED_ACTIVITY_STRING;
        break;
    case fired:
        dst=FIRED_ACTIVITY_STRING;
        break;
    case tankDestroyed:
        dst=DESTROYED_ACTIVITY_STRING;
        break;
    case shown:
        dst=SHOWN_ACTIVITY_STRING;
        break;
    case inGame:
        dst=IN_GAME_ACTIVITY_STRING;
        break;
    case scored:
        dst=SCORED_ACTIVITY_STRING;
        break;
    case killBullet:
        dst=KILL_BULLET_ACTIVITY_STRING;
        break;
    default:
        return 1;
    }
    return 0;
}

static int stringToActivity(QString actString, activity &dst)
{
    if(actString == JOIN_ACTIVITY_STRING)
        dst = joined;
    else if(actString == LEFT_GAME_ACTIVITY_STRING)
        dst=leftGame;
    else if(actString == MOVED_ACTIVITY_STRING)
        dst=moved;
    else if(actString == FIRED_ACTIVITY_STRING)
        dst=fired;
    else if(actString == SHOWN_ACTIVITY_STRING)
        dst = shown;
    else if(actString == DESTROYED_ACTIVITY_STRING)
        dst=tankDestroyed;
    else if(actString == IN_GAME_ACTIVITY_STRING)
        dst=inGame;
    else if(actString == SCORED_ACTIVITY_STRING)
        dst=scored;
    else if(actString == KILL_BULLET_ACTIVITY_STRING)
        dst=killBullet;
    else
        return 1;

    return 0;
}

struct standardTankInfo
{
    QPoint position;
    direction tankDirection;
    QString name;
    activity tankActivity;


    inline bool operator==(const standardTankInfo &l) const{
        return (this->position == l.position &&
               this->tankDirection == l.tankDirection &&
                this->name == l.name);
    }
};

#endif // COMMON_CODES_H

