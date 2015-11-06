#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);
    //ui->textBrowser->setAlignment(Qt::AlignCenter);
    //ui->textBrowser->setText(QString(QObject::tr("\t\t智能温度计")));
    ui->tableWidget->hide();
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(finishedSlot(QNetworkReply*)));
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


void Widget::pushMessage()
{
    //post action start
    QUrl url("https://api.submail.cn/message/xsend.json");

    QByteArray append("appid=10586&to=18651370755&project=d7skN4&signature=0bd4add5f563accb8f04f8b835e453f5");

    // here add your vars and date
    append.append("&vars={\"code\":\""+ QDateTime::currentDateTime().toString()+"\"}");
    //append.append("&vars={\"code\":\""+ QString("北京2015-11-06, pm25 = 44, 穿衣指数:建议着厚外套加毛衣等服装。年老体弱者宜着大衣、呢外套加羊毛衫。 感冒，较易发，感冒指数：天气较凉，较易发生感冒，请适当增加衣服。体质较弱的朋友尤其应该注意防护。来自风哥的智能温度计，么么哒！")+"\"}");
    qDebug()<<append;

    //QNetworkRequest::setHeader("User-Agent", "Mozilla/5.0");
    QNetworkRequest request(url);
    //request.setHeader("User-Agent", "Mozilla/5.0");
    QNetworkReply* reply = nam->post(request, append);
    ui->textBrowser->append(reply->readAll());
}

void Widget::getBaiduWeather()
{
    //post action start
    QUrl url("http://api.map.baidu.com/telematics/v3/weather?");

    QByteArray append("location=南通&output=xml&ak=YSGcdwW38tmEKRQvYzvuKDCu");

    qDebug()<<QObject::tr(append);

    //QNetworkRequest::setHeader("User-Agent", "Mozilla/5.0");
    QNetworkRequest request(url);
    //request.setRawHeader("User-Agent", "Mozilla/5.0 (X11; Linux x86_64; rv:7.0.1) Gecko/20100101 Firefox/7.0.1");
    QNetworkReply* reply = nam->post(request, append);
    qDebug()<<reply;
    ui->textBrowser->append(reply->readAll());
}

void Widget::insertData()
{
    QSqlQuery query;
    query.exec("select * from automobil");
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("automobil 表字段数：") << rec.count();
    bool success;
    query.prepare("insert into automobil values(?, ?)");
    for (int i = 5; i < 10; i++)
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

void Widget::xmlParser(QString xmlData){

}

void Widget::finishedSlot(QNetworkReply *reply)
{
#if 1
    // Reading attributes of the reply
    // e.g. the HTTP status code
    QVariant statusCodeV =
        reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    // Or the target URL if it was a redirect:
    QVariant redirectionTargetUrl =
        reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    // see CS001432 on how to handle this

    // no error received?
    if (reply->error() == QNetworkReply::NoError)
    {
        // read data from QNetworkReply here

        // Example 1: Creating QImage from the reply
        //QImageReader imageReader(reply);
        //QImage pic = imageReader.read();

        // Example 2: Reading bytes form the reply
        QByteArray bytes = reply->readAll();  // bytes
        //QString string(bytes); // string
        QString string = QString::fromUtf8(bytes);

        ui->textBrowser->setText(string);
    }
    // Some http error received
    else
    {
        // handle errors here
    }

    // We receive ownership of the reply object
    // and therefore need to handle deletion.
    reply->deleteLater();
#endif
}
