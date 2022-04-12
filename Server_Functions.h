#ifndef SERVER_FUNCTIONS_H
#define SERVER_FUNCTIONS_H
#include <QStringList>
#include <QString>


// ??????????? почему не работает?
//QStringList parsing_data_from_user;  // контейнер, представляющий собой двухсвязный список,
                                     // для обработки запроса пользователя
//QString function_name;  // имя функции, полученное в результате parsing()
// ?????????????

// функция обработки запроса сервером
QByteArray parsing(QString main_data_from_client);  // парсинг данных, введенных пользователем

// функции сервера
QByteArray auth(QString log, QString pass);  // функция авторизации
QByteArray reg(QString log, QString pass, QString email, QString mobilephonenumber);  // функция регистрации
QByteArray example(QString first_param);  // дополнительная функция

#endif // SERVER_FUNCTIONS_H
