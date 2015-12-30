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
#include <QtAlgorithms>
#include "bullet.h"

#define RUN_ON_LOCALHOST 1
#define RUN_ON_COMPUTER_HOST 2

class player_client;
class bullet;

class TCPserver : public QTcpServer
{
    Q_OBJECT
private:
    QMap<QString, player_client*> clients;
    QList<bullet*> bullets;

    friend class taskFactory;

    int handleFirstConnection(QString name, player_client* client);
    int handleClientLeftGame(QString name);
    int handleClientMoved(standardTankInfo info, QString message);
    int handleClientFired(standardTankInfo info,QString message);

    QString setShownMsg(QString name);
    QString findNextPossibleName();
    int sendMessageToClients(QString data);

    int checkForCollision(standardTankInfo info);
    bool checkCollisionWallsWithTank(int x, int y);
    void removeBullet(QString bulletName);

public:
    explicit TCPserver(QObject *parent = 0);
    void startServer();
    QHostAddress getServerAddress() const;
    QString getServerPort() const;

protected:
    void incomingConnection(qintptr handle);

signals:
    void playerConnectionResult(int result);

    void writeInGameMSG(QString data);


    void playerConnectedSignal(standardTankInfo info);
    void playerMovedSignal(standardTankInfo info);
    void playerDisconnectedSignal(QString name);

private slots:
    void bulletMoveSlot(standardTankInfo info);
    void bulletDeadSlot(QString msg, QString bulletName);
    void bulletHitSlot(QString msg, QString bulletName, QString destroyedName);
    void firstConnectionRequest(QString name, player_client *client);
    void clientHasWritten(QString data, QString name);
    void clientDisconnected(QString name);

};

#endif // TCPSERVER_H
