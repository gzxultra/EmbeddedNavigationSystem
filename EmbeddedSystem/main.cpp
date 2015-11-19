#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QSplashScreen *splash = new QSplashScreen;
    MainWindow w;

    splash->setPixmap(QPixmap(":/data/splash.jpg").scaled(640, 480));
    // splash->setPixmap(QPixmap(":/dataplash.png").scaled(400, 300, Qt::KeepAspectRatio));
    splash->show();
    w.show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    w.move ((QApplication::desktop()->width() - w.width()) / 2, (QApplication::desktop()->height() - w.height()) / 2);
    splash->showMessage(QObject::tr("Setting up the main window..."));
    sleep(1);

    splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::black);

    splash->finish(&w);
    delete splash;

    return a.exec();
}
