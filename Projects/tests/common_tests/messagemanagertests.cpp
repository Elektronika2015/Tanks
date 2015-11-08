#include "autotest.h"
#include "messagemanager.h"


class mock_messageManager: public messageManager
{
public:
    static int run_createDefaultPartOfMessage(QString what, QPoint position, direction tankDirection, QString name, QString& dst)
    {
        return createDefaultPartOfMessage(what,position,tankDirection,name,dst);
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
};



void messageManagerTests::test_createDefaultPartOfMessage()
{
    QString name("player name");
    QPoint position(1,1);
    direction tankDirection = north;
    QString what("moved");

    QString dst;

    mock_messageManager mmm;
    int result = mmm.run_createDefaultPartOfMessage(what,position,tankDirection,name,dst);
    QCOMPARE(result,0);

    QString compare = "[name]player name[/name][what]moved[/what][position]1:1[/position][direction]north[/direction]";

    QCOMPARE(dst,compare);
}

DECLARE_TEST(messageManagerTests)
#include "messagemanagertests.moc"
