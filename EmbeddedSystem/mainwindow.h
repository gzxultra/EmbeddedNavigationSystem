#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <httpmanager.h>
#include <QDebug>

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


private slots:
    void pushTest();
    void placeSuggest();
};

#endif // MAINWINDOW_H
