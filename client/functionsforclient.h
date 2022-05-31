#ifndef FUNCTIONSFORCLIENT_H
#define FUNCTIONSFORCLIENT_H

#include <QDebug>

#include "Client.h"

void reg(QString log, QString pass, QString email);
void auth(QString log, QString pass);
void order(QString article);
void show_info_products();
void show_info_orders();
void user_disconnected();
void create_order(int id_product, int quantity);

#endif // FUNCTIONSFORCLIENT_H
