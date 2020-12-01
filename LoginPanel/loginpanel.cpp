#include "loginpanel.h"
#include <QtWidgets\qgridlayout.h>
#include <qmessagebox.h>
#include <qsqlquery.h>

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass),
	db("localhost",
		"{ODBC Driver 17 for SQL Server}",
		"administrator",
		"12345",
		"login"){

	ui->setupUi(this);
	setSignals();
}

LoginPanel::~LoginPanel(){
	delete ui;
}

void LoginPanel::setSignals(){
	//connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(test()));
	connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(login()));
	connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));

	connect(ui->LogOutButton, SIGNAL(clicked()), this, SLOT(logOut()));

	ui->widgetAfterLogin->setVisible(false);
}

void LoginPanel::login() {
	if (db.openDatabase()) {
		//QMessageBox::information(this, "Login result", "Login is suscess");
		QSqlQuery query("SELECT name,age FROM loginPassword WHERE login='" + ui->loginTxt->text() + "' AND password='" + ui->passwordTxt->text() + "'");

		//QString qStr = "";
		//int age = 0;
		int count = 0;

		while (query.next()) {
			count++;
			//qStr = query.value(0).toString();
			//age = query.value(1).toInt();
		}
		//QMessageBox::information(this, "value", "Name: " + qStr + "\nAge: " + QString::number(age));

		if (count == 1) {
			ui->loginResultText->setText("Login and password are correct.");
			ui->loginResultText->setStyleSheet("color:green");

			ui->loginTxt->clear();
			ui->passwordTxt->clear();
			ui->loginResultText->clear();

			ui->loginWidget->setVisible(false);
			ui->widgetAfterLogin->setVisible(true);
		}
		else {
			ui->loginResultText->setText("Login or password are not correct.");
			ui->loginResultText->setStyleSheet("color:red");
		}

	}
	else {
		QMessageBox::information(this, "Login result", "Login is not suscess");
	}
}

void LoginPanel::logOut(){
	ui->widgetAfterLogin->setVisible(false);
	ui->loginWidget->setVisible(true);
}

void LoginPanel::test(){
	QMessageBox::information(this, "Msg", "Ok");
}

void LoginPanel::quit() {
	QApplication::quit();
}














// https://www.youtube.com/watch?v=6_elY8O20I8

// https://www.youtube.com/watch?v=BYQxCyB-TP4