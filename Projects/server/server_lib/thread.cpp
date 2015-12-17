#include "thread.h"

Thread::Thread(QTcpSocket *sock, QString player_name, QObject *parent)
    :QThread(parent), socket(sock), playerName(player_name)
{

}

void Thread::run()
{
    connect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    exec();
}

void Thread::firstConnection()
{
    QByteArray data = socket->readAll();
    logger l;l.log(data);

    disconnect(socket,SIGNAL(readyRead()),this,SLOT(firstConnection()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
}

void Thread::readyRead()
{
    QByteArray data = socket->readAll();

    if(data.isEmpty())
    {
        socket->write(NO_DATA_RECEIVED);
        logger l;l.log(socket->peerName()+ ":" + socket->peerPort() + "did not send any data. Possible Error!");
        l.log("Socket error: "+socket->errorString());
        emit(socket->error());
        return;
    }
    else
    {
        int result = socket->write(DATA_RECEIVED);
        if(result == -1)
        {
            logger l;l.log("Server was unable to write data to: " + socket->peerName()+ ":" + socket->peerPort());
            l.log("Socket error: "+socket->errorString());
            emit(socket->error());
            return;
        }

        QPoint point;
        if(byteArrayToQPoint(data,point))
        {
            logger l;l.log(data);
            l.log("Thread::readyRead: Was unable to convert passed data into QPoint");
            return;
        }

        logger l;l.log(data);
        emit updatePosition(point,playerName);
    }
}

void Thread::disconnected()
{
    logger l;l.log("disconnected");
    socket->deleteLater();
    exit(0);
}

