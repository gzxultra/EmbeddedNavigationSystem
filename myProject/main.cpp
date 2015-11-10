#include "widget.h"
#include <QApplication>

// class of splash
#include <QSplashScreen>
#include <QDesktopWidget>

// sensor drive
#include "sht11_test.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec *codec = QTextCodec::codecForName("UTF-8");
	QTextCodec::setCodecForTr(codec);

	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap(":/images/plash.png").scaled(480, 640));
	// splash->setPixmap(QPixmap(":/images/plash.png").scaled(400, 300, Qt::KeepAspectRatio));
	splash->show();
	// sleep(1);
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	splash->showMessage(QObject::tr("Setting up the main window..."));
	// sleep(1);
	Widget w;

	w.move ((QApplication::desktop()->width() - w.width()) / 2, (QApplication::desktop()->height() - w.height()) / 2);

	splash->showMessage(QObject::tr("Loading modules..."), topRight, Qt::black);
	w.createConnection();
	//callSensor();
	splash->showMessage(QObject::tr("Establishing connections"));


	w.show();
	splash->finish(&w);
	delete splash;

	return a.exec();
}


