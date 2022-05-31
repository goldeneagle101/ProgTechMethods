#include "functionsforclient.h"


void reg(QString log, QString pass, QString email){
    QString res="reg "+log+" "+pass+ " " + email + " ";
    Client::getInstance()->Client::SentToServer(res);
}

void auth(QString log, QString pass){
    QString res="auth "+log+" "+pass+ " ";
    Client::getInstance()->Client::SentToServer(res);
}

void order(QString article){
    QString res= "find_product " + article + " ";
    Client::getInstance()->Client::SentToServer(res);
}

void show_info_products(){
    QString sip = "example  ";
    Client::getInstance()->Client::SentToServer(sip);
}

void show_info_orders(){
    QString sip = "orders ";
    Client::getInstance()->Client::SentToServer(sip);
}


void user_disconnected()
{
    QString sip = "user_disconnected  ";
    Client::getInstance()->Client::SentToServer(sip);
}



void create_order(int id_product, int quantity)
{
    QString sip = "create_order " + QString::number(id_product) + " " + QString::number(quantity) + " ";
    Client::getInstance()->Client::SentToServer(sip);
}
