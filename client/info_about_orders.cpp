#include "info_about_orders.h"
#include "ui_info_about_orders.h"
#include "Client.h"

info_about_orders::info_about_orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info_about_orders)
{
    ui->setupUi(this);
    connect(Client::getInstance(),&Client::show_orders,this,&info_about_orders::print_answer);
}

info_about_orders::~info_about_orders()
{
    delete ui;
}

void info_about_orders::print_answer(QString answer)
{
    ui->text_info_about_orders->setText(answer);
}

void info_about_orders::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    hide();
}


void info_about_orders::on_generate_up_to_date_information_clicked()
{
    show_info_orders();
}

