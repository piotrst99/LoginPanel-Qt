#include "loginpanel.h"
#include <qpushbutton.h>

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass) {
	ui->setupUi(this);
	
	loadComponent();
}

LoginPanel::~LoginPanel(){
	delete ui;
}

void LoginPanel::loadComponent(){

}

void LoginPanel::quit() {
	QApplication::quit();
}















// https://www.youtube.com/watch?v=BYQxCyB-TP4