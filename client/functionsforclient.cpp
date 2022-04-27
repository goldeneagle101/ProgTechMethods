#include "functionsforclient.h"


void reg(QString log, QString pass, QString email){
    QString res = "reg&" + log + "&" + pass + "&" + email;
    qDebug() << res;
}

void auth(QString log, QString pass){
    QString res = "auth&" + log + "&" + pass;
    qDebug() << res;
}

void order(QString article, QString quantity){
    QString res = "order&" + article + "&" + quantity;
    qDebug() << res;
}
