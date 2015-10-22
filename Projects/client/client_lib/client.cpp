#include "client.h"
#include "logger.h"
client::client(QObject *parent)
    : QObject(parent)
{

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
    logger::log("przed qpoint");
    int result = qPointToByteArray(point,data);
    logger::log(data);
    logger::log("po qpoint");
    socket.write(data);

    return true;
}

