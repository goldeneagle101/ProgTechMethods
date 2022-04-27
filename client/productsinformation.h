#ifndef PRODUCTSINFORMATION_H
#define PRODUCTSINFORMATION_H

#include <QWidget>

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

private:
    Ui::productsinformation *ui;
};

#endif // PRODUCTSINFORMATION_H
