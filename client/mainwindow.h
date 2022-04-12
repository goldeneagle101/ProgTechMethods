#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "authform.h"
#include "productsinformation.h"

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

private:
    Ui::MainWindow *ui;
    AuthForm *auth_f;  // создание указателя на окно авторизации
    productsinformation *prod_info;  // создание указателя на окно просмотр ассортимента
};
#endif // MAINWINDOW_H
