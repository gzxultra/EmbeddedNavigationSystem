#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QWidget>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QTextBrowser>
#include <QListWidget>
#include <QLineEdit>
#include "xmlparser.h"

class httpManager : public QObject
{
    Q_OBJECT
public:
    explicit httpManager(QObject *parent = 0);
    void setUrl(QUrl myUrl);
    // QUrl getUrl();
    void setPostData(const QByteArray &myPostData);
    // QString getPostData();
    void setMethod(QString myMethod);
    // QString getMethod();
    void pushMessage();
    void placeSuggest();
    void setTextBrowser(QTextBrowser *myTextBrowser);
    void setListWidget(QListWidget *myListWidget);
    void setLineEdit(QLineEdit *myLineEdit);
    XmlParser parser;

signals:
    void finished();

private slots:
    void finishedSlot(QNetworkReply *);

private:
    class QNetworkAccessManager *manager;

    QUrl url;
    QByteArray postData;
    char method;

    void pushMessageReplyHandler();
    void placeSuggestReplyHandler();
    QTextBrowser *textBrowser;
    QListWidget *listWidget;
    QLineEdit *lineEdit;
    QString response;

    // ...
};

#endif // HTTPMANAGER_H
