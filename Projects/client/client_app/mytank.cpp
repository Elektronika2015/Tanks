#include "mytank.h"

MyTank::MyTank(QGraphicsItem *parent):QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setTransformOriginPoint(20,25);
}


QRectF MyTank::boundingRect() const
{
    return QRectF(0,0,40,50);
}

void MyTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,QPixmap(":/Graphics/tank1.png"));
}

void MyTank::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:

        break;

    case Qt::Key_Left:

        break;

    case Qt::Key_Up:

        break;

    case Qt::Key_Down:

        break;


    }
}

void MyTank::updateCoordinates(QPoint coordinates, direction dir)
{
    tankPos=coordinates;
    tankDirection=dir;
}

void MyTank::setStartupParameters(QString playerName, QPoint startPos, direction startDirection)
{
    name=playerName;
    tankPos=startPos;
    tankDirection=startDirection;
}
