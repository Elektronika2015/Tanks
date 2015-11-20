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
    QGraphicsScene battleItemsContainer;
    QGraphicsView battlefield;
    TankModel ourPlayer;
    messageManager messenger;
    QList<EnemyTank*> enemies;

    QWidget *connectWindowPointer;
    client_socket *socketPointer;
    Ui::GameWindow *ui;



    void sendToServer(QString data)
    {
        socketPointer->writeToServer(data);
    }

private slots:
    void serverSendMessage(QString data);
    void ourPlayerMessage(standardTankInfo info);




};

#endif // GAMEWINDOW_H
