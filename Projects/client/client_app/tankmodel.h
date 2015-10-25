#ifndef TANKMODEL_H
#define TANKMODEL_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QKeyEvent>
class TankModel: public QGraphicsItem
{
public:
    virtual void keyPressEvent(QKeyEvent *event);

    TankModel(QGraphicsItem *parent =NULL);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

};

#endif // TANKMODEL_H
