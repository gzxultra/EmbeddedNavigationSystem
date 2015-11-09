#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMessageBox>
#include <QTextCodec>

#include <QTime>
#include <QDateTime>

#include <QtDebug>

// class of database
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>

// class of network
#include <QNetworkReply>
#include <QNetworkRequest>

// class of xml parser
// #include <QXmlStreamReader>
#include <QtXml/QtXml>
#include <QXmlStreamReader>

// class of file
#include <QTextStream>
#include <QFile>
#include <QIODevice>

// std io class
#include <iostream>

#include <xmlstreamreader.h>



namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool createConnection();

    XmlStreamReader reader;

signals:
    void finished();

private:
    Ui::Widget *ui;
    class QNetworkAccessManager *nam;
    void PercentEncoding2ByteArray(QString strInput, QByteArray & ByteArrayOut);

    QString response;
    bool flag = false;


private slots:
    void insertData();
    void queryData();

    void finishedSlot(QNetworkReply *);

    void pushMessage();
    void getBaiduWeather();
    void placeSuggestion();

    void functionChooser();
    void debug();


};


#endif // WIDGET_H

