#include "autotest.h"
#include "common_codes.h"


class commonTests: public QObject
{
    Q_OBJECT
private slots:
    void test_qPointToByteArray();
    void test_byteArrayToQPoint();
    void test_makeNewPositionMSG();
    void test_getPosStringFromData();
    void test_directionToString();
    void test_activityToString();

    void test_randomNumbers();
};




void commonTests::test_qPointToByteArray()
{
    for(int i = 0, k = 99;i < 100; i++, k--)
    {
        QPoint point(i,k);
        QByteArray data;
        qPointToByteArray(point,data);


        QString tmp = QString::number(i) + ":" + QString::number(k);
        QByteArray compare = tmp.toStdString().c_str();
        QCOMPARE(compare, data);
    }

    //test for null
    {
        QPoint point;
        QByteArray data;
        QCOMPARE(qPointToByteArray(point,data),1);
    }

    //test for negative values
    {
        QPoint point(-1,-1);
        QByteArray data;
        QCOMPARE(qPointToByteArray(point,data),1);
    }

    //test for large values.
    {
        QPoint point(999,666);
        QByteArray data;
        qPointToByteArray(point,data);
        QByteArray compare = "999:666";
        QCOMPARE(data,compare);
    }

}

void commonTests::test_byteArrayToQPoint()
{
    for(int i = 0, k = 99; i<100; i++,k--)
    {
        QByteArray data;
        QString tmp = QString::number(i) +":"+ QString::number(k);
        data = tmp.toStdString().c_str();
        QPoint point;
        QCOMPARE(byteArrayToQPoint(data,point),0);

        QPoint compare(i,k);
        QCOMPARE(point,compare);
    }

    //test for null
    {
        QPoint point;
        QByteArray data;
        QCOMPARE(qPointToByteArray(point,data),1);
    }
}

void commonTests::test_makeNewPositionMSG()
{
    //test if correctly creates message
    {
        for(int i = 0; i<100; i++)
        {
            QPoint point(1,i);
            QByteArray test, compare;

            compare = "NEW_POS1:";
            compare.append(QString::number(i));

            QCOMPARE(makeNewPositionMSG(point,test),0);
            QCOMPARE(test, compare);
        }
    }

    //test for null
    {
        QPoint point;
        QByteArray data;
        QCOMPARE(makeNewPositionMSG(point,data),1);
    }

    //test for negative values
    {
        QPoint point(-1,-1);
        QByteArray data;
        QCOMPARE(makeNewPositionMSG(point,data),1);
    }

}

void commonTests::test_getPosStringFromData()
{
    //test if correctly retrieves position string
    {
        for(int i = 0; i<100; i++)
        {
            QPoint point(1,i);
            QByteArray test, compare;

            compare = "NEW_POS1:";
            compare.append(QString::number(i));

            QCOMPARE(makeNewPositionMSG(point,test),0);
            QCOMPARE(test, compare);

            QByteArray positionCompare = "1:", positionTest;
            positionCompare.append(QString::number(i));

            QCOMPARE(getPosStringFromData(test,positionTest),0);
            QCOMPARE(positionTest, positionCompare);
        }
    }
}

void commonTests::test_directionToString()
{
    QString compare;

    //north
    {
        QString dst;
        compare="north";
        QCOMPARE(0,directionToString(north,dst));
        QCOMPARE(compare,dst);
    }

    //east
    {
        QString dst;
        compare="east";
        QCOMPARE(0,directionToString(east,dst));
        QCOMPARE(compare,dst);
    }

    //south
    {
        QString dst;
        compare="south";
        QCOMPARE(0,directionToString(south,dst));
        QCOMPARE(compare,dst);
    }

    //west
    {
        QString dst;
        compare="south";
        QCOMPARE(0,directionToString(south,dst));
        QCOMPARE(compare,dst);
    }

}

void commonTests::test_activityToString()
{
    //join
    {
        QString compare, dst;
        compare=JOIN_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(joined,dst));
        QCOMPARE(compare,dst);
    }

    //leftGame
    {
        QString compare, dst;
        compare=LEFT_GAME_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(leftGame,dst));
        QCOMPARE(compare,dst);
    }


    //moved
    {
        QString compare, dst;
        compare=MOVED_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(moved,dst));
        QCOMPARE(compare,dst);
    }


    //fired
    {
        QString compare, dst;
        compare=FIRED_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(fired,dst));
        QCOMPARE(compare,dst);
    }


    //destroyed
    {
        QString compare, dst;
        compare=DESTROYED_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(tankDestroyed,dst));
        QCOMPARE(compare,dst);
    }


    //shown
    {
        QString compare, dst;
        compare=SHOWN_ACTIVITY_STRING;
        QCOMPARE(0,activityToString(shown,dst));
        QCOMPARE(compare,dst);
    }



}

void commonTests::test_randomNumbers()
{
    qsrand(QTime::currentTime().msec());
    int x,y;
    for(int i = 0; i<10,000 ; i++)
    {
        x = rand()%MAP_EAST_EDGE + MAP_WEST_EDGE;
        y =rand()%MAP_NORTH_EDGE + MAP_SOUTH_EDGE;
        QCOMPARE(x >= MAP_WEST_EDGE,true);
        QCOMPARE(x <= MAP_EAST_EDGE,true);
        QCOMPARE(x >= MAP_NORTH_EDGE,true);
        QCOMPARE(x <= MAP_SOUTH_EDGE,true);
    }
}

DECLARE_TEST(commonTests)
#include "commontests.moc"

