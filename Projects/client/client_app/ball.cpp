#include "ball.h"
#include "logger.h"
Ball::Ball(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setVisible(false);
    logger::setLogToqDebug(true);

}

QRectF Ball::boundingRect() const
{
    return QRectF(0,0,20,20); //edges of bullet

}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    painter->drawPixmap(18,0, QPixmap(":/Graphics/ball.png"));

}

void Ball::moveBullet(direction dir, int x, int y)
{
    logger::log(("strzal"));
    setVisible(true);
    switch(dir)
    {
    case tank_up:
         setPos(x+20,y);
         break;
    case tank_down:
         setPos(x+20,y+50);
         break;
    case tank_left:
         setPos(x-25,y+20);
         break;

    case tank_right:
         setPos(x+50,y+20);

        break;
    }


}
