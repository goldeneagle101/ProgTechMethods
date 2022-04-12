#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auth_f = new AuthForm;  // подключение окна авторизации
    auth_f->show();  // отображение окна авторизации
    prod_info = new productsinformation; // подключение окна просмотр ассортимента

    connect(auth_f, &AuthForm::logged_in, this, &MainWindow::show);  // connect(источник, действие_источника, получатель, действие_получателя
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_products_information_clicked()
{
    prod_info->show();
}



void MainWindow::on_prod_information_triggered()
{
    on_products_information_clicked();
}


void MainWindow::on_exit_clicked()
{
    close();
}


void MainWindow::on_exit_from_app_triggered()
{
    on_exit_clicked();
}

