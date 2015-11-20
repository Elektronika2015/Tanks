#include "enemytank.h"

EnemyTank::EnemyTank(QGraphicsItem*parent, QPoint coords):
    QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    this->setPos(coords);
}

QRectF EnemyTank::boundingRect() const
{
    return QRectF(0,0,40,50); //edges of Tank

}

void EnemyTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, QPixmap(":/Graphics/tank1.png"));
}

