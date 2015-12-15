#include "enemytank.h"

EnemyTank::EnemyTank(QGraphicsItem*parent):
    QGraphicsItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setTransformOriginPoint(20,25);
}

QRectF EnemyTank::boundingRect() const
{
    return QRectF(0,0,40,50); //edges of Tank

}

void EnemyTank::setPosition(standardTankInfo info)
{
    setPos(info.position.x(),info.position.y());
    setTankDirection(info.tankDirection);
}

QString EnemyTank::getName() const
{
    return name;
}

void EnemyTank::setName(const QString &value)
{
    name = value;
}

void EnemyTank::setTankDirection(direction dir)
{
    switch(dir)
    {
        case east:
        setRotation(90);
        tankDirection=east;
        break;

    case west:
        setRotation(270);
        tankDirection=west;
        break;

    case north:
        setRotation(0);
        tankDirection=north;
        break;

    case south:
        setRotation(180);
        tankDirection=south;

        break;


    }
}

void EnemyTank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->drawPixmap(0,0, QPixmap(":/Graphics/tank1.png"));
}

