
#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>

class http : public QObject
{
    Q_OBJECT
public:
    explicit http(QObject *parent = 0);
    void setUrl(QUrl myUrl);
    // QUrl getUrl();
    void setPostData(const QByteArray &myPostData);
    // QString getPostData();
    void setMethod(QString myMethod);
    // QString getMethod();

signals:
    void finished();

private slots:
    void finishedSlot(QNetworkReply *);

private:
    class QNetworkAccessManager *manager;
    QUrl url;
    QByteArray postData;
    QString method;

};

#endif // HTTP_H

