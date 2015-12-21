#include "bullet.h"



bullet::bullet(QObject *parent, standardTankInfo shooterInfo, QString bulletName, QMap<QString, player_client *> *ptrToClients)
    : QObject(parent), itsInfo(shooterInfo), clients(ptrToClients)
{
    shooterName = itsInfo.name;
    itsInfo.name = bulletName;
    setBullet();
    connect(&timer,SIGNAL(timeout()),this,SLOT(moveBulletSlot()));
    timer.start(18);
}

void bullet::moveBulletSlot()
{
    moveBullet();
    QString destroyedName;
    if(checkForCollision(destroyedName))
    {
        logger::log("Preparing for creating infos");
        standardTankInfo scoredInfo, destroyedInfo;
        QString scoredMsg, destroyedMsg,killBulletMsg;

        scoredInfo.name = shooterName;
        scoredInfo.tankActivity = scored;
        scoredInfo.tankDirection = north;

        //logger::log("Found destroyed tank name: "+iter.value()->getName());
        destroyedInfo.name = destroyedName;
        destroyedInfo.tankActivity = tankDestroyed;
        destroyedInfo.tankDirection = north;

        itsInfo.tankActivity = killBullet;

        messageManager::createMessage(itsInfo,killBulletMsg);
        logger::log("Created message for killBullet:" + killBulletMsg);
        messageManager::createMessage(scoredInfo,scoredMsg);
        logger::log("Created message for scoredMsg: "+ scoredMsg);
        messageManager::createMessage(destroyedInfo,destroyedMsg);
        logger::log("Created message for destroyedMsg: "+ destroyedMsg);


        QString msg;
        msg.append(killBulletMsg);
        msg.append(scoredMsg);
        msg.append(destroyedMsg);

        logger::log("Emiting msg!");
        emit bulletHitSignal(msg, itsInfo.name, destroyedInfo.name);
    }
    else if(checkEdges())
    {
        timer.stop();
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(moveBulletSlot()));

        //inna struktura ?
        //potrzeba nazwe pocisku - zeby usunac
        //potrzeba nazwe strzelajacego - zeby doliczyc punkty
        //potrzeba nazwe trafionego - zeby usunac
        // [name]bullet000|shooter_name|destroyed_name[/name]    ???




        //a moze tak:
        //jak checkForEdges to bulletDeadSignal
        //jak checkForCollision to
        //emit bulletDeadSignal jak teraz oraz
        //emit tankDestroyedSignal




        //wersja 3
        /* Jak checkEdges to emit bulletDeadSignal
         * jak checkForCollision:
         * 1) emit bulletDeadSignal    - zeby usunac pocisk
         * 2) emit tankDestroyedSignal - zeby usunac czolg
         * 3) emit tankScoredSignal    - zeby dodac punkt
         * 4) emit tankShownSignal     - zeby wylosowac nowe wspolrzedne czolgowi,
         *                               ale to juz chyba w tcpServer
         * a jakby emitowac liste takich info?
         * albo string po prostu stworzyc sklejony z tych 4 zdarzen
         */
        itsInfo.tankActivity = killBullet;
        QString msg;
        messageManager::createMessage(itsInfo,msg);
        emit bulletDeadSignal(msg, itsInfo.name);
    }

}


QString bullet::getShooterName() const
{
    return shooterName;
}

QString bullet::getBulletName() const
{
    return itsInfo.name;
}
int bullet::checkEdges()
{
    if((itsInfo.position.x() >= MAP_EAST_EDGE)
            || (itsInfo.position.x() <= MAP_WEST_EDGE)
            || (itsInfo.position.y()<=MAP_NORTH_EDGE)
            || (itsInfo.position.y() >= MAP_SOUTH_EDGE))
        return true;

    else return false;
}

int bullet::checkForCollision(QString& destroyedName)
{
    QMapIterator<QString, player_client*> iter(*clients);
    for(int i = 0 ; i < clients->size(); i++)
    {
        iter.next();
        //ignore the sender
        if(iter.value()->getName() == shooterName)
            continue;

        int bx, by;
        bx = itsInfo.position.x()+2;
        by = itsInfo.position.y()-2;

        direction suspectDirection = iter.value()->getTankDirection();
        QPoint suspectPosition = iter.value()->getPosition();

         //s stands for suspect : )
        int sx1, sx2;
        int sy1, sy2;
        if(suspectDirection == north || suspectDirection == south)
        {
            sx1 = suspectPosition.x();
            sx2 = sx1 + TANK_WIDTH;
            sy1 = suspectPosition.y();
            sy2 = sy1 + TANK_LENGTH;

        }
        else if ( suspectDirection == east || suspectDirection == west)
        {
            sx1 = suspectPosition.x();
            sx2 = sx1 + TANK_LENGTH;
            sy1 = suspectPosition.y();
            sy2 = sy1 + TANK_WIDTH;
        }


        if(bx >= sx1 && bx <= sx2)
        {
            if(by >= sy1 && by <= sy2)
            {
                logger::log("Current bullet coords: "+ QString::number(bx) +" "+QString::number(by));
                logger::log("Current target coords x: "+ QString::number(sx1)+" "+ QString::number(sx2));
                logger::log("Current target coords y: "+ QString::number(sy1)+" "+ QString::number(sy2));
                logger::log("Hitted player: "+iter.value()->getName());
                destroyedName = iter.value()->getName();
                return true;
            }
        }
    }
    return false; //no collisions
}

void bullet::setBullet()
{
    switch(itsInfo.tankDirection)
    {
    case north:
        itsInfo.position.setX(itsInfo.position.x()+17);
        break;
    case south:
        itsInfo.position.setX(itsInfo.position.x()+17);
        itsInfo.position.setY(itsInfo.position.y()+50);
        break;
    case west:
        itsInfo.position.setX(itsInfo.position.x()-25);
        itsInfo.position.setY(itsInfo.position.y()+20);
        break;
    case east:
        itsInfo.position.setX(itsInfo.position.x()+50);
        itsInfo.position.setY(itsInfo.position.y()+20);
        break;
    }
}

void bullet::moveBullet()
{

    switch(itsInfo.tankDirection)
    {
    case north:
        //itsInfo.position.rx() = 0;
        itsInfo.position.ry() = itsInfo.position.y() - BULLET_SPEED;
        break;

    case south:
        //itsInfo.position.rx() = 0;
        itsInfo.position.ry() = itsInfo.position.y() + BULLET_SPEED;
        break;

    case east:
        itsInfo.position.rx() = itsInfo.position.x() + BULLET_SPEED;
        //itsInfo.position.ry() = 0;
        break;

    case west:
        itsInfo.position.rx() = itsInfo.position.x() - BULLET_SPEED;
        //itsInfo.position.ry() = 0;
        break;
    }
    standardTankInfo info;
    info = itsInfo;
    emit bulletMoveSignal(info);

}
