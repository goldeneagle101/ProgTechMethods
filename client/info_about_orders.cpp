#include "info_about_orders.h"
#include "ui_info_about_orders.h"

info_about_orders::info_about_orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info_about_orders)
{
    ui->setupUi(this);
}

info_about_orders::~info_about_orders()
{
    delete ui;
}

void info_about_orders::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    hide();
}

