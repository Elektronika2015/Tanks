#ifndef TANK_H
#define TANK_H
#include <QString>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include "tankmodel.h"


class Tank
{
private:

    int lifes;
    QString name;



public:
    Tank(QString playerName);
    /*
    void updateCoordinates(int x, int y)
    {
        coordinateX+=x;
        coordinateY+=y;
    }

    */
    void updateLife(int life ){lifes=life;}
    TankModel *czolg;



signals:

public slots:
};

#endif // TANK_H
