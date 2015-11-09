#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include "client_lib.h"
#include "common_codes.h"
#include "logger.h"

class client_socket : public QObject
{
    Q_OBJECT
public:
    explicit client_socket(QObject *parent = 0);

    void connectToServer(QString address, QString port, QString name);
    int writeToServer(QString data);
private:
    QTcpSocket socket;
    QString playerName;
    bool firstConnection;
public slots:
    void connected();
    void disconnected();
    void readyRead();
    void bytesWritten(qint64 bytes);

signals:
    void nameAlreadyExists();
    void connectionAccepted();
    void serverSendMessage(QString data);
};

#endif // CLIENT_SOCKET_H
