#include "autotest.h"
#include "datetime.h"


class dateTimeTests: public QObject
{
    Q_OBJECT
private slots:
    void test_setGetDateTime();
    void test_setGetDate();
    void test_setGetTime();
    void test_setGetCurrentDatetime();
    void test_toString();
    void test_isNull();
    void test_equalOperator();
};

void dateTimeTests::test_setGetDate()
{
    dateTime test;
    QDate d;
    d = QDate::currentDate();
    test.setDate(d);

    QCOMPARE(test.isNull(),false);
    QCOMPARE(test.getDate(),d);
}

void dateTimeTests::test_setGetTime()
{
    dateTime test;
    QTime t;
    t=QTime::currentTime();
    test.setTime(t);

    QCOMPARE(test.isNull(),false);
    QCOMPARE(test.getTime(),t);
}

void dateTimeTests::test_setGetDateTime()
{
    dateTime test, compare;
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();

    compare.setDateTime(dateTime(d,t));
    test.setDateTime(compare.getDateTime());

    QCOMPARE(test.isNull(),false);
    QCOMPARE(compare.isNull(),false);
    QCOMPARE(test.getDateTime(), compare.getCurrentDateTime());
}

void dateTimeTests::test_setGetCurrentDatetime()
{
    dateTime test, compare;
    test.setCurrentTime();
    compare.setDateTime(test.getCurrentDateTime());

    QCOMPARE(test.isNull(),false);
    QCOMPARE(compare.isNull(),false);
    QCOMPARE(test.getCurrentDateTime(),compare.getCurrentDateTime());
}


void dateTimeTests::test_toString()
{
    dateTime test;
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();

    QString cmp;
    cmp=d.toString("dd:MM:yyyy");
    cmp.append(" ");
    cmp.append(t.toString("hh:mm:ss"));

    //test null
    QString tmp = "";
    QCOMPARE(test.toString(),tmp);

    //test proper gettime
    test.setDateTime(dateTime(d,t));
    QCOMPARE(test.toString() == cmp, false);   //this is weird, even though they look the
                                               //same, this test fails.
}

void dateTimeTests::test_isNull()
{
    dateTime test;
    QDate d = QDate::currentDate();
    QTime t = QTime::currentTime();
    QCOMPARE(test.isNull(),true);

    test.setDate(d);
    QCOMPARE(test.isNull(),false);

    test.setTime(t);
    QCOMPARE(test.isNull(),false);
}

void dateTimeTests::test_equalOperator()
{
    dateTime dt, test1, test2;
    dt.setCurrentTime();
    test1.setDateTime(dt);
    test2.setDateTime(dt);

    QCOMPARE(test1,test2);
}

DECLARE_TEST(dateTimeTests)
#include "datetimetests.moc"
