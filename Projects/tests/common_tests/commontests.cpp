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

DECLARE_TEST(commonTests)
#include "commontests.moc"

