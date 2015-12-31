#include "rmmv.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RMMV w;
	w.show();
	return a.exec();
}
