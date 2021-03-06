#include "tcpserver.h"

TCPserver::TCPserver(QObject *parent)
    : QTcpServer(parent)
{
    logger::setLogToqDebug(true);
}

void TCPserver::startServer()
{
    if(listen(QHostAddress::Any,1234))
    {
        logger l; l.log("Server started");
    }
    else
    {
        logger l; l.log("Server not started");
        l.log(this->errorString());
    }
}

void TCPserver::incomingConnection(qintptr handle)
{
    logger l; l.log("Connection comes");
    player_client *client = new player_client(this,this);
    connect(client,SIGNAL(playerConnected(QString,player_client*)),
            this,SLOT(firstConnectionRequest(QString,player_client*)));
    connect(client,SIGNAL(clientDisconnected(QString)),
            this,SLOT(clientDisconnected(QString)));
    client->setSocket(handle);
}

void TCPserver::bulletMoveSlot(standardTankInfo info)
{
    QString msg;
    info.tankActivity = moved;
    messageManager::createMessage(info,msg);
    sendMessageToClients(msg);
}

void TCPserver::bulletDeadSlot(QString msg, QString bulletName)
{
    logger::log("collsion found for bullet");
    logger::log(msg);
    sendMessageToClients(msg);
    removeBullet(bulletName);
}

void TCPserver::bulletHitSlot(QString msg, QString bulletName, QString destroyedName)
{
    logger::log("Creating shown msg");
    QString shownMsg = setShownMsg(destroyedName);
    msg.append(shownMsg);

    sendMessageToClients(msg);
    removeBullet(bulletName);
}

void TCPserver::firstConnectionRequest(QString name, player_client* client)
{
    int result = clients.contains(name);
    logger l; l.log("Client already contains name result: " + QString::number(result));

    if(result == 0) //new name provided, success!
        handleFirstConnection(name, client);

    emit playerConnectionResult(result);
}

int TCPserver::handleFirstConnection(QString name, player_client *client)
{
    clients.insert(name,client);

    //disconnect from firstConnection signal
    disconnect(client,SIGNAL(playerConnected(QString,player_client*)),
               this,SLOT(firstConnectionRequest(QString,player_client*)));

    //and connect to the regular one for the rest of the client existing.
    connect(client,SIGNAL(clientSendData(QString,QString)),this,SLOT(clientHasWritten(QString,QString)));


    //also connect to disconnect signal of client, so we can delete It from clients map
    //connect(client,SIGNAL(clientDisconnected(QString)),this,SLOT(clientDisconnected(QString)));
    int x;
    int y;
    do
    {
        x = rand()%(MAP_EAST_EDGE+(-MAP_WEST_EDGE)-TANK_LENGTH) +MAP_WEST_EDGE;
        y = rand()%((-MAP_NORTH_EDGE)+MAP_SOUTH_EDGE-TANK_LENGTH)+MAP_NORTH_EDGE;

    }while(checkCollisionWallsWithTank(x,y));


    int tankDirection = rand() % 4 + 1;
    standardTankInfo info;
    info.name = name;
    info.position = QPoint(x,y);
    info.tankActivity = joined;
    info.tankDirection = (direction)tankDirection;
    emit playerConnectedSignal(info);
    client->setName(name);
    client->setPosition(info.position);
    client->setTankDirection(info.tankDirection);

    QString data;
    messageManager::createMessage(info,data);
    sendMessageToClients(data);
    logger::log("Server sends data in handle first connection: "+data);

    if(clients.count() > 1)
    {
        connect(this,SIGNAL(writeInGameMSG(QString)),client
                ,SLOT(write(QString)),Qt::QueuedConnection);

        QMapIterator<QString, player_client*> iter(clients);
        for(int i = 0; i<clients.count(); i++)
        {
            iter.next();

            //reciever is not in inGame state yet!
            if(iter.value()->getName() == name)
                continue;

            standardTankInfo info;
            info.name = iter.value()->getName();
            info.position = iter.value()->getPosition();
            info.tankDirection = iter.value()->getTankDirection();
            info.tankActivity = inGame;

            QString inGameMSG;
            messageManager::createMessage(info,inGameMSG);
            logger::log("Writing to "+name+" following inGameMsg: "+inGameMSG);
            emit writeInGameMSG(inGameMSG);
        }
        disconnect(this,SIGNAL(writeInGameMSG(QString)),client,SLOT(write(QString)));
    }
}

int TCPserver::handleClientLeftGame(QString name)
{
    QString message;
    messageManager::createPlayerLeftGameMessage(name, message);
    sendMessageToClients(message);
    emit playerDisconnectedSignal(name);
}

