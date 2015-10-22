#ifndef TASK_H
#define TASK_H
#include <QObject>
#include <QRunnable>
#include "logger.h"
#include "player_client.h"

class player_client;

class positionChangedTask :public QObject, public QRunnable
{
    Q_OBJECT
public:
    positionChangedTask(QMap<QString, player_client*>* clientsPTR, QString data, QString name);

signals:
    void Result(int Number);

    void write(QString data);

protected:
    void run();

    virtual void notifyClients();

    QMap<QString, player_client*>*  clients;
    QString data, name;
};

#endif // TASK_H
