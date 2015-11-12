#include "tankmodel.h"
#include "logger.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent), rightEdge(795), leftEdge(-375),
    upEdge(-90), downEdge(495)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    tankDirection =tank_up;
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
        if(!(check_map_edges(tank_right))) break;
        tankDirection=tank_right;
        setTransformOriginPoint(20,25);
        moveBy(5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();

        break;



   case Qt::Key_Left:
        setRotation(270);
        if(!(check_map_edges(tank_left))) break;
        tankDirection=tank_left;
        setTransformOriginPoint(20,25);
        moveBy(-5,0);
        coordinateX=pos().x();
        coordinateY=pos().y();
        break;


   case Qt::Key_Up:
        setRotation(0);
        tankDirection=tank_up;
        if(!(check_map_edges(tank_up))) break;
        setTransformOriginPoint(20,25);
        moveBy(0,-5);
        coordinateX=pos().x();
        coordinateY=pos().y();
        break;


   case Qt::Key_Down:
        setRotation(180);
        if(!(check_map_edges(tank_down))) break;
        tankDirection=tank_down;
        setTransformOriginPoint(20,25);
        moveBy(0,5);
        coordinateX=pos().x();
        coordinateY=pos().y();
        break;

   case Qt::Key_Space:
        shoot();

   case Qt::Key_M:
       delete bullet;


     break;

 }

}


bool TankModel::check_map_edges(direction dir)
{
    switch(dir)
    {
    case tank_up:
        if(coordinateY==upEdge) return false;
        break;

    case tank_down:
        if(coordinateY==downEdge) return false;
        break;

    case tank_left:
        if(coordinateX==leftEdge) return false;
        break;

    case tank_right:
        if(coordinateX==rightEdge) return false;
        break;

    }
    return true;
}

void TankModel::shoot()
{

    bullet = new Ball;
    bullet->moveBullet(tankDirection,coordinateX,coordinateY);
    //pointerToBattleItemsCointainer->addItem(bullet);
    //delete bullet;


}
