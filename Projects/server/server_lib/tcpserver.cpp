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
        logger::log("Server started");
    }
    else
    {
        logger::log("Server not started");
        logger::log(this->errorString());
    }
}

void TCPserver::incomingConnection(qintptr handle)
{
    logger::log("Connection comes");
    player_client *client = new player_client(this,this);
    connect(client,SIGNAL(playerConnected(QString,player_client*)),
            this,SLOT(firstConnectionRequest(QString,player_client*)));
    connect(client,SIGNAL(clientDisconnected(QString)),
            this,SLOT(clientDisconnected(QString)));
    client->setSocket(handle);
}

void TCPserver::firstConnectionRequest(QString name, player_client* client)
{
    int result = clients.contains(name);
    logger::log("Client already contains name result: " + QString::number(result));

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

    int x = rand()%MAP_EAST_EDGE + 100;
    int y = rand()%MAP_NORTH_EDGE + 100;

    int tankDirection = rand() % 1 + 4;
    standardTankInfo info;
    info.name = name;
    info.position = QPoint(x,y);
    info.tankActivity = joined;
    info.tankDirection = (direction)tankDirection;
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

            //reciever in not in inGame state yet!
            if(iter.value()->getName() == name)
                continue;

            standardTankInfo info;
            info.name = iter.value()->getName();
            info.position = iter.value()->getPosition();
            info.tankDirection = iter.value()->getTankDirection();
            info.tankActivity = inGame;

            QString inGameMSG;
            messageManager::createMessage(info,inGameMSG);
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
}

int TCPserver::handleClientMoved(standardTankInfo info, QString message)
{
    if(checkForCollision(info))
    {
        //TODO: update client
        sendMessageToClients(message);
    }
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

    QMapIterator<QString, player_client*> iter(clients);
    for(int i = 0; i<clients.count(); i++)
    {
        iter.next();
        QPoint pos = iter.value()->getPosition();

        if(x == pos.x())
        {

        }
        else if(y == pos.y())
        {

        }
    }
    return true; //found collision
}

void TCPserver::clientHasWritten(QString data, QString name)
{
    standardTankInfo info;
    messageManager::parseMessage(data,info);
    if(info.tankActivity == moved)
        handleClientMoved(info,data);


//    taskFactory factory(this);
//    QRunnable* task = factory.createTask(data, name);
//    if(task != NULL)
//        QThreadPool::globalInstance()->start(task);
//    else
//        logger::log("Wrong data was provided by " + name + " so the task was not created. Provided data: " + data);
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
        logger::log("Specified client was not found in clients. Possible error. Clients name: " + name);
        return;
    }
    else if(result > 1)
    {
        logger::log("There were more than one clients of this name in a list. Should not happened. Clients name: " + name);
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
