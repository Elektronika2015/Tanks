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
    Ball bullet;
    EnemyTank(QGraphicsItem *parent =NULL, QPoint coords = QPoint(0,0));

    QRectF boundingRect() const;
    void setPosition(standardTankInfo info);
    QString getName() const;
    void setName(const QString &value);
    void setTankDirection(direction dir);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QString name;

private slots:


signals:
    void sendMessage(QString data);

};

#endif // TANKMODEL_H
