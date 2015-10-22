#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QTest>
#include <QList>
#include <QString>
#include <QSharedPointer>
#include <QDebug>
#include <QThread>

namespace AutoTest
{
    typedef QList<QObject*> TestList;
    static QStringList fails;

    inline TestList& testList()
    {
        static TestList list;
        return list;
    }

    inline QStringList getNames()
    {
        static QStringList names;
        return names;
    }

    inline bool findObject(QObject* object)
    {
        TestList& list = testList();
        if (list.contains(object))
        {
            return true;
        }
        foreach (QObject* test, list)
        {
            if (test->objectName() == object->objectName())
            {
                return true;
            }
        }
        return false;
    }

    inline void addTest(QObject* object)
    {
        TestList& list = testList();
        if (!findObject(object))
        {
            list.append(object);
        }
    }

    inline int run(int argc, char *argv[])
    {
        int ret = 0;
        int i = 0;
        int count = 0;

        foreach (QObject* test, testList())
        {
            int result = QTest::qExec(test, argc, argv);
            if(result != 0)
            {
                fails.append(AutoTest::getNames().value(i));
            }
            ret += result;
            i++, count++;
        }

        if (ret == 0)
        {
            QThread::msleep(500);
            qDebug() << "ALL " << count << "    CLASS TESTS PASSED";
        }
        else
        {
            QThread::msleep(500);
            qDebug() << ret << " TESTS FAILED!";
            qDebug() << "following tests have failed: \n";
            for(int i = 0; i < fails.length(); i++)
                qDebug() << fails.value(i) << "\n";
        }
        return ret;
    }
}

template <class T>
class Test
{
public:
    QSharedPointer<T> child;

    Test(const QString& name) : child(new T)
    {
        AutoTest::getNames().append(name);
        child->setObjectName(name);
        AutoTest::addTest(child.data());
    }
};

#define DECLARE_TEST(className) static Test<className> t(#className);

#define TEST_MAIN \
    int main(int argc, char *argv[]) \
{ \
    return AutoTest::run(argc, argv); \
    }



//#include <QString>
//#include <QtTest>
//#include "autotest.h"

//class tests : public QObject
//{
//    Q_OBJECT

//public:
//    tests();



//private Q_SLOTS:
//};


//DECLARE_TEST(tests)
//#include "tests.moc"


#endif // AUTOTEST_H
