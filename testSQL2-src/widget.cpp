#include "widget.h"
#include "ui_widget.h"
#include <QLatin1String>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::insertData()
{
    QSqlQuery query;
    query.exec("select * from automobil");
    QSqlRecord rec = query.record();
    qDebug()<< QObject::tr("automobil 表字段数：")<<rec.count();
    bool success;
    query.prepare("insert into automobil values(?, ?)");
    for(int i=0; i<5; i++)
    {
        query.bindValue(0, i+1);
        query.bindValue(1, rand()%35 +15);

        success = query.exec();
        if(!success)
        {
            QSqlError lastError = query.lastError();
            qDebug()<<lastError.driverText()<<QString(QObject::tr("插入失败!\n"));
        }
    }
}

void Widget::queryData()
{
    //ui->textBrowser->append("hello");
    QSqlQuery query;
    QString result;
    query.exec("SELECT id, temperature FROM automobil");
    if(!query.isActive())
        QMessageBox::warning(this, tr("Database Error!"), query.lastError().text());
    else{
        while(query.next())
        {
            QString result = query.value(0).toString() + ' ';
            result += query.value(1).toString();
            ui->textBrowser->append(result);
            paintEvent();
        }
       }
}

void Widget::paintEvent()
{
    QPainter painter(this); //this为绘图设备，即表明在该部件上进行绘制
    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
}
