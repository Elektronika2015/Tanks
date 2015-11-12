#ifndef TASKFACTORY_H
#define TASKFACTORY_H
#include <QRunnable>
#include "positionchangedtask.h"
#include "common_codes.h"
#include "logger.h"
#include "tcpserver.h"

class TCPserver;
class taskFactory
{
public:
    taskFactory(TCPserver *ptrToServer);

    QRunnable* createTask(QString data,QString name);

protected:
    TCPserver *server;

    int parseData(QString data);

    QRunnable *create_postionChangedTask(QString data, QString name);

    enum TASKS{
        position_changed_task = 1,
        player_disconnected_task,
        player_shooted,
        player_destroyed
    };
};

#endif // TASKFACTORY_H
