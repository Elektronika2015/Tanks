#ifndef ENEMYTANK_H
#define ENEMYTANK_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QPoint>
#include "ball.h"
#include "common_codes.h"

class EnemyTank: public QGraphicsItem
{

public:

    direction tankDirection;
    int coordinateX;
    int coordinateY;
    Ball bullet;
    EnemyTank(QGraphicsItem *parent =NULL, QPoint coords = QPoint(0,0));
    bool check_map_edges(direction dir);

    QRectF boundingRect() const;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    //QTimer timer;
private slots:
    void shoot();

signals:
    void sendMessage(QString data);

};

#endif // TANKMODEL_H
