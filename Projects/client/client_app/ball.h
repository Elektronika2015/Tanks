#ifndef BALL_H
#define BALL_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include "common_codes.h"
#include "logger.h"

class Ball: public QGraphicsItem
{


public:
    Ball(QGraphicsItem *parent, QString _bulletName, QString _shooterName);
    Ball(QGraphicsItem *parent = NULL);
    QRectF boundingRect() const;
    QString bulletName, shooterName;

    void setBullet(direction dir, int x, int y);
    void moveMe(QPoint p);


    void moveBullet();
    bool checkEdges();

    QString getBulletName() const;

    QString getShooterName() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
   direction ballDirection;
   int ballCoordinateX;
   int ballCoordinateY;

   void updateBallCoordinates();


};

#endif // BALL_H
