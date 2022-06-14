#ifndef PRODUCTSINFORMATION_H
#define PRODUCTSINFORMATION_H

#include <QWidget>
#include "Client.h"

namespace Ui {
class productsinformation;
}

class productsinformation : public QWidget
{
    Q_OBJECT

public:
    explicit productsinformation(QWidget *parent = nullptr);
    ~productsinformation();

signals:
    void return_to_main_window();

private slots:
    void on_return_to_main_window_from_products_information_clicked();
    void print_answer(QString answer);
    void clear_old_data(bool flag);
    void clear_all();
    void on_generate_up_to_date_information_clicked();

private:
    Ui::productsinformation *ui;
};

#endif // PRODUCTSINFORMATION_H
