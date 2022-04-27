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
    void on_return_to_main_window_from_products_information_clicked();

    void on_order_clicked();

private:
    Ui::prod_order *ui;
};

#endif // PROD_ORDER_H
