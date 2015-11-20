#include "client_socket.h"

client_socket::client_socket(QObject *parent)
    : QObject(parent),playerName("No name")
{
    connect(&socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(&socket,SIGNAL(connected()),this,SLOT(connected()),Qt::DirectConnection);
    connect(&socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    connect(&socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)),Qt::DirectConnection);

    firstConnection = true;
}

void client_socket::connectToServer(QString address, QString port, QString name)
{
    QHostAddress hostAddress;
    hostAddress.setAddress(address);
    playerName = name;

    socket.connectToHost(hostAddress,port.toInt());
}

int client_socket::writeToServer(QString data)
{
    if(firstConnection)
        tmpName = data;
    socket.write(data.toStdString().c_str());
    socket.flush();
}

void client_socket::connected()
{
    int result = socket.write(playerName.toStdString().c_str());
    if(result == -1)
    {
        logger::log("Could not write to server.");
        logger::log(socket.errorString());
    }
    socket.flush();
    //perform first connection
    //else regular msg passing
}

void client_socket::disconnected()
{
    socket.deleteLater();
    socket.disconnectFromHost();
}

void client_socket::readyRead()
{
    if(firstConnection == true)
    {
        QByteArray data = socket.readAll();
        if(data.isEmpty())
        {
            logger::log("Strange. Server did not send any data.");
            return;
        }

        if(data==CONNECTION_ACCEPTED)
        {
            emit connectionAccepted();
            playerName = tmpName;
            firstConnection = false;
        }
        else if(data==NAME_ALREADY_EXISTS)
        {
            emit nameAlreadyExists();
        }
    }
    else
    {
        QByteArray data = socket.readAll();
        logger::log("Data read in client: "+ playerName + " : "+data);
        if(data.isEmpty())
        {
            logger::log("Strange. Server did not send any data.");
            logger::log(socket.errorString());
            return;
        }
        emit serverSendMessage(QString(data));
    }
    //handle first connection
    //if server allowed, emit firstConnection to app
}

void client_socket::bytesWritten(qint64 bytes)
{

}

