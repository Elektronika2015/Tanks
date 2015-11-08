#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <tank.h>
#include <QKeyEvent>

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


    //virtual void keyPressEvent(QKeyEvent *event);


};

#endif // GAMEWINDOW_H
