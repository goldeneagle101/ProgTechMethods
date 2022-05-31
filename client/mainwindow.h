#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"
#include "productsinformation.h"
#include "functionsforclient.h"
#include "info_about_orders.h"
#include "prod_order.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_products_information_clicked();

    void on_prod_information_triggered();

    void on_exit_clicked();

    void on_exit_from_app_triggered();


    void on_switch_user_clicked();

    void on_logged_in(QString log);

    void on_information_about_orders_clicked();

    void on_product_order_clicked();

private:
    Ui::MainWindow *ui;
    AuthForm *auth_f;  // создание указателя на окно авторизации
    productsinformation *prod_info;  // создание указателя на окно просмотр ассортимента
    info_about_orders *info_orders;  // создание указателя на окно просмотра заказов
    prod_order *prod_orders;  // создание указателя на окно заказа товара
};
#endif // MAINWINDOW_H
