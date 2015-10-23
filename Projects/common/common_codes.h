#ifndef COMMON_CODES_H
#define COMMON_CODES_H
#include <QPoint>
#include <QByteArray>
#include <QStringList>
#include "common_lib.h"

#define DATA_RECEIVED "Data received"

#define NO_DATA_RECEIVED "No data was received"

#define CONNECTION_ACCEPTED "Connection accepted"

#define NAME_ALREADY_EXISTS "Name already exists"

#define NEW_POSITION_TXT "NEW_POS"

#define CLIENT_DISCONNECTED_TXT "CLI_DIS"

#define MSG_TXT_LENGTH 7

/**
 * @brief qPointToByteArray takes QPoint and returns its string version in format x:y
 * @param src - Qpoint
 * @param dst - reference to destination QByteArray
 * @return if succeds returns 0, otherwise 1.
 */
static int qPointToByteArray(QPoint src, QByteArray& dst)
{
    if(src.isNull())
        return 1;

    if(src.x() < 0 || src.y() < 0)
        return 1;

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
    if(src.isEmpty() || src.isNull())
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

    if(pos.x() < 0 || pos.y() < 0)
        return 1;

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

#endif // COMMON_CODES_H

