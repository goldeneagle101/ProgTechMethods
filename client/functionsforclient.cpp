#include "functionsforclient.h"


void reg(QString log, QString pass, QString email){
    QString res="reg "+log+" "+pass+ " " + email + " ";
    Client::getInstance()->Client::SentToServer(res);
}

void auth(QString log, QString pass){
    QString res="auth "+log+" "+pass+ " ";
    Client::getInstance()->Client::SentToServer(res);
}

void order(QString article, QString quantity){
    QString res= "order " + article + " " + quantity + " ";
    qDebug() << res;
}

void show_info_products(){
    QString sip = "example  ";
    Client::getInstance()->Client::SentToServer(sip);
}

void show_info_orders(){
    QString sip = "orders ";
    Client::getInstance()->Client::SentToServer(sip);
}

