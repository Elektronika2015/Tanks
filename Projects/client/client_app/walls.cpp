#include "walls.h"

Walls::Walls(QGraphicsItem *parent): QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setVisible(true);
}

QRectF Walls::boundingRect() const
{
    return QRectF(0,0,160,60);

}

void Walls::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, QPixmap(":/Graphics/wall.png"));
}