int TCPserver::handleClientMoved(standardTankInfo info, QString message)
{
    if(checkForCollision(info))
    {
        //TODO: update client
        emit playerMovedSignal(info);
        QMap<QString, player_client*>::const_iterator iter = clients.find(info.name);
        if(iter!=clients.end())
        {
            iter.value()->setPosition(info.position);
            sendMessageToClients(message);
        }
        else
            logger::log("TCPserver::handleCLientMoved did not found client in clients list. Client name: "+info.name);
    }
}

int TCPserver::handleClientFired(standardTankInfo info, QString message)
{
    bullet* b = new bullet(NULL,info,findNextPossibleName(),&clients);
    info.name = b->getBulletName();
    //info.name.append(b->getShooterName());
    messageManager::createMessage(info,message);
    sendMessageToClients(message);

    connect(b,SIGNAL(bulletMoveSignal(standardTankInfo))
            ,this,SLOT(bulletMoveSlot(standardTankInfo)));//,Qt::QueuedConnection);

    connect(b,SIGNAL(bulletDeadSignal(QString,QString))
                     ,this,SLOT(bulletDeadSlot(QString,QString)),Qt::QueuedConnection);

    connect(b,SIGNAL(bulletHitSignal(QString,QString,QString)),
            this,SLOT(bulletHitSlot(QString,QString,QString)),Qt::QueuedConnection);

    bullets.append(b);
}

QString TCPserver::setShownMsg(QString name)
{
    standardTankInfo info;
    info.name = name;
    info.tankActivity = shown;
    info.tankDirection = (direction)(rand() % 1 + 4);
    int x;
    int y;
    do
    {
        x=rand()%(MAP_EAST_EDGE+(-MAP_WEST_EDGE)-TANK_LENGTH)+ MAP_WEST_EDGE;
        y=rand()%((-MAP_NORTH_EDGE)+MAP_SOUTH_EDGE-TANK_LENGTH)+MAP_NORTH_EDGE;


    }while(checkCollisionWallsWithTank(x,y));
        info.position.setX(x);
        info.position.setY(y);
    QString ret;
    messageManager::createMessage(info,ret);

    logger::log("Created shown message: "+ret);
    QMap<QString, player_client*>::const_iterator iter = clients.find(name);
    if(iter!=clients.end())
    {
        iter.value()->setPosition(info.position);
        iter.value()->setTankDirection(info.tankDirection);
        logger::log("Updated clients position and direction!");
    }

    return ret;
}

QString TCPserver::findNextPossibleName()
{
    logger::log("Bullets count: "+QString::number(bullets.count()));
//    if(bullets.count() == 0)
//        return "bullet000";
//    else
//    {
//        int bulletLength = QString("bullet").length();
//        QVector<bool> ownedNumbers;

//        QVector<int> numbers;
//        for(int i = 0 ; i < bullets.count(); i++)
//        {
//            QString tmp = bullets[i]->getBulletName();
//            logger::log("Bullet name: "+ tmp);
//            tmp = tmp.remove(0,bulletLength);
//            logger::log("After conversion to int: "+QString::number(tmp.toInt()));
//            numbers.append(tmp.toInt());
//        }

//        //find the biggest number, so we dont need to create vector of 999 elements
//        //every time we find next possible number.
//        qSort(numbers);
//        for(int i = 0 ; i < numbers.count(); i++)
//            logger::log(QString::number(numbers[i]));
//        ownedNumbers.resize(numbers.last());
//        logger::log("The biggest number is:"+QString::number(numbers.first()));
//        for(int i = 0; i < numbers.last(); i++)
//            ownedNumbers[i]=false;

//        logger::log("Ustawianie false");
//        for(int i = 0 ; i < numbers.count(); i++)
//            logger::log(QString::number(ownedNumbers[i]));


//        //find out which numbers are already taken
//        for(int i = 0 ; i < ownedNumbers.count(); i++)
//            ownedNumbers[numbers[i]] = true;

//        logger::log("Ustawianie true");
//        for(int i = 0 ; i < numbers.count(); i++)
//            logger::log(QString::number(ownedNumbers[i]));

//        //get first possible number and create a message
//        int index = 0 ;
//        for(index; index < ownedNumbers.count(); index++)
//            if(ownedNumbers[index] == false)
//                break;

//        //the index of bullet has 3 digits, that is the reason of ifs below.
    static int index = 0;
        QString bulletName = "bullet";
        if(index < 10)
        {
            //we need to add 2 zeros before index
            bulletName.append("00");
            bulletName.append(QString::number(index));
            //bulletName.insert(bulletLength,"00");
        }
        else if (index < 100)
        {
            //we need to add 1 zero before index
            bulletName.append("0");
            bulletName.append(QString::number(index));
            //bulletName.insert(bulletLength,"0");
        }
        else
        {
            //add as it is, as it has 3 digits.
            bulletName.append(QString::number(index));
        }
        index++;
        if(index >=1000)
            index = 0 ;
        return bulletName;
   // }
}

