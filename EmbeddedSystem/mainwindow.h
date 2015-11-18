#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <httpmanager.h>
#include <QDebug>
#include <QDateTime>
#include <QTextCodec>
#include <vector>
#include <QMessageBox>
#include <QWebView>
#include <QWebFrame>
#include <QTextStream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    httpManager myManager;

private:
    Ui::MainWindow *ui;
    void InitProperty();
    // void writeHtml();
    void writeHtml();
    QString suggestions;


private slots:
    void pushMessage();
    void placeSuggest();
    void showSelectedItem();
    void btn_clicked();
    void showHtml();
    void myDebug();
};

#endif // MAINWINDOW_H
