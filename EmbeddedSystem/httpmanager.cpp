
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
    if(myMethod == "placeSuggest")
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
   // qDebug() << "FinishedSlot is being called.";
    if (reply->error() == QNetworkReply::NoError)
    {
        std::cerr << "Success: " << std::endl;
        QByteArray bytes = reply->readAll();  // bytes
        QString string = QString::fromUtf8(bytes);
        response = string;
    }
    else
        std::cerr << "Error: " << qPrintable(reply->errorString())
                  << std::endl;
    reply->deleteLater();

    switch (method) {
        case '1':{
            qDebug() << "Finished Slot: pushMessageReplyHandler.";
            pushMessageReplyHandler();
            break;
        }
        case '3':{
            qDebug() << "Finished Slot: placeSuggestReplyHandler.";
            placeSuggestReplyHandler();
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

    qDebug() << postData;

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentLengthHeader, postData.length());

    this->manager->post(request, postData);
}

void httpManager::placeSuggest()
{
    qDebug() << "start suggest places.";

    QNetworkRequest request(url);

    this->manager->get(request);
}

void httpManager::setTextBrowser(QTextBrowser *myTextBrowser)
{
    textBrowser = myTextBrowser;
}

void httpManager::setListWidget(QListWidget *myListWidget)
{
    listWidget = myListWidget;
}

void httpManager::setLineEdit(QLineEdit *myLineEdit)
{
    lineEdit = myLineEdit;
}

void httpManager::pushMessageReplyHandler()
{
    textBrowser->setText(response);
    qDebug() << response;
}

void httpManager::placeSuggestReplyHandler()
{
    parser.setShowWidget(listWidget, lineEdit);
    // qDebug() << response;

    qDebug() << "in Place Suggest Reply Handler";
    textBrowser->setText(response);


    QFile xmlFile("place_suggestion_response.xml");
    if (!xmlFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        std::cerr << "Cannot open file for writing:" << qPrintable(xmlFile.errorString()) << std::endl;
        return;
    }
    QTextStream out(&xmlFile);
    out << response;
    xmlFile.close();

    // xmlFile.close();

    listWidget->clear();
    // bugs on listWidget.
    qDebug() << "start parse xml file.";
    parser.readFile("place_suggestion_response.xml");
    qDebug() << "parser done.";
}
