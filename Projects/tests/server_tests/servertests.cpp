//#include <QString>
//#include <QtTest>
//#include "autotest.h"
//#include "client.h"


////class mockServer:public server
////{
////public:
////    int runGetIPs(QList<QHostAddress> &returnList)
////    {
////        return getIPs(returnList);
////    }

////    int runGetLocalHost(QList<QHostAddress> list)
////    {
////        return getLocalhost(list);
////    }

////    int runGetHostIpAddress(QList<QHostAddress> list)
////    {
////        return getHostIpAddress(list);
////    }
////};

////class serverTests : public QObject
////{
////    Q_OBJECT

////public:
////    serverTests();



////private Q_SLOTS:
////    void test_getIps();
////    void test_getLocalHost();
////    void test_getHostIpAddress();
////    void test_run();
////};

////serverTests::serverTests()
////{
////    qApp->processEvents();
////}



////void serverTests::test_getIps()
////{
////    mockServer serv;
////    QList<QHostAddress> list;
////    int result = serv.runGetIPs(list);
////    QCOMPARE(result,0);
////}

////void serverTests::test_getLocalHost()
////{
////    mockServer serv;
////    QList<QHostAddress> list;
////    int result = serv.runGetIPs(list);
////    QCOMPARE(result,0);

////    int index = serv.runGetLocalHost(list);
////    Q_ASSERT(index != -1);
////    QCOMPARE(list[index].toString().toStdString().c_str(),"127.0.0.1");

////    //test empty list
////    {
////        mockServer serv;
////        QList<QHostAddress> list;
////        int index = serv.runGetLocalHost(list);
////        QCOMPARE(index,-1);
////    }


////}

////void serverTests::test_getHostIpAddress()
////{
////    mockServer serv;
////    QList<QHostAddress> list;
////    int result = serv.runGetIPs(list);
////    QCOMPARE(result,0);

////    int index = serv.runGetHostIpAddress(list);
////    Q_ASSERT(index != -1);
////    QCOMPARE(list[index].toString().toStdString().c_str() != "127.0.0.1", 1);

////    //test empty list
////    {
////        mockServer serv;
////        QList<QHostAddress> list;
////        int index = serv.runGetHostIpAddress(list);
////        QCOMPARE(index,-1);
////    }
////}

////void serverTests::test_run()
////{

////    server serv(this);
////    QCOMPARE(serv.run(RUN_ON_LOCALHOST),0);
////    qApp->processEvents();


////    client c;
////    qApp->processEvents();
////    c.connectToServer(serv.getServerAddress().toString(),serv.getServerPort());
////    qApp->processEvents();
////    c.updatePosition();
////    qApp->processEvents();

////}

//DECLARE_TEST(serverTests)
//#include "servertests.moc"
