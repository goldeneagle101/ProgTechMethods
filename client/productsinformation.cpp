#include "productsinformation.h"
#include "ui_productsinformation.h"

productsinformation::productsinformation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::productsinformation)
{
    ui->setupUi(this);
}

productsinformation::~productsinformation()
{
    delete ui;
}

void productsinformation::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    hide();
}

