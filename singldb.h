#ifndef SINGLDB_H
#define SINGLDB_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>


class SingDB;//объявляемЮ что где-то есть класс

class SingDestDB//класс для очистки
{
private:
    SingDB * p_instan;//создаем ссылку на объект SingDB
public:

    ~SingDestDB();

    void initial(SingDB * p);
};

class SingDB
{
private:
    static SingDB * p_instan; //ссылка на объект SingDB
    static SingDestDB dest;
    QSqlDatabase db; // сама бд
    QStringList res;
protected:
    SingDB();
    SingDB(const SingDB&) = delete;
    SingDB& operator = (SingDB&) = delete;
    ~SingDB();
    friend class SingDestDB;

public:
    static SingDB * getInstance();//медот получения единственного экземляра SingDB

    QStringList getValue(QString);//метод для отправки в бд запросов
};


#endif // SINGLDB_H
