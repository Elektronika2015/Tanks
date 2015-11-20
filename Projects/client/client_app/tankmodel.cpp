#include "tankmodel.h"
#include "logger.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    name = "noname";
    tankDirection =north;
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


void TankModel::keyPressEvent(QKeyEvent *event)
{
    standardTankInfo info;

    switch(event->key())
    {
    case Qt::Key_Right:
        setRotation(90);
        tankDirection=east;
        if(!(check_map_edges(east))) break;
        setTransformOriginPoint(20,25);
        //moveBy(5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();

        info.name=this->name;
        info.position = this->pos().toPoint();
        info.tankDirection = tankDirection;
        info.tankActivity = moved;

        break;

   case Qt::Key_Left:
        setRotation(270);
        tankDirection=west;
        if(!(check_map_edges(west))) break;
        setTransformOriginPoint(20,25);
        //moveBy(-5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        break;


   case Qt::Key_Up:
        setRotation(0);
        tankDirection=north;
        if(!(check_map_edges(north))) break;
        setTransformOriginPoint(20,25);
        //moveBy(0,-5);
        coordinateX=pos().x();
        coordinateY=pos().y();
        info.name=this->name;
        info.position = this->pos().toPoint();
        info.tankDirection = tankDirection;
        info.tankActivity = moved;
        break;


   case Qt::Key_Down:
        setRotation(180);
        if(!(check_map_edges(south))) break;
        tankDirection=south;
        setTransformOriginPoint(20,25);
        //moveBy(0,5);
        coordinateX=pos().x();
        coordinateY=pos().y();
        info.name=this->name;
        info.position = this->pos().toPoint();
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
        if(coordinateY==(MAP_NORTH_EDGE+5)) return false;
        break;

    case south:
        if(coordinateY==(MAP_SOUTH_EDGE-50)) return false;
        break;

    case west:
        if(coordinateX==(MAP_WEST_EDGE+5)) return false;
        break;

    case east:
        if(coordinateX==(MAP_EAST_EDGE-50)) return false;
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
