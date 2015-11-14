
#include "httpmanager.h"

httpManager::httpManager(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    if(QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*))))
        qDebug("connected.");
}

void httpManager::setMethod(QString myMethod)
{
    if(myMethod == "pushMessage")
        method = '1';
    if(myMethod == "baiduWeather")
        method = '2';
    if(myMethod == "placeSuggeste")
        method = '3';

    qDebug() << "method has set to " << method;
}

void httpManager::setPostData(const QByteArray &myPostData)
{
    postData.clear();
    postData.append(myPostData);
}

void httpManager::setUrl(QUrl myUrl)
{
    url = myUrl;
}

void httpManager::finishedSlot(QNetworkReply *reply)
{
   // qDebug() << "I am in finishedSlot.";
    //qDebug() << reply->readAll();
    response = reply->readAll();

    switch (method) {
        case '1':{
            qDebug() << "I am in finishedSlot.";
            pushMessageReplyHandler();
            break;
        }
        default:
        {
            qDebug() << "still working on it";
            break;
        }
    }

}

void httpManager::pushMessage()
{
    // this->browser = textBrowser;
    qDebug() << "start pushing message.";
    setUrl(QUrl("https://api.submail.cn/message/xsend.json"));
    QByteArray postConstruction  = "appid=10586&to=18651370755&project=d7skN4&signature=0bd4add5f563accb8f04f8b835e453f5";
    postConstruction.append("&vars={\"code\":\"");
    postConstruction.append("Currently, I am still working on it.");
    postConstruction.append("\"}");

    setPostData(postConstruction);

    qDebug() << postData;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, postData.length());

    this->manager->post(request, postData);
}

void httpManager::setTextBrowser(QTextBrowser *myTextBrowser)
{
    textBrowser = myTextBrowser;
}

void httpManager::pushMessageReplyHandler()
{
    textBrowser->setText(response);
    qDebug() << response;
}
