//#include <QString>
//#include <QtTest>
//#include "autotest.h"
//#include "taskfactory.h"


//class mockTaskFactory: public taskFactory
//{
//private:
//    TCPserver serv;
//public:
//    mockTaskFactory()
//        :taskFactory(&serv)
//    {/*...*/}

//    int do_parseData(QString data)
//    {
//        return parseData(data);
//    }
//};


//class taskFactoryTests : public QObject
//{
//    Q_OBJECT

//public:
//    taskFactoryTests();

//private:
//    player_client client;
//    TCPserver server;
//private Q_SLOTS:
//    void test_createTask();
//    void test_parseData();
//};




//taskFactoryTests::taskFactoryTests()
//{
//    //client.setSocket(0);

//    //server.firstConnectionRequest("pierwszy",&client);
//}

//void taskFactoryTests::test_createTask()
//{
//    taskFactory factory(&server);

//    QRunnable* task = factory.createTask(NEW_POSITION_TXT,client.getName());

//    QCOMPARE(dynamic_cast<notifyClientsTask*>(task) != NULL, 1);
//}

//void taskFactoryTests::test_parseData()
//{
//    mockTaskFactory mock;

//    //test for good data
//    QCOMPARE(mock.do_parseData(NEW_POSITION_TXT),1);

//    //test for wrong data
//    QCOMPARE(mock.do_parseData("asdkjdklja"),-1);
//}

//DECLARE_TEST(taskFactoryTests)
//#include "taskfactorytests.moc"
