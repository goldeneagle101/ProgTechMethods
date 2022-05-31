#include "authform.h"
#include "ui_authform.h"
#include "functionsforclient.h"
#include "mainwindow.h"
#include "Client.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    ui->line_email->setVisible(false);  // скрываем поле email при входе на окно авторизации
    connect(Client::getInstance(),&Client::logged_in,this,&AuthForm::on_logged_in);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::on_registration_clicked()
{
    ui->line_login->setText("");
    ui->line_password->setText("");
    ui->line_email->setText("");
    ui->line_email->setVisible(true);  // показываем поле email при нажатии кнопки регистрация
    ui->enter->setText("Зарегистрироваться");  // переименование клавиши войти на зарегистрироваться
    ui->registration->setVisible(false);  // скрываем кнопку регистрации
}


void AuthForm::on_enter_clicked()
{
    QString log = ui->line_login->text();
    QString pass = ui->line_password->text();
    if (ui->line_email->isVisible()){
        QString email = ui->line_email->text();
        reg(log, pass, email);  // регистрация в программе
        ui->line_email->setVisible(false);
        ui->registration->setVisible(true);
        ui->line_login->setText("");
        ui->line_password->setText("");
        ui->line_email->setText("");
        ui->enter->setText("Войти");  // переименование клавиши зарегистрироваться на войти
    }
    else{
        auth(log, pass);  // аутентификация в программе
        QString user_name = "Текущий пользователь: " + log;

        //emit logged_in(user_name);  // вызов сигнала входа в систему
        //hide();  // скрыть окно
        //ui->line_login->setText("");
        //ui->line_password->setText("");
    }
}

void AuthForm::on_logged_in(bool flag)
{
     QString lo = ui->line_login->text();
     ui->line_login->setText("");
     ui->line_password->setText("");
    if(flag)
    {

        emit logged_in(lo);
        emit clear_all();
        close();

    }



}

