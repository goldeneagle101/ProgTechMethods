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
