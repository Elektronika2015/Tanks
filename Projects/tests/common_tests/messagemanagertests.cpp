#include "autotest.h"
#include "messagemanager.h"


class mock_messageManager: public messageManager
{
public:
    static int run_createDefaultPartOfMessage(activity tankActivity, QPoint position, direction tankDirection, QString name, QString& dst)
    {
        return createDefaultPartOfMessage(tankActivity,position,tankDirection,name,dst);
    }

    static int run_createTypeMarkerFront(QString type, QString &dst)
    {
        return createTypeMarkerFront(type, dst);
    }

    static int run_createTypeMarkerEnd(QString type, QString &dst)
    {
        return createTypeMarkerEnd(type, dst);
    }
};

class messageManagerTests: public QObject
{
    Q_OBJECT
private slots:
    void test_createDefaultPartOfMessage();
    void test_createTankMovedMessage();
    void test_createTankFiredMessage();
    void test_createTankDestroyedShownMessage();
    void test_createTankJoinedMessage();
    void test_createTankLeftMessage();
    void test_parseMessage();
    void test_parseMultipleMessages();
};



void messageManagerTests::test_createDefaultPartOfMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;

    mock_messageManager mmm;
    //moved activity
    {
        int result = mmm.run_createDefaultPartOfMessage(moved,position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(MOVED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }

    //fired activity
    {
        int result = mmm.run_createDefaultPartOfMessage(fired,position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(FIRED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }

    //joined activity
    {
        int result = mmm.run_createDefaultPartOfMessage(joined,position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(JOIN_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }

    //left game activity
    {
        int result = mmm.run_createDefaultPartOfMessage(leftGame,position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(LEFT_GAME_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }

    //destroyed activity
    {
        int result = mmm.run_createDefaultPartOfMessage(tankDestroyed,position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(DESTROYED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_createTankMovedMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;
    {
        int result = messageManager::createTankMovedMessage(position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(MOVED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_createTankFiredMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;
    {
        int result = messageManager::createTankFiredMessage(position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(FIRED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_createTankDestroyedShownMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;
    {
        int result = messageManager::createTankDestroyedMessage(position,tankDirection,name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(DESTROYED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_createTankJoinedMessage()
{

    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;
    {
        int result = messageManager::createPlayerJoinedMessage(name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(JOIN_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_createTankLeftMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;


    QString dst;
    {
        int result = messageManager::createPlayerLeftGameMessage(name,dst);
        QCOMPARE(result,0);

        QString compare = "[name]player name[/name][what]"+QString(LEFT_GAME_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        QCOMPARE(dst,compare);
    }
}

void messageManagerTests::test_parseMessage()
{
    //joined
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(JOIN_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        messageManager::parseMessage(message,result);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,joined);
    }

    //leftgame
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(LEFT_GAME_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        messageManager::parseMessage(message,result);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,leftGame);
    }

    //moved
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(MOVED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        int res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,moved);
        QCOMPARE(result.position,QPoint(1,1));
        QCOMPARE(result.tankDirection,north);


        message = "[name]xyz[/name][what]"+QString(MOVED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]west[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("xyz"));
        QCOMPARE(result.tankActivity,moved);
        QCOMPARE(result.position,QPoint(666,666));
        QCOMPARE(result.tankDirection,west);


        message = "[name]xyz[/name][what]"+QString(MOVED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]bad_direction[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,1);
    }

    //fired
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(FIRED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        int res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,fired);
        QCOMPARE(result.position,QPoint(1,1));
        QCOMPARE(result.tankDirection,north);


        message = "[name]xyz[/name][what]"+QString(FIRED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]west[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("xyz"));
        QCOMPARE(result.tankActivity,fired);
        QCOMPARE(result.position,QPoint(666,666));
        QCOMPARE(result.tankDirection,west);


        message = "[name]xyz[/name][what]"+QString(FIRED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]bad_direction[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,1);
    }

    //destroyed
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(DESTROYED_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        int res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,tankDestroyed);
        QCOMPARE(result.position,QPoint(1,1));
        QCOMPARE(result.tankDirection,north);


        message = "[name]xyz[/name][what]"+QString(DESTROYED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]west[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("xyz"));
        QCOMPARE(result.tankActivity,tankDestroyed);
        QCOMPARE(result.position,QPoint(666,666));
        QCOMPARE(result.tankDirection,west);


        message = "[name]xyz[/name][what]"+QString(DESTROYED_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]bad_direction[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,1);
    }


    //shown
    {
        QString message;
        standardTankInfo result;
        message = "[name]player name[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";

        int res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("player name"));
        QCOMPARE(result.tankActivity,shown);
        QCOMPARE(result.position,QPoint(1,1));
        QCOMPARE(result.tankDirection,north);


        message = "[name]xyz[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]west[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,0);
        QCOMPARE(result.name,QString("xyz"));
        QCOMPARE(result.tankActivity,shown);
        QCOMPARE(result.position,QPoint(666,666));
        QCOMPARE(result.tankDirection,west);


        message = "[name]xyz[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]bad_direction[/dire]";
        res = messageManager::parseMessage(message,result);
        QCOMPARE(res,1);
    }
}

void messageManagerTests::test_parseMultipleMessages()
{
    QString message;
    QList<standardTankInfo> results;
    message = "[name]player name[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]1:1[/posi][dire]north[/dire]";
    message.append("[name]xyz[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]west[/dire]");
    int res = messageManager::parseMultipleMessages(message,results);
    QCOMPARE(res,-1);
    QCOMPARE(results[0].name,QString("player name"));
    QCOMPARE(results[0].tankActivity,shown);
    QCOMPARE(results[0].position,QPoint(1,1));
    QCOMPARE(results[0].tankDirection,north);

    QCOMPARE(results[1].name,QString("xyz"));
    QCOMPARE(results[1].tankActivity,shown);
    QCOMPARE(results[1].position,QPoint(666,666));
    QCOMPARE(results[1].tankDirection,west);

    results.clear();
    message.append("[name]xyz[/name][what]"+QString(SHOWN_ACTIVITY_STRING)+"[/what][posi]666:666[/posi][dire]bad_direction[/dire]");
    res = messageManager::parseMultipleMessages(message, results);
    QCOMPARE(res,2);
    QCOMPARE(results.count(),2);
    QCOMPARE(results[0].name,QString("player name"));
    QCOMPARE(results[0].tankActivity,shown);
    QCOMPARE(results[0].position,QPoint(1,1));
    QCOMPARE(results[0].tankDirection,north);

    QCOMPARE(results[1].name,QString("xyz"));
    QCOMPARE(results[1].tankActivity,shown);
    QCOMPARE(results[1].position,QPoint(666,666));
    QCOMPARE(results[1].tankDirection,west);

}

DECLARE_TEST(messageManagerTests)
#include "messagemanagertests.moc"
