#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QNetworkInterface>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //TCPserver serv;
    //serv.startServer();
    static MainWindow w;
    w.show();
    //qInstallMessageHandler(redirectQMessages);
//    TCPserver serv;
//    serv.startServer();
//    //serv.run(RUN_ON_LOCALHOST);
//    QString port = serv.getServerPort();

//    QHostAddress address = serv.getServerAddress();
//    logger::log(port);
//    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
//             qDebug() << address.toString();
//    }

    a.exec();
    return 0;
}
