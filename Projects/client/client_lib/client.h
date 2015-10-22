#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "client_lib.h"
#include "common_codes.h"

class CLIENT_LIBSHARED_EXPORT client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = 0);
    int connectToServer(QString address, QString port);
    int updatePosition();
private:
    QString address,port;
    QTcpSocket socket;

};

#endif // CLIENT_H
