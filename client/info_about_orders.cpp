#include "info_about_orders.h"
#include "ui_info_about_orders.h"
#include "Client.h"

info_about_orders::info_about_orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info_about_orders)
{
    ui->setupUi(this);
    connect(Client::getInstance(),&Client::show_orders,this,&info_about_orders::print_answer);
    connect(Client::getInstance(),&Client::logged_in,this,&info_about_orders::clear_old_data);

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
    clear_all();
    hide();
}


void info_about_orders::on_generate_up_to_date_information_clicked()
{
    show_info_orders();
}

// зачистка данных от старого пользователя при смене пользователя
void info_about_orders::clear_old_data(bool flag)
{
    clear_all();
}

void info_about_orders::clear_all()
{
    ui->text_info_about_orders->setText("");
}

