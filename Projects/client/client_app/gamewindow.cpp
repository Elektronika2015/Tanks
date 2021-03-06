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
    battleItemsContainer.setBackgroundBrush(Qt::black);
    battleItemsContainer.setSceneRect(MAP_WEST_EDGE,MAP_NORTH_EDGE,(-MAP_WEST_EDGE)+MAP_EAST_EDGE,(-MAP_NORTH_EDGE)+MAP_SOUTH_EDGE);
    battleItemsContainer.addItem(&mapBackground);
    battleItemsContainer.addItem(&ourPlayer.bullet);
    battleItemsContainer.addItem(&playerScore);
    battleItemsContainer.addItem(&ourPlayer);
    ourPlayer.setFocus();





    playerScore.setPos(MAP_WEST_EDGE,MAP_NORTH_EDGE-35);
    connect(&ourPlayer,SIGNAL(messageSignal(standardTankInfo)),
            this,SLOT(ourPlayerMessage(standardTankInfo)));
    battlefield.setScene(&battleItemsContainer);
    drawBarriersOnMap();

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


//    QString massage;
//    makeNewPositionMSG(ourPlayer.pos(),massage);
//    sendToServer(massage);
}
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
    ourPlayer.setName(name);
}

void GameWindow::drawBarriersOnMap()
{
    for (int i=0; i<8; i++)
    {
        battleItemsContainer.addItem(&map1.barrier[i]);
    }
}

void GameWindow::handleInGame(standardTankInfo info, QString message)
{
    if(info.name ==ourPlayer.getName())
        return;
    EnemyTank *enemy=new EnemyTank;
    enemy->setName(info.name);
    enemy->setPosition(info);
    enemies.append(enemy);
    battleItemsContainer.addItem(enemy);
    enemy->show();
}

void GameWindow::handleKillBullet(standardTankInfo info, QString message)
{
    for(int i = 0 ; i < balls.size(); i++)
    {
        if(info.name == balls[i]->getBulletName())
        {
            balls[i]->hide();
            delete balls[i];
            balls.removeAt(i);

            logger::log("Found bullet to kill. Given message:");
            logger::log(message);
            logger::log("Bullet name: " + info.name);
        }
    }
}

void GameWindow::handleDestroyed(standardTankInfo info, QString message)
{
    if(info.name == ourPlayer.getName())
    {
        ourPlayer.hide();
        //wybuch?
    }
    else
    {
        for(int i=0; i<enemies.size();i++)
        {
            if(info.name==enemies[i]->getName())
            {
                enemies[i]->hide();
                //wybuch?
                break;
            }
        }
    }
}

void GameWindow::handleShown(standardTankInfo info, QString message)
{
    if(info.name == ourPlayer.getName())
    {
        ourPlayer.setPosition(info);
        ourPlayer.show();
    }
    else
    {
        for(int i=0; i<enemies.size();i++)
        {
            if(info.name==enemies[i]->getName())
            {
                enemies[i]->setPosition(info);
                enemies[i]->show();
                break;
            }
        }
    }
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    ourPlayer.setFocus();
    logger::log("Mysz zostala kliknieta");
}


void GameWindow::serverSendMessage(QString data)
{
    QList<standardTankInfo> infoList;
    //EnemyTank *enemy=new EnemyTank;      <----- wyciek pamieci Aruś! :-)
    EnemyTank *enemy;
    Ball *b;
    messageManager::parseMultipleMessages(data,infoList);
    for(int i = 0 ; i < infoList.count(); i++)
    {
        standardTankInfo info = infoList[i];
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
            else
            {
                if(info.name.contains("bullet"))
                {

                    for(int i = 0 ; i < balls.size(); i++)
                    {
                        if(info.name == balls[i]->getBulletName())
                            balls[i]->moveMe(info.position);
                    }
                }
                else
                {
                    for(int i=0; i<enemies.size();i++)
                    {
                        if(info.name==enemies[i]->getName())
                        {
                            enemies[i]->setPosition(info);
                            break;

                        }
                    }
                }
            }

            break;
        case joined:
            if(info.name ==ourPlayer.getName())
            {
                ourPlayer.setName(info.name);
                ourPlayer.setPosition(info);
                ourPlayer.show();
            }
            else
            {
                enemy = new EnemyTank();
                enemy->setName(info.name);
                enemy->setPosition(info);
                enemies.append(enemy);
                battleItemsContainer.addItem(enemy);
            }

            //handle joined
            //dodaj do listy
            //
            break;
        case leftGame:
            for(int i=0; i<enemies.size();i++)
            {
                if(info.name==enemies[i]->getName())
                {
                    battleItemsContainer.removeItem(enemies[i]);
                    delete enemies[i];
                    enemies.removeAt(i);
                }
            }
            //index of skorzystac bo Michał prosił
            //battleItemsContainer.removeItem();
            break;
        case fired:
            //handle fired
            b = new Ball(NULL,info.name,info.name);
            balls.append(b);
            battleItemsContainer.addItem(b);
            b->show();
            break;
        case tankDestroyed:
            handleDestroyed(info,data);
            break;
        case shown:
            handleShown(info,data);
            break;
        case inGame:
            handleInGame(info,data);
            break;
        case killBullet:
            handleKillBullet(info,data);
            break;
        case scored:
            if(info.name==ourPlayer.getName())
            {
                playerScore.increase();
            }
            break;
        default:
            logger::log("Should not have happened, GameWindow::serverSendMessage");
            logger::log("Data from server: "+data);
            break;
        }
    }
}

void GameWindow::ourPlayerMessage(standardTankInfo info)
{

    QString message;
    this->messenger.createMessage(info,message);
    this->socketPointer->writeToServer(message);
}




