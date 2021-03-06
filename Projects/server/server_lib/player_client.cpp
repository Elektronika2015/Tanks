#include "player_client.h"

player_client::player_client(QObject *parent, TCPserver *serv)
    : QObject(parent), server(serv)
{

}

player_client::~player_client()
{
    socket->deleteLater();
//    disconnect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()));
//    disconnect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
//    disconnect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
    delete socket;
}

void player_client::setSocket(int Descriptor)
{
    socket = new QTcpSocket(this);
    this->descriptor = Descriptor;

    connect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    socket->setSocketDescriptor(Descriptor);
    name = "noname"+QString::number(Descriptor);
    qDebug()<<"client connected "<<Descriptor;
}

void player_client::firstConnection()
{
    logger l; l.log("First connection occured for "+QString::number(descriptor));
    QByteArray data = socket->readAll();
    if(data.isEmpty())
    {
        socket->write(NO_DATA_RECEIVED);
        logger l; l.log(socket->peerName()+ ":" + socket->peerPort() + "did not send any data. Possible Error!");
        l.log("Socket error: "+socket->errorString());
        emit(socket->error());
        return;
    }
    else
    {
//        int result = socket->write(DATA_RECEIVED);
//        socket->flush();
//        if(result == -1)
//        {
//            logger l; l.log("Server was unable to write data to: " + socket->peerName()+ ":" + socket->peerPort());
//            logger l; l.log("Socket error: "+socket->errorString());
//            emit(socket->error());
//            return;
//        }
        tmpName = QString(data.toStdString().c_str());
        connect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
        emit playerConnected(tmpName, this);

    }
}

void player_client::playerConnectedResult(int result)
{
    logger l; l.log("player_client::playerConnectedResult function,   result value is: "+QString::number(result));
    if(result == 0)
    {
        name = tmpName;
        logger l; l.log("Client " + QString::number(descriptor) + " with name: " + name + "have successfully connected");

        sendMsgToClient(CONNECTION_ACCEPTED);

        disconnect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()));
        connect(socket, SIGNAL(readyRead()),this,SLOT(readyRead()));
    }
    else
    {
        logger l; l.log("Client " + QString::number(descriptor) + " provided name that is already in use.");
        sendMsgToClient(NAME_ALREADY_EXISTS);
    }
}

void player_client::disconnected()
{
    logger l; l.log(this->name + " disconnected");
    socket->deleteLater();
    socket->disconnectFromHost();
    disconnect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()));
    disconnect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    disconnect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
    emit clientDisconnected(name);
    //exit(0);
}

void player_client::readyRead()
{
    QString data(this->socket->readAll());
    logger l; l.log(this->name + ": " + data);
    emit clientSendData(data,this->name);
}
QTcpSocket *player_client::getSocket() const
{
    return socket;
}

void player_client::write(QString data)
{
    int result;
    result = this->socket->write(data.toStdString().c_str());
    if(result == -1)
    {
        logger l; l.log("Could not write to client: "+name);
        l.log("Message: "+data);
    }
    this->socket->flush();
}
direction player_client::getTankDirection() const
{
    return tankDirection;
}

void player_client::setTankDirection(const direction &value)
{
    tankDirection = value;
}

QPoint player_client::getPosition() const
{
    return position;
}

void player_client::setPosition(const QPoint &value)
{
    position = value;
}


int player_client::sendMsgToClient(QByteArray msg)
{
    logger l; l.log("Trying to send msg: "+QString(msg)+ "to: "+QString::number(descriptor));
    int result = this->socket->write(msg);
    socket->flush();
    if(result == -1)
    {
        logger l; l.log("Failed to write to client: " + QString(descriptor));
    }
    return result;
}


QString player_client::getName() const
{
    return name;
}

void player_client::setName(const QString &value)
{
    name = value;
}



