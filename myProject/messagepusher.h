#ifndef MESSAGEPUSHER_H
#define MESSAGEPUSHER_H

#include <QObject>
#include <QTextBrowser>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <iostream>
#include <QUrl>


class messagePusher : public QObject
{
    Q_OBJECT
public:
    explicit messagePusher(QObject *parent = 0);
    void setMessage(QString string);
    QString getMessage();
    bool pushMessage(QTextBrowser *textBrowser);

signals:
    void finished();

private:
    class QNetworkAccessManager *manager;
    QString message;

    QTextBrowser *browser;

private slots:
    void finishedSlot(QNetworkReply *);

};

#endif // MESSAGEPUSHER_H
