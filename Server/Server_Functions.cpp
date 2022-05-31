#include "Server_Functions.h"

// парсинг данных, введенных пользователем
QByteArray parsing(QString main_data_from_client, long long id_descriptor){
    QStringList parsing_data_from_user; // контейнер, представляющий собой двухсвязный список,
                                        // для обработки запроса пользователя
    QString function_name;  // имя функции, полученное в результате parsing()
    int number_of_parameters;  // количество параметров (необходимо для предотвращения ошибки нехватки параметров)

    parsing_data_from_user = main_data_from_client.split(QLatin1Char(' '));  // разделение введенных данных по спец символу
    function_name = parsing_data_from_user.front();
    parsing_data_from_user.pop_front();
    number_of_parameters = parsing_data_from_user.size();
    if (function_name=="auth"){
        if (number_of_parameters == 3){
            return auth(parsing_data_from_user.at(0), parsing_data_from_user.at(1), id_descriptor);
        }
        else{
            return "error (incorrect number of parameters during authorization).\n";
        }
    }
    else if (function_name=="reg"){
        if (number_of_parameters == 4){
            return reg(parsing_data_from_user.at(0), parsing_data_from_user.at(1),
                       parsing_data_from_user.at(2));
        }
        else{
            return "error (incorrect number of parameters during registration).\n";
        }
    }
    else if (function_name=="example"){
        if (number_of_parameters == 2){
            return example(parsing_data_from_user.at(0));
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else if (function_name=="orders"){
        if (number_of_parameters == 1){
            return orders(id_descriptor);
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else if (function_name=="just_orders"){
        if (number_of_parameters == 1){
            return just_orders();
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else if (function_name=="just_trucks"){
        if (number_of_parameters == 1){
            return just_trucks();
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else if (function_name=="just_orders_for_trucks"){
        if (number_of_parameters == 1){
            return just_orders_for_trucks();
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else return "error\n";
}

// функция авторизации
QByteArray auth(QString log, QString pass, long long id_descriptor){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::Found(log, pass).toUtf8());
    if (QString(result)=="True"){
        result = "";
        result.append(DataBase::active_user(log, "1", id_descriptor).toUtf8());
        if (QString(result)=="True") result = "/mes0010";
    }
    else result = "/err0010";
    qDebug() << result;
    return result;
}

// функция регистрации
QByteArray reg(QString log, QString pass, QString email){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::Add(log, pass, email).toUtf8());
    result.append("\n");
    qDebug() << result;
    return result;
}

// дополнительная функция
QByteArray example(QString first_param){
    first_param = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    QByteArray result = "/ans0005";
    DataBase::getInstance();
    result.append(DataBase::Show_products().toUtf8());
    result.append("\n");
    return result;
    return "example\n";
}

QByteArray orders(long long id_descriptor)
{
    QByteArray result = "/ans0010";
    DataBase::getInstance();
    result.append(DataBase::Orders(id_descriptor).toUtf8());
    result.append("\n");
    return result;
}

QByteArray just_orders(){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::just_orders().toUtf8());
    result.append("\n");
    return result;
}

QByteArray just_trucks(){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::just_trucks().toUtf8());
    result.append("\n");
    return result;
}

QByteArray just_orders_for_trucks(){
    QByteArray result = "";
    DataBase::getInstance();
    result.append(DataBase::just_orders_for_trucks().toUtf8());
    result.append("\n");
    return result;
}

