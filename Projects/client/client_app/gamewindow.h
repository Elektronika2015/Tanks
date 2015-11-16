#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "tankmodel.h"
#include <QKeyEvent>
#include "logger.h"
#include "client_socket.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void setSocketPointer(client_socket * socketAdress){socketPointer=socketAdress;}

private:
    QGraphicsScene battleItemsContainer;
    QGraphicsView battlefield;
    TankModel ourPlayer;

    QWidget *connectWindowPointer;
    client_socket *socketPointer;
    Ui::GameWindow *ui;

    void sendToServer(QString data){socketPointer->writeToServer(data);}






};

#endif // GAMEWINDOW_H
