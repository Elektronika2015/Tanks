#include "tankmodel.h"
#include "logger.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    name = "noname";
    tankDirection =north;
    setTransformOriginPoint(20,25);
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

    switch(event->key())
    {
    case Qt::Key_Right:
        setTankDirection(east);
        if(!(check_map_edges(east))) break;

        info.name=this->name;
        info.position = this->pos().toPoint();

        info.position.rx() += 5;

        info.tankDirection = tankDirection;
        info.tankActivity = moved;

        break;

   case Qt::Key_Left:
        setTankDirection(west);
        if(!(check_map_edges(west))) break;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.rx() -= 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        break;


   case Qt::Key_Up:
        setTankDirection(north);
        if(!(check_map_edges(north))) break;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.ry() -= 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        break;


   case Qt::Key_Down:
        setTankDirection(south);
        if(!(check_map_edges(south))) break;
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.position.ry() += 5;
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        break;

   case Qt::Key_Space:
//       if(timer.isActive())break;
//       bullet.setBullet(tankDirection,coordinateX,coordinateY);
//       connect(&timer,SIGNAL(timeout()),this,SLOT(shoot()));
//       timer.start(18);
       info.name=this->name;
       info.position = this->pos().toPoint();
       info.tankDirection = tankDirection;
       info.tankActivity = fired;
        break;
   }
    emit messageSignal(info);
}


bool TankModel::check_map_edges(direction dir)
{
    switch(dir)
    {
    case north:
        if(y()==(MAP_NORTH_EDGE+5)) return false;
        break;

    case south:
        if(y()==(MAP_SOUTH_EDGE-50)) return false;
        break;

    case west:
        if(x()==(MAP_WEST_EDGE+5)) return false;
        break;

    case east:
        if(x()==(MAP_EAST_EDGE-50)) return false;
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
