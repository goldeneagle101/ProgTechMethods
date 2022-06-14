#include "productsinformation.h"
#include "ui_productsinformation.h"

productsinformation::productsinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::productsinformation)
{
    ui->setupUi(this);
    connect(Client::getInstance(),&Client::show_info,this,&productsinformation::print_answer);
    connect(Client::getInstance(),&Client::logged_in,this,&productsinformation::clear_old_data);
}

productsinformation::~productsinformation()
{
    delete ui;
}

void productsinformation::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    clear_all();
    hide();
}

void productsinformation::print_answer(QString answer)
{
    ui->text_info_about_products->setText(answer);
}

// зачистка данных от старого пользователя при смене пользователя
void productsinformation::clear_old_data(bool flag)
{
    clear_all();
}

void productsinformation::clear_all()
{
    ui->text_info_about_products->setText("");
}


void productsinformation::on_generate_up_to_date_information_clicked()
{
    show_info_products();
}

