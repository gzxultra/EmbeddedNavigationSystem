#include "widget.h"
#include <QApplication>
#include <QSplashScreen>
#include "sht11_test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("splash.png").scaled(400,300,Qt::KeepAspectRatio));
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window..."));
    Widget w;
    splash->showMessage(QObject::tr("loading modules..."), topRight, Qt::white);
    createConnection();
    //callSensor();
    splash->showMessage(QObject::tr("Establishing connections..."));

    w.show();
    splash->finish(&w);
    delete splash;








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

