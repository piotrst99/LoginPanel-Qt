#include "loginpanel.h"
#include <qpushbutton.h>
#include <QtWidgets\qgridlayout.h>
#include <QLabel>
#include <QLineEdit>
#include <qmessagebox.h>

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass) {
	ui->setupUi(this);
	
	loadComponent()->show();
}

LoginPanel::~LoginPanel(){
	delete ui;
}

QWidget *LoginPanel::loadComponent(){
	QWidget* loginWindow = new QWidget(this);
	loginWindow->setGeometry(20, 20, 250, 100);
	
	QGridLayout* loginlayout = new QGridLayout();

	QLabel* loginLabel = new QLabel("Login:");
	QLineEdit* loginTxt = new QLineEdit;

	QLabel* passwordLabel = new QLabel("Password:");
	QLineEdit* passwordTxt = new QLineEdit;
	passwordTxt->setEchoMode(QLineEdit::Password);

	QPushButton* loginButton = new QPushButton("Login");
	loginButton->setFixedSize(80, 25);
	connect(loginButton, SIGNAL(clicked()), this, SLOT(test()));
	//connect(loginButton, SIGNAL(clicked()), this, SLOT(quit()));
	
	loginlayout->addWidget(loginLabel, 0, 0);
	loginlayout->addWidget(loginTxt, 0, 1);

	loginlayout->addWidget(passwordLabel, 1, 0);
	loginlayout->addWidget(passwordTxt, 1, 1);

	loginlayout->addWidget(loginButton,2,1);

	loginWindow->setLayout(loginlayout);
	//loginWindow->show();

	return loginWindow;
}

void LoginPanel::test(){
	if ("atr" == "Piotr"){
		QMessageBox::information(this, "Msg", "Ok");
	}
	else {
		QMessageBox::information(this, "Msg", "Nie ok");
	}
}

void LoginPanel::quit() {
	QApplication::quit();
}















// https://www.youtube.com/watch?v=BYQxCyB-TP4