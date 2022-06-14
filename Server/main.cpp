#include <QCoreApplication>
#include "LogiFirm_Server.h"
#include "database.h"

DataBase * DataBase::p_instance;
DataBaseDestroyer DataBase::destroyer;

QSqlDatabase DataBase::db;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LogiFirmServer LogiFirm_server;  // создание сервера
    return a.exec();
}
