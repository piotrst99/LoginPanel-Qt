#include "loginpanel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LoginPanel w;
	w.show();
	return a.exec();
}


// https://www.youtube.com/watch?v=8qozxqSZQEg
