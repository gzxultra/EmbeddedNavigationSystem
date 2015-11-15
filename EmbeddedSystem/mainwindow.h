#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <httpmanager.h>
#include <QDebug>
#include <QDateTime>
#include <QTextCodec>
#include <vector>

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


private slots:
    void pushMessage();
    void placeSuggest();
    void showSelectedItem();
    void btn_clicked();
};

#endif // MAINWINDOW_H
