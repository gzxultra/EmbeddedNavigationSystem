
#include "http.h"

http::http(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    if(QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*))))
        qDebug("connected.");
}

void http::setMethod(QString myMethod)
{
    method = myMethod;
}

void http::setPostData(const QByteArray &myPostData)
{
    postData.append(myPostData);
}

void http::setUrl(QUrl myUrl)
{
    url = myUrl;
}

void http::finishedSlot(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}




