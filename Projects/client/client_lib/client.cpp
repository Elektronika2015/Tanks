#include "client.h"
#include "logger.h"
client::client(QObject *parent)
    : QObject(parent)
{
    connect(&socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

int client::connectToServer(QString address, QString port)
{


    QHostAddress hostAddress;
    hostAddress.setAddress(address);

    socket.connectToHost(hostAddress,port.toInt());
    QString error = socket.errorString();
    if(socket.waitForConnected(20))
    {
        qDebug()<<"Connected";
    }

    int result = socket.write("player1");
    qDebug()<<("result of write: "+ QString::number(result));

    error = socket.errorString();
    qDebug()<<(error);
    this->address = address;
    this->port = port;
    return 1;

}

int client::updatePosition()
{
    QPoint point(1,0);
    QByteArray data;

    int result = qPointToByteArray(point,data);

    socket.write(data);

    return true;
}

void client::readyRead()
{

}
