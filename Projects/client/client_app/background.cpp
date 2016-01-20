#include "background.h"



background::background(QGraphicsItem *parent)
: QGraphicsItem(parent)
{
    setPos(-375,-90);
    setVisible(true);
}

QRectF background::boundingRect() const
{
    return QRectF(0,0,1170,585);
}

void background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, QPixmap(":/Graphics/background.png"));
}

