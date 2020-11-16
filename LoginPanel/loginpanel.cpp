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
	QPushButton *button = new QPushButton("&Kliknij", this);
	button->setGeometry(100, 100, 80, 30);
	connect(button, SIGNAL(clicked()), this, SLOT());
}

















// https://www.youtube.com/watch?v=BYQxCyB-TP4