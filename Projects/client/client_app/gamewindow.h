#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "tankmodel.h"
#include <QKeyEvent>
#include "logger.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
private:
    QGraphicsScene battleItemsContainer;
    QGraphicsView battlefield;
    TankModel ourPlayer;


    Ui::GameWindow *ui;
    QWidget *connectWindowPointer;


};

#endif // GAMEWINDOW_H
