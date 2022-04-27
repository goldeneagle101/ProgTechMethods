#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QDebug>

void reg(QString log, QString pass, QString email);
void auth(QString log, QString pass);
void order(QString article, QString quantity);

#endif // FUNCTIONSFORCLIENT_H
