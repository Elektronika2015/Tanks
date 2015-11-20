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
    connect(client,SIGNAL(clientDisconnected(QString)),this,SLOT(clientDisconnected(QString)));
    client->setSocket(handle);
}

void TCPserver::firstConnectionRequest(QString name, player_client* client)
{
    int result = clients.contains(name);
    logger::log("Client already contains name result: " + QString::number(result));

    if(result == 0) //new name provided, success!
    {
        clients.insert(name,client);

        //disconnect from firstConnection signal
        disconnect(client,SIGNAL(playerConnected(QString,player_client*)),
                   this,SLOT(firstConnectionRequest(QString,player_client*)));

        //and connect to the regular one for the rest of the client existing.
        connect(client,SIGNAL(clientSendData(QString,QString)),this,SLOT(clientHasWritten(QString,QString)));

        //also connect to disconnect signal of client, so we can delete It from clients map
        //connect(client,SIGNAL(clientDisconnected(QString)),this,SLOT(clientDisconnected(QString)));
    }
    emit playerConnectionResult(result);
}

void TCPserver::clientHasWritten(QString data, QString name)
{
    taskFactory factory(this);
    QRunnable* task = factory.createTask(data, name);
    if(task != NULL)
        QThreadPool::globalInstance()->start(task);
    else
        logger::log("Wrong data was provided by " + name + " so the task was not created. Provided data: " + data);
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
    {
        logger::log(name + "have left the game.");
        clientHasWritten(CLIENT_DISCONNECTED_TXT,name);
        taskFactory factory(this);
        QRunnable* task = factory.createTask(CLIENT_DISCONNECTED_TXT, name);
        if(task != NULL)
            QThreadPool::globalInstance()->start(task);
        else
            logger::log("Wrong data was provided by " + name + " so the task was not created. Provided data: " + CLIENT_DISCONNECTED_TXT);

        //should update all other clients now.
    }
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
