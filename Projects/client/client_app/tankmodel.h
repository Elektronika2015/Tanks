#ifndef TANKMODEL_H
#define TANKMODEL_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "ball.h"
#include <QGraphicsScene>


class TankModel: public QGraphicsItem
{
public:

    direction tankDirection;
    Ball * bullet;
    int coordinateX;
    int coordinateY;
    QGraphicsScene * pointerToBattleItemsCointainer;
    TankModel(QGraphicsItem *parent =NULL);
    bool check_map_edges(direction dir);
    void shoot();
    QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    const int rightEdge;
    const int leftEdge;
    const int upEdge;
    const int downEdge;


};

#endif // TANKMODEL_H
