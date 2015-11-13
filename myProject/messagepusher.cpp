#include "messagepusher.h"
#include "QDateTime"

messagePusher::messagePusher(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
    if(QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*))))
        qDebug("connected.");
    //QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //connect(manager, SIGNAL(finished(QNetworkReply*)),
      //      this, SLOT(replyFinished(QNetworkReply*)));

}

void messagePusher::setMessage(QString string)
{
    message = string;
}

QString messagePusher::getMessage()
{
    //this->setMessage(QString("nothing."));
    return this->message;
}

bool messagePusher::pushMessage(QTextBrowser *textBrowser)
{

    this->browser = textBrowser;

    QUrl url = QUrl("https://api.submail.cn/message/xsend.json");
    QByteArray post_data = "appid=10586&to=18651370755&project=d7skN4&signature=0bd4add5f563accb8f04f8b835e453f5";

    // here add your vars and date
    post_data.append("&vars={\"code\":\"" + QDateTime::currentDateTime().toString() + "\"}");

    qDebug() << post_data;

    QNetworkRequest request(url);
    // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    // request.setHeader(QNetworkRequest::ContentLengthHeader, post_data.length());

    this->manager->post(request, post_data);

    return true;
}

void messagePusher::finishedSlot(QNetworkReply *reply)
{
    // due to some unknown reasons, it doesn't work
    qDebug() << "wow, it works!";
    QString response;
    if (reply->error() == QNetworkReply::NoError)
    {
        std::cerr << "Success: " << std::endl;
        QByteArray bytes = reply->readAll();  // bytes
        response = QString::fromUtf8(bytes);
    }
    else
        std::cerr << "Error: " << qPrintable(reply->errorString())
                  << std::endl;
    // emit finished();
    reply->deleteLater();

    qDebug() << response;
    this->browser->setText(response);

}
