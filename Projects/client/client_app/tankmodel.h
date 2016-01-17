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
    Ball bullet;
    TankModel(QGraphicsItem *parent =NULL);
    messageManager messenger;
    bool check_map_edges(direction dir);

    QRectF boundingRect() const;
    virtual void keyPressEvent(QKeyEvent *event);



    QString getName() const;
    void setName(const QString &value);
    void setPosition(standardTankInfo info);
    void setTankDirection(direction dir);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QTimer timer;
    QString name;
    bool moveTimerIsOn;
private slots:
    void shoot();
    void timerSlot()
    {
        timer.stop();
        disconnect(&timer,SIGNAL(timeout()),this,SLOT(timerSlot()));
        moveTimerIsOn = false;
    }

signals:
    void sendMessage(QString data);
    void messageSignal(standardTankInfo info);

};

#endif // TANKMODEL_H
