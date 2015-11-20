#ifndef PLAYER_CLIENT_H
#define PLAYER_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QThreadPool>
#include "tcpserver.h"
//#include "positionchangedtask.h"
#include "logger.h"
#include "common_codes.h"

class TCPserver;
class player_client : public QObject
{
    Q_OBJECT
public:
    explicit player_client(QObject *parent = 0,TCPserver *serv = 0);
    ~player_client();
    void setSocket(int Descriptor);
    QString getName() const;
    void setName(const QString &value);
    QTcpSocket *getSocket() const;

    QPoint getPosition() const;
    void setPosition(const QPoint &value);

signals:
    void error(QTcpSocket::SocketError socketError);
    void playerConnected(QString name, player_client* client);
    void clientSendData(QString data, QString name);
    void clientDisconnected(QString name);

public slots:
    void firstConnection();
    void playerConnectedResult(int result);
    void disconnected();
    void readyRead();

    void write(QString data);

private:
    QTcpSocket *socket;
    QString name, tmpName;
    int descriptor;
    int goodNameProvided;
    TCPserver *server;
    QPoint position;

    int sendMsgToClient(QByteArray msg);
};

#endif // PLAYER_CLIENT_H
