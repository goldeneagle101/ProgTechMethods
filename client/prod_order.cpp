#include "prod_order.h"
#include "ui_prod_order.h"
#include "functionsforclient.h"
#include "Client.h"

prod_order::prod_order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prod_order)
{
    ui->setupUi(this);
    connect(Client::getInstance(),&Client::logged_in,this,&prod_order::clear_old_data);
    connect(Client::getInstance(),&Client::answer_order,this,&prod_order::answer_order);
    connect(Client::getInstance(),&Client::error_order,this,&prod_order::error_order);
    connect(Client::getInstance(),&Client::product_is_ordered,this,&prod_order::product_is_ordered);
}

prod_order::~prod_order()
{
    delete ui;
}

void prod_order::clear_all(int flag)
{
    if (flag == 0){
        ui->quantity->setText("");
        ui->article_number->setText("");
        ui->quantity->setEnabled(true);
        ui->article_number->setEnabled(true);
        ui->order->setEnabled(true);
        ui->info->setText("");
        ui->reject->setEnabled(false);
        ui->confirm->setEnabled(false);
        ui->order_reset->setEnabled(false);
        ui->status->setText("");
    }
    else if (flag == 1){
        //активация запроса одобрения заказа
        ui->quantity->setEnabled(false);
        ui->article_number->setEnabled(false);
        ui->order->setEnabled(false);
        ui->reject->setEnabled(true);
        ui->confirm->setEnabled(true);
        ui->order_reset->setEnabled(true);
    }
    else if (flag == 2){
        // зачистка при отсутствии товара
        ui->article_number->setText("");
        ui->quantity->setText("");
    }
}

void prod_order::on_return_to_main_window_from_products_information_clicked()
{
    emit return_to_main_window();
    clear_all(0);
    hide();
}


void prod_order::on_order_clicked()
{
    QString article = ui->article_number->text();
    QString quantity = ui->quantity->text();
    global_article = article.toInt();
    global_quantity = quantity.toInt();
    order(article);
}

// зачистка данных от старого пользователя при смене пользователя
void prod_order::clear_old_data(bool flag)
{
    clear_all(0);
}


void prod_order::on_order_reset_clicked()
{
    clear_all(0);
}

void prod_order::answer_order(QString answer)
{
    clear_all(1);
    QString answer_quantity = answer.left(6);  // обработка количества
    QString answer_info = answer.mid(6);  // обработка информации об товаре
    global_int_answer_quantity = answer_quantity.toInt();  // преобразование в integer, чтобы можно было сравнивать как количество
    //QString answer_for_client = QStringLiteral("Количество %1 \n").arg(int_answer_quantity);
    // сравнение полученных данных и запрошенных
    global_flag_for_order = 0;
    // если товар закончился
    if (global_int_answer_quantity == 0){
        clear_all(0);
        ui->info->setText(answer_info + "Товар закончился :(");
    }
    // если товара меньше, чем нужно
    else if (global_int_answer_quantity < global_quantity){
        global_flag_for_order = 1;
        ui->info->setText(answer_info +
                          QStringLiteral("Товар в нужном количестве отсутствует, доступно для заказа %1 шт.\n").arg(global_int_answer_quantity));
    }
    // если товара достаточно для заказа
    else if (global_int_answer_quantity >= global_quantity){
        global_flag_for_order = 2;
        ui->info->setText(answer_info + QStringLiteral("Товар в размере %1 шт. доступен для заказа\n").arg(global_quantity));
    }
}

void prod_order::error_order()
{
    QString article = ui->article_number->text();
    ui->info->setText("Товара с артиклем " + article + " не существует.");
    clear_all(2);
}


void prod_order::on_confirm_clicked()
{
    clear_all(0);
    if (global_flag_for_order == 2){
        create_order(global_article, global_quantity);
    }
    else if (global_flag_for_order == 1){
        create_order(global_article, global_int_answer_quantity);
    }
}



void prod_order::on_reject_clicked()
{
    clear_all(0);
    ui->status->setText("Заказ отменен");
}

void prod_order::product_is_ordered()
{
    ui->status->setText("Товар заказан");
}

