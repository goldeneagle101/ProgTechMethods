#ifndef LOGIFIRM_SERVER_H
#define LOGIFIRM_SERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>

class LogiFirmServer : public QObject
{
    Q_OBJECT
public:
    explicit LogiFirmServer(QObject *parent = nullptr);
    ~LogiFirmServer();
public slots:
    void slotClientConnected();
    void slotClientDisconnected();

    void slotServerRead();


private:
    QVector<QTcpSocket*> multiple_sockets;  // массив сокетов
    QTcpServer * Server;  // сервер
    QTcpSocket * Socket;  // сокет
    int server_status;  // статус сервера

    // переменные для работы с чтением на сервере
    QByteArray read_array;  // массив для считывания
    QString result_Server_Read;  // результат чтения сервера
};
#endif // LOGIFIRM_SERVER_H







