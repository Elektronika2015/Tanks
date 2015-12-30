#ifndef WALLS_H
#define WALLS_H

#include <QGraphicsItem>
#include <QGraphicsView>
class Walls: public QGraphicsItem
{
public:
    Walls(QGraphicsItem *parent =NULL);
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WALLS_H
