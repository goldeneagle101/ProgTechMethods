#ifndef PROD_ORDER_H
#define PROD_ORDER_H

#include <QWidget>

namespace Ui {
class prod_order;
}

class prod_order : public QWidget
{
    Q_OBJECT

public:
    explicit prod_order(QWidget *parent = nullptr);
    ~prod_order();

signals:
    void return_to_main_window();

private slots:
    void clear_all(int flag);
    void on_return_to_main_window_from_products_information_clicked();
    void on_order_clicked();
    void clear_old_data(bool flag);
    void on_order_reset_clicked();
    void answer_order(QString answer);
    void error_order();

    void on_confirm_clicked();

    void on_reject_clicked();
    void product_is_ordered();

private:
    int global_article;
    int global_quantity;
    int global_int_answer_quantity;
    int global_flag_for_order;
    Ui::prod_order *ui;
};

#endif // PROD_ORDER_H
