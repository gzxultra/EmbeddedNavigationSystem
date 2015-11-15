#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::placeSuggest()
{
    qDebug() << "placeSuggest is called.";
    myManager.setMethod("placeSuggest");
    myManager.setTextBrowser(ui->textBrowser);
    myManager.setLineEdit(ui->lineEdit);
    myManager.setListWidget(ui->listWidget);

    QString input = ui->lineEdit->text();

    QString region = QByteArray("全国").toPercentEncoding();

    QByteArray originRequest = "http://api.map.baidu.com/place/v2/suggestion?";
    originRequest.append("query=");
    originRequest.append(input);
    originRequest.append("&region=");
    originRequest.append(region);
    originRequest.append("&output=xml&ak=PAWBPVqwwomy8UBoeeUm9dfo");

    myManager.setUrl(QUrl(originRequest));

    myManager.placeSuggest();


}
void MainWindow::pushMessage()
{
    qDebug() << "pushMessage is called.";
    myManager.setMethod(QString("pushMessage"));
    myManager.setTextBrowser(ui->textBrowser);

    myManager.setUrl(QUrl("https://api.submail.cn/message/xsend.json"));

    QByteArray postConstruction  = "appid=10586&to=18651370755&project=d7skN4&signature=0bd4add5f563accb8f04f8b835e453f5";
    postConstruction.append("&vars={\"code\":\"");
    postConstruction.append("Currently, I am still working on it. ");
    postConstruction.append(QDateTime::currentDateTime().toString());
    postConstruction.append("\"}");
    myManager.setPostData(postConstruction);

    myManager.pushMessage();
}

void MainWindow::showSelectedItem()
{
    ui->lineEdit->clear();
    // QObject::disconnect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(placeSuggest()));
    QListWidgetItem *item = ui->listWidget->currentItem();
    qDebug() << item;
    if(item != 0x0)
        ui->lineEdit->setText(ui->listWidget->currentItem()->text());
    else
        qDebug() << "small glinches";
    qDebug() << "set text successfully.";
}
