#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QVector>
#include <QMutex>
//#include "player_client.h"
#include "logger.h"
#include "thread.h"
#include "taskfactory.h"
#include <QPoint>

#define RUN_ON_LOCALHOST 1
#define RUN_ON_COMPUTER_HOST 2

class player_client;

class TCPserver : public QTcpServer
{
    Q_OBJECT
private:
    QMap<QString, player_client*> clients;

    friend class taskFactory;

    int handleFirstConnection(QString name, player_client* client);
    int handleClientLeftGame(QString name);
    int handleClientMoved(standardTankInfo info, QString message);
    int sendMessageToClients(QString data);

    int checkForCollision(standardTankInfo info);

public:
    explicit TCPserver(QObject *parent = 0);
    void startServer();
    QHostAddress getServerAddress() const;
    QString getServerPort() const;

protected:
    void incomingConnection(qintptr handle);

signals:
    void playerConnectionResult(int result);

public slots:
    void firstConnectionRequest(QString name, player_client *client);
    void clientHasWritten(QString data, QString name);
    void clientDisconnected(QString name);

};

#endif // TCPSERVER_H
