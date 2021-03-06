#include "tankmodel.h"
#include "logger.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    name = "noname";
    tankDirection =north;
    setPos(1,1);
    setTransformOriginPoint(20,25);
    shootTimerIsOn = false;
    variableResponsibleForKeepTheValueOfLastUsingQtKeyInKeyPressEventFunction=-1;
}


QRectF TankModel::boundingRect() const
{
    return QRectF(0,0,40,50); //edges of Tank

}


void TankModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, QPixmap(":/Graphics/tank1.png"));
}
QString TankModel::getName() const
{
    return name;
}

void TankModel::setName(const QString &value)
{
    name = value;
}

void TankModel::setPosition(standardTankInfo info)
{
    setPos(info.position.x(),info.position.y());
    setTankDirection(info.tankDirection);
}

void TankModel::setTankDirection(direction dir)
{
    switch(dir)
    {
        case east:
        setRotation(90);
        tankDirection=east;
        break;

    case west:
        setRotation(270);
        tankDirection=west;
        break;

    case north:
        setRotation(0);
        tankDirection=north;
        break;

    case south:
        setRotation(180);
        tankDirection=south;

        break;


    }
}


void TankModel::keyPressEvent(QKeyEvent *event)
{
    standardTankInfo info;
    if(variableResponsibleForKeepTheValueOfLastUsingQtKeyInKeyPressEventFunction!=event->key()&& variableResponsibleForKeepTheValueOfLastUsingQtKeyInKeyPressEventFunction!=Qt::Key_Space)
    {
        disconnectAndStopTimer2Slot();
    }
    switch(event->key())
    {
    case Qt::Key_Right:
        if(moveTimer2IsOn == false)
        {
            connect(&timer2,SIGNAL(timeout()),this,SLOT(disconnectAndStopTimer2Slot()));
            timer2.start(30);
            moveTimer2IsOn = true;
        }
        else
        {
            break;
        }
        if(!(check_map_edges(east))) break;
        tankDirection=east;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.rx() += 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        emit messageSignal(info);
        break;

   case Qt::Key_Left:
        if(moveTimer2IsOn == false)
        {
            connect(&timer2,SIGNAL(timeout()),this,SLOT(disconnectAndStopTimer2Slot()));
            timer2.start(30);
            moveTimer2IsOn = true;
        }
        else
        {
            break;
        }
        if(!(check_map_edges(west))) break;
        tankDirection=west;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.rx() -= 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        emit messageSignal(info);
        break;


   case Qt::Key_Up:
        if(moveTimer2IsOn == false)
        {
            connect(&timer2,SIGNAL(timeout()),this,SLOT(disconnectAndStopTimer2Slot()));
            timer2.start(30);
            moveTimer2IsOn = true;
        }
        else
        {
            break;
        }
        if(!(check_map_edges(north))) break;
        tankDirection=north;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.ry() -= 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        emit messageSignal(info);
        break;


   case Qt::Key_Down:
        if(moveTimer2IsOn == false)
        {
            connect(&timer2,SIGNAL(timeout()),this,SLOT(disconnectAndStopTimer2Slot()));
            timer2.start(30);
            moveTimer2IsOn = true;
        }
        else
        {
            break;
        }
        if(!(check_map_edges(south))) break;
        tankDirection=south;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.ry() += 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        emit messageSignal(info);
        break;

   case Qt::Key_Space:
//       if(timer.isActive())break;
//       bullet.setBullet(tankDirection,coordinateX,coordinateY);
//       connect(&timer,SIGNAL(timeout()),this,SLOT(shoot()));
//       timer.start(18);
        if(shootTimerIsOn == false)
        {
            connect(&timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
            timer.start(2000);
            shootTimerIsOn = true;
        }
        else
        {
            break;
        }
       info.name=this->name;
       info.position = this->pos().toPoint();
       info.tankDirection = tankDirection;
       info.tankActivity = fired;
       emit messageSignal(info);
        break;
   }
variableResponsibleForKeepTheValueOfLastUsingQtKeyInKeyPressEventFunction=event->key();
}


bool TankModel::check_map_edges(direction dir)
{
    switch(dir)
    {
    case north:
        if(pos().y()<=(MAP_NORTH_EDGE+5)) return false;
        break;

    case south:
        if(pos().y()>=(MAP_SOUTH_EDGE-50)) return false;
        break;

    case west:
        if(pos().x()<=(MAP_WEST_EDGE+10)) return false;
        break;

    case east:
        if(pos().x()>=(MAP_EAST_EDGE-50)) return false;
        break;

    }
    return true;
}

void TankModel::shoot()
{
    bullet.moveBullet();
    if(bullet.checkEdges())
    {
        timer.stop();
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(shoot()));
    }

}
