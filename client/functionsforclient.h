#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QDebug>

#include "Client.h"

void reg(QString log, QString pass, QString email);
void auth(QString log, QString pass);
void order(QString article, QString quantity);
void show_info_products();
void show_info_orders();

#endif // FUNCTIONSFORCLIENT_H
