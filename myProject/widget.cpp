#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
    //ui->textBrowser->setAlignment(Qt::AlignCenter);
    //ui->textBrowser->setText(QString(QObject::tr("\t\t智能温度计")));
}

Widget::~Widget()
{
	delete ui;
}


void Widget::queryData()
{
    QSqlQuery query;
    QString result;
    query.exec("SELECT id, temperature FROM automobil");
    if (!query.isActive())
        QMessageBox::warning(this,\
                             QObject::tr("Database Error!"), query.lastError().text());
    else {
        while (query.next())
        {
            QString result = query.value(0).toString() + ' ';
            result += query.value(1).toString();
            ui->textBrowser->append(result);
        }
    }
}
void Widget::insertData()
{
    QSqlQuery query;
    query.exec("select * from automobil");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("automobil 表字段数：") << rec.count();
    bool success;
    query.prepare("insert into automobil values(?, ?)");
    for (int i = 0; i < 5; i++)
    {
        query.bindValue(0, i + 1);
        query.bindValue(1, i);

        success = query.exec();
        if (!success)
        {
            QSqlError lastError = query.lastError();
            qDebug() << lastError.driverText() << QString(QObject::tr("插入失败!\n"));
        }
    }
}

bool Widget::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("test.db");
    db.setUserName("gzxultra");
    db.setPassword("123456798");
    bool success;
    success = db.open();
    if (!success)
        qDebug() << QObject::tr("打开数据库失败!\n");
    else
        qDebug() << QObject::tr("打开数据库成功!\n");


    QSqlQuery query;
    success = query.exec("create table automobil(id int primary key, temperature int)");

    if (success)
        qDebug() << QObject::tr("数据库表创建成功!\n");
    else
        qDebug() << QObject::tr("数据库表创建失败!\n");

    return true;
}

void Widget::httpPost()
{

}
