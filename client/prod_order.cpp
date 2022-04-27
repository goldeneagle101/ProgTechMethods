#include "prod_order.h"
#include "ui_prod_order.h"
#include "functionsforclient.h"

prod_order::prod_order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prod_order)
{
    ui->setupUi(this);
}

prod_order::~prod_order()
{
    delete ui;
}

void prod_order::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    hide();
}


void prod_order::on_order_clicked()
{
    QString article = ui->article_number->text();
    QString quantity = ui->quantity->text();
    order(article, quantity);
    ui->article_number->setText("");
    ui->quantity->setText("");
}

