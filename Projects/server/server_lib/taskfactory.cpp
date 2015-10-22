#include "taskfactory.h"

taskFactory::taskFactory(TCPserver *ptrToServer)
    :server(ptrToServer)
{

}

QRunnable *taskFactory::createTask(QString data, QString name)
{
    int task = parseData(data);
    switch(task)
    {
    case position_changed_task:
        return create_postionChangedTask(data, name);
    case player_disconnected_task:
        return create_postionChangedTask(data, name);
    default:
        return NULL;
    }
}

int taskFactory::parseData(QString data)
{
//    QString msg;
//    for(int i = 0;i<MSG_TXT_LENGTH; i++)
//        msg.append(data[i]);

    data.truncate(MSG_TXT_LENGTH);

    if(data == NEW_POSITION_TXT)
    {
        return position_changed_task;
    }
    else if(data == CLIENT_DISCONNECTED_TXT)
        return player_disconnected_task;
    else
        return -1;
}

QRunnable *taskFactory::create_postionChangedTask(QString data, QString name)
{
    positionChangedTask* task = new positionChangedTask(&(server->clients), data, name);
    task->setAutoDelete(true);

    return task;
}


