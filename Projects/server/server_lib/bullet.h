#ifndef BULLET_H
#define BULLET_H
#include "common_codes.h"
#include <QTimer>
#include "player_client.h"

class player_client;
#define BULLET_SPEED 5

class bullet : public QObject
{
    Q_OBJECT
private:
    standardTankInfo itsInfo;
    QMap<QString, player_client*>* clients;
    QString shooterName;
    QTimer timer;

    int checkEdges();
    int checkForCollision();
    void setBullet();
    void moveBullet();
public:
    explicit bullet(QObject *parent, standardTankInfo shooterInfo, QString bulletName,QMap<QString, player_client*>* ptrToClients);

    QString getShooterName() const;
    QString getBulletName() const;

signals:
    void bulletMoveSignal(standardTankInfo info);
    void bulletDeadSignal(standardTankInfo info);

private slots:
    void moveBulletSlot();
};

#endif // BULLET_H
