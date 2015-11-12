#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGraphicsView>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    connectWindowPointer(parent)

{
    ui->setupUi(this);
    battleItemsContainer = new QGraphicsScene(-380,-90,1220,635);
    battleItemsContainer->setBackgroundBrush(Qt::black);
    player = new Tank("Arczi");
    battleItemsContainer->addItem(player->czolg);
    battlefield = new QGraphicsView(battleItemsContainer);
    QPen mypen= QPen(Qt::red);
    QLineF TopLine(battleItemsContainer->sceneRect().topLeft(),battleItemsContainer->sceneRect().topRight());
    QLineF LeftLine(battleItemsContainer->sceneRect().topLeft(),battleItemsContainer->sceneRect().bottomLeft());
    QLineF RightLine(battleItemsContainer->sceneRect().topRight(),battleItemsContainer->sceneRect().bottomRight());
    QLineF BottomLine(battleItemsContainer->sceneRect().bottomLeft(),battleItemsContainer->sceneRect().bottomRight());
    battleItemsContainer->addLine(TopLine,mypen);
    battleItemsContainer->addLine(LeftLine,mypen);
    battleItemsContainer->addLine(RightLine,mypen);
    battleItemsContainer->addLine(BottomLine,mypen);
    player->czolg->pointerToBattleItemsCointainer==battleItemsContainer;
    setCentralWidget(battlefield);






}


GameWindow::~GameWindow()
{
    delete ui;
}





