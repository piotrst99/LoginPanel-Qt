#include "loginpanel.h"
#include <qpushbutton.h>
#include <QtWidgets\qgridlayout.h>
#include <QLabel>
#include <QLineEdit>
#include <qmessagebox.h>

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass) {
	ui->setupUi(this);
}

LoginPanel::~LoginPanel(){
	delete ui;
}


void LoginPanel::test(){
	QMessageBox::information(this, "Msg", "Ok");
}

void LoginPanel::quit() {
	QApplication::quit();
}













// https://www.youtube.com/watch?v=6_elY8O20I8

// https://www.youtube.com/watch?v=BYQxCyB-TP4