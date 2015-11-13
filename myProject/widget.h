#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMessageBox>
#include <QTextCodec>

#include <QTime>
#include <QDateTime>

#include <QtDebug>

// database interface
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>

// network handler
#include <QNetworkReply>
#include <QNetworkRequest>

// xml file output handler
#include <QTextStream>
#include <QFile>
#include <QIODevice>

// std input/output
#include <iostream>

// parser
#include <xmlstreamreader.h>

// Qt xml reader
#include <QtXml/QtXml>
#include <QXmlStreamReader>

// push message
#include <messagepusher.h>

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
   // messagePusher pusher;

signals:
    void finished();

private:
    Ui::Widget *ui;
    class QNetworkAccessManager *nam;

    QString response;

private slots:
    void insertData();
    void queryData();

    void finishedSlot(QNetworkReply *);

    void pushMessage();
    void getBaiduWeather();
    void placeSuggestion();

    void functionChooser();
    void debug();

    void showSelectedItemOnLineEdit();
    void setHtmlData();

};


#endif // WIDGET_H

