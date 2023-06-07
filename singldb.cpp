#include "singldb.h"

SingDB * SingDB::p_instan;
SingDestDB SingDB::dest;

SingDB::SingDB()
{

    db = QSqlDatabase::addDatabase("QSQLITE");// подключаем к SQLITE
    db.setDatabaseName("./ExamDB.db");
    QSqlQuery query(db);
    if(db.open())
        qDebug()<<"open";
    else
        qDebug()<<"no open";


    if (db.tables().contains(QLatin1String("User")))
        qDebug()<<"Be";
    else{
        query.exec("CREATE TABLE User (Login VARCHAR(20) NOT NULL UNIQUE, Queue VARCHAR(20) NOT NULL;");
        qDebug()<<"create";
    }

}



QStringList SingDB::getValue(QString log)
{
    QSqlQuery query(db);
    res.clear();
    if(query.exec(log))
    {
        int num_of_cols = query.record().count();

        while(query.next()) for(int i = 0; i<num_of_cols;i++) res.append(query.value(i).toString());
        return res;
    }
    else{
        res.append("Error");
        return res;
    }

}

SingDB::~SingDB()
{
    if(p_instan!=nullptr)
        db.close();
}

SingDestDB::~SingDestDB()
{
   delete p_instan;
}

void SingDestDB::initial(SingDB * p)
{
    p_instan = p;
}

SingDB* SingDB::getInstance()
{
    if (!p_instan){
        p_instan = new SingDB();
        dest.initial(p_instan);
    }
    return p_instan;
}

