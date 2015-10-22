#include "widget.h"
#include "ui_widget.h"
#include <QNetworkAccessManager>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::showHttp()
{
    ui->textBrowser->append("hello");
}
