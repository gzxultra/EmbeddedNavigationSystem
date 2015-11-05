#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMessageBox>
#include <QTextCodec>

#include <QTime>

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


private:
    Ui::Widget *ui;

private slots:
    void insertData();
    void queryData();
    void httpPost();
};


#endif // WIDGET_H

