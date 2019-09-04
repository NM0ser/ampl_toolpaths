#include "stdafx.h"

#include "QtOcct.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtOcct w;
	w.show();
	return a.exec();
}
