#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsItem>
#include <QGraphicsView>


class background: public QGraphicsItem
{
public:
    background(QGraphicsItem *parent = NULL);
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BACKGROUND_H
