#include "positionchangedtask.h"

notifyClientsTask::notifyClientsTask(QMap<QString, player_client *> *clientsPTR, QString data, QString name)
    :clients(clientsPTR)
{
    this->data = data;
    this->name = name;
}

void notifyClientsTask::run()
{
    notifyClients();
}

void notifyClientsTask::notifyClients()
{
    QMapIterator<QString, player_client*> iter(*clients);
    for(int i = 0; i<clients->count(); i++)
    {
        //int result;

        iter.next();
        //logger l; l.log("Writing to " + iter.value()->getName());

//        //dont write to the sender!
//        if(iter.value()->getName() == name)
//            continue;

        //connect to clients slot
        connect(this,SIGNAL(write(QString)),iter.value()
                ,SLOT(write(QString)),Qt::QueuedConnection);

        //pass data to write to client socket
        emit write(data);

        //disconnect, so we wont write to this client again in this task.
        disconnect(this,SIGNAL(write(QString)),iter.value(),SLOT(write(QString)));
    }
}

