#include "tankmodel.h"

TankModel::TankModel(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
}

QRectF TankModel::boundingRect() const
{
    return QRectF(0,0,70,70);

}

void TankModel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(10,10, QPixmap(":/Graphics/tank1.png"));
}

void TankModel::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Right:

        moveBy(5,0);
        break;


    case Qt::Key_Left:

        moveBy(-5,0);
        break;


    case Qt::Key_Up:

        moveBy(0,-5);
        break;


    case Qt::Key_Down:
        moveBy(0,5);
        break;
    }

}
