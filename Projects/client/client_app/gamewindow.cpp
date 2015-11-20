#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QGraphicsView>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    connectWindowPointer(parent)

{
    logger::setLogToqDebug(true);
    ui->setupUi(this);
    battleItemsContainer.setSceneRect(MAP_WEST_EDGE,MAP_NORTH_EDGE,(-MAP_WEST_EDGE)+MAP_EAST_EDGE,(-MAP_NORTH_EDGE)+MAP_SOUTH_EDGE);
    battleItemsContainer.setBackgroundBrush(Qt::black);
    battleItemsContainer.addItem(&ourPlayer.bullet);
    battleItemsContainer.addItem(&ourPlayer);
    connect(&ourPlayer,SIGNAL(messageSignal(standardTankInfo)),
            this,SLOT(ourPlayerMessage(standardTankInfo)));

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

//    QString massage;
//    makeNewPositionMSG(ourPlayer.pos(),massage);
//    sendToServer(massage);

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setSocketPointer(client_socket *socketAdress)
{
    socketPointer=socketAdress;
    connect(socketPointer,SIGNAL(serverSendMessage(QString))
            ,this,SLOT(serverSendMessage(QString)));


}

void GameWindow::setTankName(QString name)
{
    //    ourPlayer.se
}

void GameWindow::serverSendMessage(QString data)
{
    standardTankInfo info;
    this->messenger.parseMessage(data,info);
    switch(info.tankActivity)
    {
    case moved:
        //handle move
        //void handleMove()
        //{ if(info.name == myName
        if(info.name ==ourPlayer.getName())
        {
            ourPlayer.setPosition(info);
        }

        break;
    case joined:

        //handle joined
        //dodaj do listy
        //
        break;
    case leftGame:
        //handle leftGame
        break;
    case fired:
        //handle fired
        break;
    case tankDestroyed:
        //handle tankDestroyed
        break;
    case shown:
        //handle shown
        break;
    default:
        logger::log("Should not happened, GameWindow::serverSendMessage");
        logger::log("Data from server: "+data);
        break;
    }
}

void GameWindow::ourPlayerMessage(standardTankInfo info)
{

    QString message;
    this->messenger.createMessage(info,message);
    this->socketPointer->writeToServer(message);
}




