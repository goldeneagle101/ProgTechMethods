#include "Server_Functions.h"

// парсинг данных, введенных пользователем
QByteArray parsing(QString main_data_from_client){
    QStringList parsing_data_from_user; // контейнер, представляющий собой двухсвязный список,
                                        // для обработки запроса пользователя
    QString function_name;  // имя функции, полученное в результате parsing()
    int number_of_parameters;  // количество параметров (необходимо для предотвращения ошибки нехватки параметров)

    parsing_data_from_user = main_data_from_client.split(QLatin1Char('&'));  // разделение введенных данных по спец символу
    function_name = parsing_data_from_user.front();
    parsing_data_from_user.pop_front();
    number_of_parameters = parsing_data_from_user.size();
    if (function_name=="auth"){
        if (number_of_parameters == 2){
            return auth(parsing_data_from_user.at(0), parsing_data_from_user.at(1));
        }
        else{
            return "error (incorrect number of parameters during authorization).\n";
        }
    }
    else if (function_name=="reg"){
        if (number_of_parameters == 4){
            return reg(parsing_data_from_user.at(0), parsing_data_from_user.at(1),
                       parsing_data_from_user.at(2), parsing_data_from_user.at(3));;
        }
        else{
            return "error (incorrect number of parameters during registration).\n";
        }
    }
    else if (function_name=="example"){
        if (number_of_parameters == 1){
            return example(parsing_data_from_user.at(0));;
        }
        else{
            return "error (incorrect number of parameters during running example()).\n";
        }
    }
    else return "error\n";
}

// функция авторизации
QByteArray auth(QString log, QString pass){
  log = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
  pass = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
  return "auth\n";
}

// функция регистрации
QByteArray reg(QString log, QString pass, QString email, QString mobilephonenumber){
    log = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    pass = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    email = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    mobilephonenumber = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    return "reg\n";
}

// дополнительная функция
QByteArray example(QString first_param){
    first_param = "";  // обнуление, чтобы не было предупреждения. В дальнейшем необходимо удалить
    return "example\n";
}
