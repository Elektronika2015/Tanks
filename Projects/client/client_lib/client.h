#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "client_lib.h"
#include "common_codes.h"

class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    int connectToServer(QString address, QString port);
    int updatePosition();
private:

    QString address,port;
    QTcpSocket socket;
private slots:
    void readyRead();
};

#endif // CLIENT_H
