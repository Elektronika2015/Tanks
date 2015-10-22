#include <QCoreApplication>
#include <QObject>
#include "tcpserver.h"
#include "client.h"
#include <iostream>
#include <QString>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    st s;
//    s.run();
//    server serv(0);
//    if(serv.run(RUN_ON_LOCALHOST))
//        return 0;

//    TCPserver serv;
//    serv.startServer();
//    int listen = serv.isListening();
//    std::string ax;
//    std::cin>>ax;
//    if(ax == "ok")
    {
        client c;
        c.connectToServer("127.0.0.1",QString::number(1237));
        c.updatePosition();
    }

    return a.exec();
}

