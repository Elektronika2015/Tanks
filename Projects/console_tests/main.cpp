#include <QCoreApplication>
#include <QObject>
#include "tcpserver.h"
#include "client.h"
#include <iostream>
#include <QString>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    QString test = "009";
//    int b = test.toInt();


    getchar();
    getchar();

    return a.exec();
}

