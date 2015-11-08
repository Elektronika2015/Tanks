#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    connectWindowPointer(parent)

{
    ui->setupUi(this);
    battleItemsContainer = new QGraphicsScene(0,0,200,200);
    battleItemsContainer->setBackgroundBrush(Qt::black);
    player = new Tank("Arczi");
    battleItemsContainer->addItem(player->czolg);
    battlefield = new QGraphicsView(battleItemsContainer);

    //battlefield->show();
    setCentralWidget(battlefield);

;

}

GameWindow::~GameWindow()
{
    delete ui;
}

//void GameWindow::keyPressEvent(QKeyEvent *event)
//{
//    QPointF pos;
//    int key = event->key();
//   switch(key)
//   {
//   case Qt::Key_Right:

//        player->updateCoordinates(2,0);
//        pos = player->czolg->pos();
//        player->czolg->moveBy(2,0);
//        break;

//   case Qt::Key_Left:

//        player->updateCoordinates(-2,0);
//        player->czolg->moveBy(-2,0);
//        break;
//    default:
//       player->czolg->moveBy(2,2);

//    }

//}

