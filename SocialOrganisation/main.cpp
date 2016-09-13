#include "SocialApplication.h"
#include <QtWidgets/QApplication>
#include <qsplashscreen.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPixmap pix(":/splashImage.png");
	QSplashScreen splash(pix);
	splash.setWindowTitle("asdf");
	
	splash.showMessage("");
	a.processEvents();


	SocialApplication w;
	w.show();
	splash.finish(&w);
	return a.exec();
}