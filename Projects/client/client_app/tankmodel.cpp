#include "tankmodel.h"
#include "logger.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent), rightEdge(795), leftEdge(-375),
    upEdge(-90), downEdge(495)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
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

void TankModel::keyPressEvent(QKeyEvent *event)
{
   switch(event->key())
   {
   case Qt::Key_Right:
        setRotation(90);
        if(!(check_map_edges(east))) break;
        tankDirection=east;
        setTransformOriginPoint(20,25);

        moveBy(5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();

        break;

   case Qt::Key_Left:
        setRotation(270);
        if(!(check_map_edges(west))) break;
        tankDirection=west;
        setTransformOriginPoint(20,25);
        moveBy(-5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();
        break;


   case Qt::Key_Up:
        setRotation(0);
        tankDirection=north;
        if(!(check_map_edges(north))) break;
        setTransformOriginPoint(20,25);
        moveBy(0,-5);
        coordinateX=pos().x();
        coordinateY=pos().y();
        break;


   case Qt::Key_Down:
        setRotation(180);
        if(!(check_map_edges(south))) break;
        tankDirection=south;
        setTransformOriginPoint(20,25);
        moveBy(0,5);
        coordinateX=pos().x();
        coordinateY=pos().y();

        break;

   case Qt::Key_Space:
        shoot();
		break;
   }
}


bool TankModel::check_map_edges(direction dir)
{
    switch(dir)
    {
    case north:
        if(coordinateY==upEdge) return false;
        break;

    case south:
        if(coordinateY==downEdge) return false;
        break;

    case west:
        if(coordinateX==leftEdge) return false;
        break;

    case east:
        if(coordinateX==rightEdge) return false;
        break;

    }
    return true;
}

void TankModel::shoot()
{

    //bullet = new Ball;
   // bullet->moveBullet(tankDirection,coordinateX,coordinateY);
    //pointerToBattleItemsCointainer->addItem(bullet);
    //delete bullet;

}
