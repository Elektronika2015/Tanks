#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include "common_codes.h"

class Ball: public QGraphicsItem
{


public:
    Ball(QGraphicsItem *parent =NULL);
    QRectF boundingRect() const;

    void setBullet(direction dir, int x, int y);
    void moveBullet();
    bool checkEdges();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
   direction ballDirection;
   int ballCoordinateX;
   int ballCoordinateY;

   void updateBallCoordinates();


};

#endif // BALL_H
