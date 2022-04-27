#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>


namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:

    void on_registration_clicked();

    void on_enter_clicked();

signals:
    void logged_in(QString log);

private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
