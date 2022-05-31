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
    info_orders = new info_about_orders;  //подключение окна просмотра заказов
    prod_orders = new prod_order;  // подключение окна заказа товара

    connect(auth_f, &AuthForm::logged_in, this, &MainWindow::on_logged_in);  // connect(источник, действие_источника, получатель, действие_получателя
    connect(prod_info, &productsinformation::return_to_main_window, this, &MainWindow::show);
    connect(info_orders, &info_about_orders::return_to_main_window, this, &MainWindow::show);
    connect(prod_orders, &prod_order::return_to_main_window, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logged_in(QString log)
{
    ui->login->setText(log);
    show();
}

void MainWindow::on_products_information_clicked()
{
    prod_info->show();
    hide();
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


void MainWindow::on_switch_user_clicked()
{
    auth_f->show();
    hide();
}


void MainWindow::on_information_about_orders_clicked()
{
    info_orders->show();
    hide();
}


void MainWindow::on_product_order_clicked()
{
    prod_orders->show();
    hide();
}

