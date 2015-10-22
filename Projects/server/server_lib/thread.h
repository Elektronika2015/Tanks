#ifndef THREAD_H
#define THREAD_H
#include <server_lib.h>
#include "logger.h"
#include "common_codes.h"
#include <QThread>
#include <QTcpSocket>
#include <QPoint>
#include <QByteArray>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QTcpSocket *sock,QString player_name, QObject *parent = 0);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
    void updatePosition(QPoint pos, QString playerName);

public slots:
    void firstConnection();
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    QString playerName;
};

#endif // THREAD_H
