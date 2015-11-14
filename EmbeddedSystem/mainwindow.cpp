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

}
void MainWindow::pushTest()
{
    qDebug() << "I am called.";
    myManager.setMethod(QString("pushMessage"));
    myManager.setTextBrowser(ui->textBrowser);
    // set URL and Data
    myManager.pushMessage();
}
