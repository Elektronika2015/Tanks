#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include "common_codes.h"
//enum direction{north,south,west,east};

class Ball: public QGraphicsItem
{
public:
    Ball(QGraphicsItem *parent =NULL);
    QRectF boundingRect() const;
    void moveBullet(direction dir,int x, int y);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BALL_H
