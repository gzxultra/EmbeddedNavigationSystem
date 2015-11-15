#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->hide();
    this->InitProperty();
    /*
    QString localHostName = QHostInfo::localHostName();
    qDebug() <<"localHostName: "<<localHostName;
    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug() << "IP Address: "<<info.addresses();
    */
    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn) {
        connect(b, SIGNAL(clicked()), this, SLOT(btn_clicked()));
    }

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

void MainWindow::btn_clicked()
{
    QPushButton *btn = (QPushButton *)sender();
    QString objectName = btn->objectName();
    QString value = btn->text();

    if (objectName == "btnDelete")
    {
        ui->lineEdit->setText(ui->lineEdit->text().left(ui->lineEdit->text().length() - 1));
    }else if (objectName == "btnSpace")
    {
        ui->lineEdit->setText(ui->lineEdit->text() + " ");
    }
    else if(btn->property("btnLetter").toBool())
    {
        ui->lineEdit->setText(ui->lineEdit->text() + value);
    }

}

void MainWindow::InitProperty()
{
    ui->btna->setProperty("btnLetter", true);
    ui->btnb->setProperty("btnLetter", true);
    ui->btnc->setProperty("btnLetter", true);
    ui->btnd->setProperty("btnLetter", true);
    ui->btne->setProperty("btnLetter", true);
    ui->btnf->setProperty("btnLetter", true);
    ui->btng->setProperty("btnLetter", true);
    ui->btnh->setProperty("btnLetter", true);
    ui->btni->setProperty("btnLetter", true);
    ui->btnj->setProperty("btnLetter", true);
    ui->btnk->setProperty("btnLetter", true);
    ui->btnl->setProperty("btnLetter", true);
    ui->btnm->setProperty("btnLetter", true);
    ui->btnn->setProperty("btnLetter", true);
    ui->btno->setProperty("btnLetter", true);
    ui->btnp->setProperty("btnLetter", true);
    ui->btnq->setProperty("btnLetter", true);
    ui->btnr->setProperty("btnLetter", true);
    ui->btns->setProperty("btnLetter", true);
    ui->btnt->setProperty("btnLetter", true);
    ui->btnu->setProperty("btnLetter", true);
    ui->btnv->setProperty("btnLetter", true);
    ui->btnw->setProperty("btnLetter", true);
    ui->btnx->setProperty("btnLetter", true);
    ui->btny->setProperty("btnLetter", true);
    ui->btnz->setProperty("btnLetter", true);

    ui->btnDelete->setProperty("btnOther", true);
    ui->btnReturn->setProperty("btnOther", true);
    ui->btnSpace->setProperty("btnOther", true);
    ui->btnFn->setProperty("btnOther", true);

    ui->pushButton->setProperty("btnAction", true);
}
