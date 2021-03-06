#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->hide();
    this->InitProperty();

    // Q_INIT_RESOURCE(web);
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
    myManager.setMainWindow(this);
    QString telephoneNumber = ui->telephoneInput->text();
    if (telephoneNumber.length() != 11)
    {
        QMessageBox::about(this,tr("提示信息"),tr("您输入的手机号有误！"));
        return;
    }
    qDebug() << "pushMessage is called.";
    myManager.setMethod(QString("pushMessage"));
    myManager.setTextBrowser(ui->textBrowser);

    myManager.setUrl(QUrl("https://api.submail.cn/message/xsend.json"));

    QByteArray postConstruction  = "appid=10586&to=";
    postConstruction.append(telephoneNumber);
    postConstruction.append("&project=d7skN4&signature=8202eb5e44a5519cd0b989a696a60cec");
    postConstruction.append("&vars={\"code\":\"");
    myDebug();
    postConstruction.append(this->suggestions);
    postConstruction.append("Currently, I am still working on it. ");
    postConstruction.append(QDateTime::currentDateTime().toString());
    postConstruction.append("\"}");
    myManager.setPostData(postConstruction);

    myManager.pushMessage();
    ui->telephoneInput->clear();
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

void MainWindow::showHtml()
{
    ui->webView->setZoomFactor(1.0);
    writeHtml();
    qDebug() << "show Html.";

    QString currentPath = QDir::currentPath();
    currentPath = "file:///" + currentPath + "/map.html";
    qDebug() << "html path: " << currentPath;

    ui->webView->load(QUrl(currentPath));


    //ui->webView->load(QUrl("file://qrc:/data/map.html"));
}

void MainWindow::writeHtml()
{
    QString currentPath = QDir::currentPath();
    currentPath = currentPath + "/map.html";
    qDebug() << "file path: " << currentPath;


    //QFile file("qrc:/data/map.html");
    QFile file(currentPath);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        std::cerr << "Open failed.\n";
        return;
    }
    QString html;

    QTextStream txt(&file);
    for (int i = 0; i <=48; ++i){
        html.append(txt.readLine());
        html.append("\n");
    }
    QString destination = ui->lineEdit->text();

    html.append("transit.search(\"北京工业大学\", \"");
    html.append(destination);
    html.append("\");\n</script>");

    txt.seek(0);
    txt << html;

    file.close();
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
    else if (btn->property("btnLetter").toBool())
    {
        ui->lineEdit->setText(ui->lineEdit->text() + value);
    }
    else if (objectName == "btnReturn")
    {
        showHtml();
    }

}

void MainWindow::myDebug()
{
    qDebug() << "get suggestions.";
    QString buff = ui->webView->page()->mainFrame()->toPlainText();
    buff = buff.replace("©", "");
    buff = buff.replace("&", "");
    buff = buff.replace("\n", " ");
    suggestions = buff.trimmed();
    qDebug() << suggestions;

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

    ui->btnDelete->setProperty("btnCommand", true);
    ui->btnReturn->setProperty("btnCommand", true);
    ui->btnSpace->setProperty("btnCommand", true);
    ui->btnFn->setProperty("btnCommand", true);

    ui->messageButton->setProperty("btnAction", true);
}