int TCPserver::sendMessageToClients(QString data)
{
    notifyClientsTask *task = new notifyClientsTask (&this->clients,data,"tmp");
    task->setAutoDelete(true);
    QThreadPool::globalInstance()->start(task);
}

int TCPserver::checkForCollision(standardTankInfo info)
{
    int x = info.position.x();
    int y = info.position.y();
    if(checkCollisionWallsWithTank(x,y))return false;

    QMapIterator<QString, player_client*> iter(clients);
    for(int i = 0; i<clients.count(); i++)
    {
        iter.next();
        //ignore the sender
        if(iter.value()->getName() == info.name)
            continue;

        QPoint pos = iter.value()->getPosition();
        if((iter.value()->getTankDirection()==east || iter.value()->getTankDirection()==west) &&( x >=( pos.x()-TANK_LENGTH)) && (x <= pos.x()+TANK_LENGTH) )
        {
            int y1, y2;
            y1=pos.y();
            y2=pos.y()+TANK_WIDTH;
            if(y >=(y1-TANK_WIDTH) && y <=y2)
                return 0;
        }
        else if((iter.value()->getTankDirection()==north || iter.value()->getTankDirection()==south) &&( x >= (pos.x()-TANK_WIDTH)) && (x <= pos.x()+TANK_WIDTH) )
        {
            int y1, y2;
            y1=pos.y();
            y2=pos.y()+TANK_LENGTH;
            if(y >=(y1-TANK_LENGTH) && y <= y2)
                return 0;
        }


    }
    return true; //did not found collision
}

bool TCPserver::checkCollisionWallsWithTank(int x, int y)
{
    //Wall 0
    if(x>-305 & x<-195 & y >-50 & y<160)return true;

    //Wall 1
    if(x>-305 & x<-195 & y >195 & y<405)return true;

    //Wall 2
    if(x>580 & x<685 & y >-50 & y<160)return true;

    //Wall 3
    if(x>580 & x<685 & y >195 & y<405)return true;

    //Wall 4
    if(x>-120 & x<-15 & y >73 & y<283)return true;

    //Wall 5
    if(x>400 & x<505 & y >73 & y<283)return true;

    //Wall 6
    if(x>90 & x<295 & y >-50 & y<55)return true;

    //Wall 7
    if(x>90 & x<295 & y >300 & y<405)return true;

    //Oczko
    if(x>77 & x<297 & y >70 & y<287)return true;



    return false;
}



void TCPserver::removeBullet(QString bulletName)
{
    for(int i = 0 ; i <  bullets.size(); i++)
        if(bullets[i]->getBulletName() == bulletName)
        {
            delete bullets[i];
            bullets.removeAt(i);
            logger::log("Found bullet to remove: "+bulletName);
        }
}

void TCPserver::clientHasWritten(QString data, QString name)
{
    standardTankInfo info;
    messageManager::parseMessage(data,info);
    switch(info.tankActivity)
    {
    case moved:
        handleClientMoved(info,data);
        break;
    case fired:
        handleClientFired(info,data);
        break;
    default:
        logger::log("Should not have happened, GameWindow::serverSendMessage");
        logger::log("Data from server: "+data);
        break;
    }

    //    taskFactory factory(this);
    //    QRunnable* task = factory.createTask(data, name);
    //    if(task != NULL)
    //        QThreadPool::globalInstance()->start(task);
    //    else
    //        logger l; l.log("Wrong data was provided by " + name + " so the task was not created. Provided data: " + data);
}

void TCPserver::clientDisconnected(QString name)
{

    //QMutex mutex;
    //mutex.lock();
    if(name.contains("noname"))
        return;

    disconnect(clients.find(name).value(),SIGNAL(clientDisconnected(QString)),this,SLOT(clientDisconnected(QString)));
    disconnect(clients.find(name).value(),SIGNAL(clientSendData(QString,QString)),this,SLOT(clientHasWritten(QString,QString)));
    disconnect(clients.find(name).value(),SIGNAL(playerConnected(QString,player_client*)),
               this,SLOT(firstConnectionRequest(QString,player_client*)));

    int result = clients.remove(name);
    //mutex.unlock();
    if(result == 0)
    {
        logger l; l.log("Specified client was not found in clients. Possible error. Clients name: " + name);
        return;
    }
    else if(result > 1)
    {
        logger l; l.log("There were more than one clients of this name in a list. Should not happened. Clients name: " + name);
        return;
    }
    else
        handleClientLeftGame(name);
}

QHostAddress TCPserver::getServerAddress() const
{
    return this->serverAddress();
}

QString TCPserver::getServerPort() const
{
    int port = this->serverPort();
    return QString::number(port);
}
