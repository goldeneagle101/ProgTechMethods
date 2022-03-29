#include <QCoreApplication>
#include "LogiFirm_Server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    LogiFirmServer LogiFirm_server;  // создание сервера
    return a.exec();
}
