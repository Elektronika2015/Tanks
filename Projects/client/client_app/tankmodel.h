#ifndef TANKMODEL_H
#define TANKMODEL_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "ball.h"
#include "common_codes.h"
#include <QGraphicsScene>
#include <QTimer>



class TankModel:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    direction tankDirection;
    int coordinateX;
    int coordinateY;
    Ball bullet;
    TankModel(QGraphicsItem *parent =NULL);
    bool check_map_edges(direction dir);

    QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QTimer timer;
private slots:
    void shoot();

};

#endif // TANKMODEL_H
