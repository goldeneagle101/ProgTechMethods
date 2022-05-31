#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>

class DataBase;

class DataBaseDestroyer
{
    private:
        DataBase * p_instance;
    public:
        ~DataBaseDestroyer()
        {
            delete p_instance;
        }
        void initialize(DataBase * p)
        {
            p_instance = p;
        }
};


class DataBase
{

    private:
        static DataBase * p_instance;
        static DataBaseDestroyer destroyer;

        static QSqlDatabase db;
    protected:
        DataBase()
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("../latest_version/DB.db");
            db.open();

            if (!db.open())
                qDebug() << db.lastError().text();
        }
        DataBase(const DataBase& );
        DataBase& operator = (DataBase &);
        ~DataBase() {}
        friend class DataBaseDestroyer;
    public:
        // возврат указателя на базу данных
        static DataBase *getInstance(){
            if (!p_instance)
            {
                p_instance = new DataBase();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        // добавление пользователя при регистрации
        static QString Add(QString login, QString password, QString email) {
            // проверка на существовании записи о пользователе
            if (DataBase::Found(login, password) != "Invalid login")
                return "The user is already exists";
            else {
                QSqlQuery query(db);
                query.prepare("INSERT INTO User(login, password, email) VALUES (:login, :password, :email)");
                query.bindValue(":login", login);
                query.bindValue(":password", password);
                query.bindValue(":email", email);
                query.exec();
                return "True";
            }
        }

        static QString active_user(QString login, QString id_function, long long id_descriptor){
            bool flag_check = false;
            if (id_function == "1"){
                QSqlQuery query(db);
                query.prepare("UPDATE User SET active = :id_active WHERE login = :login");
                query.bindValue(":login", login);
                query.bindValue(":id_active", id_descriptor);
                query.exec();
                flag_check = true;
            }
            else if (id_function == "0"){
                QSqlQuery query(db);
                query.prepare("UPDATE User SET active = :id_active WHERE login = :login");
                query.bindValue(":login", login);
                query.bindValue(":id_active", id_descriptor);
                query.exec();
                flag_check = true;
            }
            if (flag_check == true)
                return "True";
            else
                return "False";
        }

        // поиск записи о пользователе при аутентификации
        static QString Found(QString login, QString password) {
            QSqlQuery query(db);
            query.prepare("SELECT * FROM User where login = :login");
            query.bindValue(":login", login);
            query.exec();
            QSqlRecord rec = query.record();

            //qDebug() << (query.value(rec.indexOf("login")).toString())<< ";\t" << (query.value(rec.indexOf("password")).toString()) << "\n";

            // проверка на корректную аутентификацию
            if (!query.next())
                return "Invalid login";
            else
            {
                if (password == query.value(rec.indexOf("password")).toString()) {
                    qDebug() << query.value(rec.indexOf("password")).toString();
                    return "True";
                }
                else return "Invalid password";
            }
        }

        static QString Show_products(){ //вывод информации и товарах
            QSqlQuery query(db);
            query.exec("SELECT * FROM Products");
            QSqlRecord rec = query.record();
            QString article, name, count;
            bool flag = false;
            QString answer = "";
            while (query.next()) {
               article = query.value(rec.indexOf("article")).toString();
               name = query.value(rec.indexOf("name")).toString();
               count = query.value(rec.indexOf("count")).toString();

               qDebug() << "Артикул: " + article + " Наименование товара: " + name + " Количество товара доступное для заказа: " + count + "\n";
               answer += "Артикул: " + article + " Наименование товара: " + name + " Количество товара доступное для заказа: " + count + "\n";

               if (!flag) flag = true;
            }
            if (flag)
                return answer;
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }

        static QString Orders(long long id_descriptor){ //заказы
            QSqlQuery query(db);
            query.prepare("select id_client, id_product from Orders "
                       "JOIN Products ON Products.article = Orders.id_product "
                       "JOIN User ON User.id = Orders.id_client "
                       "WHERE User.active = :id_descriptor");
            query.bindValue(":id_descriptor", id_descriptor);
            query.exec();
            QSqlRecord rec = query.record();
            QString article, login;
            bool flag = false;
            QString answer = "";
            while (query.next()) {
               article = query.value(rec.indexOf("id_product")).toString();
               login = query.value(rec.indexOf("id_client")).toString();
               qDebug() << "Товар: " + article + " Заказал: " + login +"\n";
               answer += "Товар: " + article + " Заказал: " + login +"\n";

               if (!flag) flag = true;
            }
            if (flag)
                return answer;
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }


        static QString Check(){ //проверка таблицы пользователей
            QSqlQuery query(db);
            query.exec("SELECT * FROM User");
            QSqlRecord rec = query.record();
            QString login, password, email;
            bool flag = false;

            while (query.next()) {
               login = query.value(rec.indexOf("login")).toString();
               password = query.value(rec.indexOf("password")).toString();
               email = query.value(rec.indexOf("email")).toString();

               qDebug() << login << ";\t" << password << ";\t" << email;
               if (!flag) flag = true;
            }
            //query.exec("DROP TABLE User");
            if (flag)
                return "Succes"; //если что-то вывелось, то в сервер выводиться успех, иначе провал
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }


        static QString just_orders(){
            QSqlQuery query(db);
            query.exec("SELECT * FROM Orders");
            QSqlRecord rec = query.record();
            QString id_order, id_client, id_product;
            bool flag = false;
            QString answer = "";
            while (query.next()) {
                id_order = query.value(rec.indexOf("id_order")).toString();
                id_client = query.value(rec.indexOf("id_client")).toString();
                id_product = query.value(rec.indexOf("id_product")).toString();

                qDebug() << id_order + " " + id_client + " " + id_product;
                answer += id_order + " " + id_client + " " + id_product +"\n";

               if (!flag) flag = true;
            }
            if (flag)
                return answer;
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }

        static QString just_trucks(){
            QSqlQuery query(db);
            query.exec("SELECT * FROM Truck");
            QSqlRecord rec = query.record();
            QString id_order, id_client, id_product;
            bool flag = false;
            QString answer = "";
            while (query.next()) {
                id_order = query.value(rec.indexOf("id")).toString();
                id_client = query.value(rec.indexOf("name")).toString();
                id_product = query.value(rec.indexOf("value")).toString();

                qDebug() << id_order + " " + id_client + " " + id_product;
                answer += id_order + " " + id_client + " " + id_product +"\n";

               if (!flag) flag = true;
            }
            if (flag)
                return answer;
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }

        static QString just_orders_for_trucks(){
            QSqlQuery query(db);
            query.exec("SELECT * FROM order_for_truck");
            QSqlRecord rec = query.record();
            QString id_order, id_client, id_product, id_product_2;
            bool flag = false;
            QString answer = "";
            while (query.next()) {
                id_order = query.value(rec.indexOf("id")).toString();
                id_client = query.value(rec.indexOf("id_truck")).toString();
                id_product = query.value(rec.indexOf("id_order")).toString();
                id_product_2 = query.value(rec.indexOf("date")).toString();

                qDebug() << id_order + " " + id_client + " " + id_product + id_product_2;
                answer += id_order + " " + id_client + " " + id_product + " " + id_product_2 +"\n";

               if (!flag) flag = true;
            }
            if (flag)
                return answer;
            else {
                qDebug() << "Fail";
                return "Fail";
            }
        }




        // закрытие базы данных
        static void closeDB()
        {
            db.close(); // Закрыть БД
        }

};

#endif // DATABASE_H
