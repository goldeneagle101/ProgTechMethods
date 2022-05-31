#ifndef SERVER_FUNCTIONS_H
#define SERVER_FUNCTIONS_H
#include <QStringList>
#include <QString>
#include "database.h"

/// \authors Tatarchuk_Mihail
/// \date 28.03.2022
/// \version 1.0.0
/// \brief parsing функция для реализации парсинга запросов
/// \brief auth функция для авторизации
/// \brief reg функция для регистрации
/// \brief example просто функция (для проверки работоспособности)
/// \param[in] main_data_from_client строка введенная клиентом
/// \param[in] log логин пользователя
/// \param[in] pass пароль пользователя
/// \param[in] email e-mail пользователя
/// \param[in] mobilephonenumber номер телефона пользователя


// ??????????? почему не работает?
//QStringList parsing_data_from_user;  // контейнер, представляющий собой двухсвязный список,
                                     // для обработки запроса пользователя
//QString function_name;  // имя функции, полученное в результате parsing()
// ?????????????

// функция обработки запроса сервером
QByteArray parsing(QString main_data_from_client, long long id_descriptor);  // парсинг данных, введенных пользователем

// функции сервера
QByteArray auth(QString log, QString pass, long long id_descriptor);  // функция авторизации
QByteArray reg(QString log, QString pass, QString email);  // функция регистрации
QByteArray orders(long long id_descriptor);
QByteArray just_orders();
QByteArray just_trucks();
QByteArray just_orders_for_trucks();
QByteArray example(QString first_param);  // дополнительная функция

#endif // SERVER_FUNCTIONS_H
