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


    painter->drawPixmap(0,0, QPixmap(":/Graphics/ball.png"));

}

void Ball::updateBallCoordinates()
{
    ballCoordinateX=pos().x();
    ballCoordinateY=pos().y();
}

void Ball::moveBullet()
{
    switch(ballDirection)
    {
    case north:
        moveBy(0,-10);
        updateBallCoordinates();
        break;

    case south:
        moveBy(0,10);
        updateBallCoordinates();
        break;

    case east:
        moveBy(10,0);
        updateBallCoordinates();
        break;

    case west:
        moveBy(-10,0);
        updateBallCoordinates();
        break;
    }




}

bool Ball::checkEdges()
{
    if((ballCoordinateX >= MAP_EAST_EDGE) || (ballCoordinateX <= MAP_WEST_EDGE) || (ballCoordinateY<=MAP_NORTH_EDGE) || (ballCoordinateY >= MAP_SOUTH_EDGE))
    {
        logger::log(QVariant(ballCoordinateX).toString());
        logger::log(" ");
        logger::log(QVariant(ballCoordinateY).toString());
        setVisible(false);
        return true;

    }

    else return false;
}

void Ball::setBullet(direction dir, int x, int y)
{
    setVisible(true);
    ballDirection=dir;
    switch(dir)
    {
    case north:
         setPos(x+20,y);
         updateBallCoordinates();
         break;
    case south:
         setPos(x+20,y+50);
         updateBallCoordinates();
         break;
    case west:
         setPos(x-25,y+20);
         updateBallCoordinates();
         break;

    case east:
         setPos(x+50,y+20);
         updateBallCoordinates();
        break;
    }


}
