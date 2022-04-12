#include "authform.h"
#include "ui_authform.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->line_email->setVisible(false);  // скрываем поле email при входе на окно авторизации
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_registration_clicked()
{
    ui->line_email->setVisible(true);  // показываем поле email при нажатии кнопки регистрация
    ui->registration->setVisible(false);  // скрываем кнопку регистрации
}


void AuthForm::on_enter_clicked()
{
    emit logged_in();  // вызов сигнала входа в систему
    hide();  // скрыть окно
}

