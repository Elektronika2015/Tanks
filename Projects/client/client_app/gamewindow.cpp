#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGraphicsView>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    connectWindowPointer(parent)

{
    ui->setupUi(this);
    battleItemsContainer.setSceneRect(MAP_WEST_EDGE,MAP_NORTH_EDGE,(-MAP_WEST_EDGE)+MAP_EAST_EDGE,(-MAP_NORTH_EDGE)+MAP_SOUTH_EDGE);
    battleItemsContainer.setBackgroundBrush(Qt::black);
    battleItemsContainer.addItem(&ourPlayer.bullet);
    battleItemsContainer.addItem(&ourPlayer);

    battlefield.setScene(&battleItemsContainer);

    QPen mypen= QPen(Qt::red);
    QLineF TopLine(battleItemsContainer.sceneRect().topLeft(),battleItemsContainer.sceneRect().topRight());
    QLineF LeftLine(battleItemsContainer.sceneRect().topLeft(),battleItemsContainer.sceneRect().bottomLeft());
    QLineF RightLine(battleItemsContainer.sceneRect().topRight(),battleItemsContainer.sceneRect().bottomRight());
    QLineF BottomLine(battleItemsContainer.sceneRect().bottomLeft(),battleItemsContainer.sceneRect().bottomRight());
    battleItemsContainer.addLine(TopLine,mypen);
    battleItemsContainer.addLine(LeftLine,mypen);
    battleItemsContainer.addLine(RightLine,mypen);
    battleItemsContainer.addLine(BottomLine,mypen);


    setCentralWidget(&battlefield);






}


GameWindow::~GameWindow()
{
    delete ui;
}


