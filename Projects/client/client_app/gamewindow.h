#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "tankmodel.h"
#include <QKeyEvent>
#include "logger.h"
#include "client_socket.h"
#include "messagemanager.h"
#include "common_codes.h"
#include "enemytank.h"
#include "messagemanager.h"
#include "ball.h"
#include "score.h"
#include "mapbarriers.h"
#include "background.h"

//class ball;

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void setSocketPointer(client_socket * socketAdress);
    void setTankName(QString name);

private:
    MapBarriers map1;
    QGraphicsScene battleItemsContainer;
    QGraphicsView battlefield;
    Score playerScore;
    TankModel ourPlayer;
    messageManager messenger;
    QList<EnemyTank*> enemies;
    QList<Ball*> balls; //ale jaja
    background mapBackground;

    QWidget *connectWindowPointer;
    client_socket *socketPointer;
    Ui::GameWindow *ui;



    void sendToServer(QString data)
    {
        socketPointer->writeToServer(data);
    }
    void drawBarriersOnMap();
    void handleInGame(standardTankInfo info, QString message);
    void handleKillBullet(standardTankInfo info, QString message);
    void handleDestroyed(standardTankInfo info, QString message);
    void handleShown(standardTankInfo info, QString message);
    void mousePressEvent(QMouseEvent * event);
private slots:
    void serverSendMessage(QString data);
    void ourPlayerMessage(standardTankInfo info);




};

#endif // GAMEWINDOW_H
