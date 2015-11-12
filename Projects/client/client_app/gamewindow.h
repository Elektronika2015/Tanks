#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <tank.h>
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
    Tank *player;
private:
    Ui::GameWindow *ui;
    QWidget *connectWindowPointer;
    QGraphicsView * battlefield;
    QGraphicsScene *battleItemsContainer;


};

#endif // GAMEWINDOW_H
