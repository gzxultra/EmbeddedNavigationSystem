#include "widget.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    //if(!createConnection())
      //  return 1;
    createConnection();
    Widget w;
    w.show();
    return a.exec();
}

bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("test.db");
    db.setUserName("gzxultra");
    db.setPassword("123456798");
    bool success;
    success = db.open();
    if(!success)
        qDebug()<<QObject::tr("打开数据库失败!\n");
    else
        qDebug()<<QObject::tr("打开数据库成功!\n");


    QSqlQuery query;
    success = query.exec("create table automobil(id int primary key, temperature int)");

    if(success)
        qDebug()<<QObject::tr("数据库表创建成功!\n");
    else
        qDebug()<<QObject::tr("数据库表创建失败!\n");

    return true;
}

