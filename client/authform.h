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

    void on_logged_in(bool flag);

signals:
    void logged_in(QString log);
    void clear_all();  // для очистки всех форм прошлого пользователя

private:
    Ui::AuthForm *ui;
};

#endif // AUTHFORM_H
