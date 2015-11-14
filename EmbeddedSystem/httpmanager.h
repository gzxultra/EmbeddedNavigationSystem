#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QTextBrowser>

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
    void setTextBrowser(QTextBrowser *myTextBrowser);

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
    QTextBrowser *textBrowser;
    QString response;

    // ...
};

#endif // HTTPMANAGER_H
