#include <QtTest>
#include "P:/project_QT/abc/latest_version/Server_Functions.h"
// add necessary includes here

DataBase * DataBase::p_instance;
DataBaseDestroyer DataBase::destroyer;

QSqlDatabase DataBase::db;

class test_qt : public QObject
{
    Q_OBJECT

public:
    test_qt();
    ~test_qt();

private slots:
    void test_Tatarchuk();
    void test_Dvorkin();
    void text_Serdykova();
    void text_Saymanova();

};

test_qt::test_qt()
{

}

test_qt::~test_qt()
{

}

void test_qt::test_Tatarchuk()
{
    QString input = "auth d d d d d d d d ";
    QString output = "error (incorrect number of parameters during authorization).\n";
    QString received = parsing(input, 555);
    QCOMPARE(output, received);
}

void test_qt::test_Dvorkin()
{
    QString input = "itjustquery";
    QString output = "error SERVER_FUNCTIONS\n";
    QString received = parsing(input, 555);
    QCOMPARE(output, received);
}

void test_qt::text_Serdykova()
{
    DataBase::getInstance();
    QString output = "True";
    QString received = DataBase::active_user("admin","1",12);
    QCOMPARE(output, received);
}

void test_qt::text_Saymanova()
{
    DataBase::getInstance();
    // происходит проверка возвращаемого кода идентификатора
    QString output = "/ans1005";
    QString received = example("1");
    received = received.left(8);
    QCOMPARE(output, received);
}

QTEST_APPLESS_MAIN(test_qt)

#include "tst_test_qt.moc"
