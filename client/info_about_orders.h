#ifndef INFO_ABOUT_ORDERS_H
#define INFO_ABOUT_ORDERS_H

#include <QWidget>

namespace Ui {
class info_about_orders;
}

class info_about_orders : public QWidget
{
    Q_OBJECT

public:
    explicit info_about_orders(QWidget *parent = nullptr);
    ~info_about_orders();


signals:
    void return_to_main_window();

private slots:
    void on_return_to_main_window_from_products_information_clicked();
    void print_answer(QString answer);
    void on_generate_up_to_date_information_clicked();
    void clear_old_data(bool flag);
    void clear_all();

private:
    Ui::info_about_orders *ui;
};

#endif // INFO_ABOUT_ORDERS_H
