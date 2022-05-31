#ifndef CLIENT_H
#define CLIENT_H
#pragma once

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QObject>
#include <QTcpSocket>
#include "functionsforclient.h"

class Client;

class ClientDestroyer
{
    private:
        Client * p_instance;
    public:
        ~ClientDestroyer() { delete p_instance;}
        void initialize(Client * p){p_instance = p;}
};


class Client: public QObject
{
    Q_OBJECT
    private:
        static Client * p_instance;
        static ClientDestroyer destroyer;
        static QTcpSocket * mTcpSocket;

        // анализ входных данных
        void output_analysis(QString answer){
            int size_of_identifier = 8;  // создание перменной для размера идентификатора
            QString identifier = "";  // создание переменной для идентификатора
            identifier = answer.left(size_of_identifier);  // запись первых восьми символов, см. README (идентификатор)
            answer = answer.mid(size_of_identifier);  // пересохранение переменной удалив первые 8 символов
            qDebug() << "QUERY: " + identifier + " -> " + answer;  // вывод отладочной информации в консоль

            if (identifier=="/mes0010"){
                emit logged_in(true);
            }
            else if (identifier=="/err0010")
                emit logged_in(false);
            else if (identifier == "/ans1005")
                emit show_info(answer);
            else if (identifier == "/ans1010")
                emit show_orders(answer);
            else if (identifier == "/ans1100")
                emit answer_order(answer);
            else if (identifier == "/err0100")
                emit error_order();
            else if (identifier == "/mes0101")
                emit product_is_ordered();
            else {
                qDebug()<< "ERROR CLIENT.H";
            }
        }

signals:
    void logged_in(bool flag);
    void show_info(QString answer);
    void show_orders(QString answer);
    void answer_order(QString answer);
    void error_order();
    void product_is_ordered();
    protected:
         Client(QObject *parent = nullptr)
        {
            mTcpSocket = new QTcpSocket(this);
            mTcpSocket->connectToHost("127.0.0.1", 33333);
            connect(mTcpSocket, &QTcpSocket::readyRead,
                this, &Client::slotServerRead);

        }
        ~Client() {mTcpSocket->close();}

        Client(const Client& );
        Client& operator = (Client &);
        friend class ClientDestroyer;

    public:
        int test=0;
        int get_test(){
            return test;
        }
        static Client* getInstance(){
            if (!p_instance)
            {
                p_instance = new Client();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
    void SentToServer(QString request)
    {
        mTcpSocket->write(request.toUtf8());
    }

    public slots:
    void slotServerRead()
    {
        QString answer = "";
        while(mTcpSocket->bytesAvailable()>0)
        {
            QByteArray array = mTcpSocket->readAll();
            answer.append(array);
        }
        output_analysis(answer);  // анализ выходных данных
    }
};

#endif // CLIENT_H
