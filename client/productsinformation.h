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

private:
    Ui::productsinformation *ui;
};

#endif // PRODUCTSINFORMATION_H
