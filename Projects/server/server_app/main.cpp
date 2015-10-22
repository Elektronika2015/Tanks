#include "mainwindow.h"
#include <QApplication>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    TCPserver serv;
    serv.startServer();
    //serv.run(RUN_ON_LOCALHOST);
    QString port = serv.getServerPort();
    logger::log(port);

    a.exec();
    return 0;
}
