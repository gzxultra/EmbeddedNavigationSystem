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

signals:
    void finished();

private:
    Ui::Widget *ui;
    class QNetworkAccessManager *nam;

private slots:
    void insertData();
    void queryData();
    void httpPost();
    void finishedSlot(QNetworkReply *);
};


#endif // WIDGET_H

