#include "loginpanel.h"
#include <qpushbutton.h>
#include "components.h"
#include <QGroupBox>

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

void LoginPanel::quit(){
	QApplication::exit();
}


// qgridlayout














// https://www.youtube.com/watch?v=BYQxCyB-TP4

// https://www.youtube.com/watch?v=J_Clau1bYco