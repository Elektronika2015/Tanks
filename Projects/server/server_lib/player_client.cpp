#include "player_client.h"

player_client::player_client(QObject *parent, TCPserver *serv)
    : QObject(parent), server(serv)
{

}

void player_client::setSocket(int Descriptor)
{
    socket = new QTcpSocket(this);
    this->descriptor = Descriptor;

    connect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    socket->setSocketDescriptor(Descriptor);
    qDebug()<<"client connected "<<Descriptor;
}

void player_client::firstConnection()
{
    logger::log("First connection occured for "+QString::number(descriptor));
    QByteArray data = socket->readAll();
    if(data.isEmpty())
    {
        socket->write(NO_DATA_RECEIVED);
        logger::log(socket->peerName()+ ":" + socket->peerPort() + "did not send any data. Possible Error!");
        logger::log("Socket error: "+socket->errorString());
        emit(socket->error());
        return;
    }
    else
    {
        int result = socket->write(DATA_RECEIVED);
        if(result == -1)
        {
            logger::log("Server was unable to write data to: " + socket->peerName()+ ":" + socket->peerPort());
            logger::log("Socket error: "+socket->errorString());
            emit(socket->error());
            return;
        }
        name = QString(data.toStdString().c_str());
        connect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
        emit playerConnected(name, this);

    }
}

void player_client::playerConnectedResult(int result)
{
    logger::log("player_client::playerConnectedResult function,   result value is: "+QString::number(result));
    if(result == 0)
    {
        logger::log("Client " + QString::number(descriptor) + "with name: " + name + "have successfully connected");

        sendMsgToClient(CONNECTION_ACCEPTED);

        disconnect(server,SIGNAL(playerConnectionResult(int)),this,SLOT(playerConnectedResult(int)));
        disconnect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()));
        connect(socket, SIGNAL(readyRead()),this,SLOT(readyRead()));
    }
    else
    {
        logger::log("Client " + QString::number(descriptor) + "provided name that is already in use.");
        sendMsgToClient(NAME_ALREADY_EXISTS);
    }
}

void player_client::disconnected()
{
    logger::log(this->name + "disconnected");
    socket->deleteLater();
    emit clientDisconnected(name);
    //exit(0);
}

void player_client::readyRead()
{
    QString data(this->socket->readAll());
    logger::log(this->name + ": " + data);
    emit clientSendData(data,this->name);
}
QTcpSocket *player_client::getSocket() const
{
    return socket;
}

void player_client::write(QString data)
{
    this->socket->write(data.toStdString().c_str());
    this->socket->flush();
}

int player_client::sendMsgToClient(QByteArray msg)
{
    int result = this->socket->write(msg);
    if(result == -1)
    {
        logger::log("Failed to write to client: " + QString(descriptor));
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



