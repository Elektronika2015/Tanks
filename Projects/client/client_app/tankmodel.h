#ifndef TANKMODEL_H
#define TANKMODEL_H
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QKeyEvent>
#include "ball.h"
#include "common_codes.h"
#include "messagemanager.h"
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
    messageManager messenger;
    bool check_map_edges(direction dir);

    QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event);



    QString getName() const;
    void setName(const QString &value);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QTimer timer;
    QString name;
private slots:
    void shoot();
signals:
    void sendMessage(QString data);
    void messageSignal(standardTankInfo info);

};

#endif // TANKMODEL_H
