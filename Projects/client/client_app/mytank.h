#ifndef MYTANK_H
#define MYTANK_H

#include <QPoint>
#include <QGraphicsView>
#include <QKeyEvent>
#include <ball.h>
#include <common_codes.h>



class MyTank:public QGraphicsItem
{
private:
    QPoint tankPos;
    direction tankDirection;
    Ball bullet;
    QString name;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void keyPressEvent(QKeyEvent *event);
public:
    MyTank(QGraphicsItem *parent =NULL);
    void updateCoordinates(QPoint coordinates, direction dir);
    void setStartupParameters(QString playerName, QPoint startPos, direction startDirection);

signals:

public slots:
};

#endif // MYTANK_H
