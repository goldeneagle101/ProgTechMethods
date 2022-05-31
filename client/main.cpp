#include "mainwindow.h"
#include "Client.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>


Client * Client::p_instance=0;
ClientDestroyer Client::destroyer;
QTcpSocket * Client::mTcpSocket;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // w.show();  // отображение главного окна
    return a.exec();
}
