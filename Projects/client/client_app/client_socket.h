#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <QObject>

class client_socket : public QObject
{
    Q_OBJECT
public:
    explicit client_socket(QObject *parent = 0);

signals:

public slots:
};

#endif // CLIENT_SOCKET_H
