#include "loginpanel.h"
#include <QtWidgets\qgridlayout.h>
#include <qmessagebox.h>
#include <qsqlquery.h>
#include "verifyData.h"

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass),
	db("localhost",
		"{ODBC Driver 17 for SQL Server}",
		"administrator",
		"12345",
		"login"){

	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
	setSignals();
}

LoginPanel::~LoginPanel(){
	delete ui;
}

void LoginPanel::setSignals(){
	connect(ui->loginButton, SIGNAL(clicked()), this, SLOT(login()));
	connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quit()));
	connect(ui->logOutButton, SIGNAL(clicked()), this, SLOT(logOut()));
	connect(ui->registerButton, SIGNAL(clicked()), this, SLOT(registerPanel()));
	connect(ui->backButton, SIGNAL(clicked()), this, SLOT(backToLogin()));
	connect(ui->registerButton_2, SIGNAL(clicked()), this, SLOT(registerUser()));
}


void LoginPanel::login() {
	if (db.openDatabase()) {
		QSqlQuery query("SELECT id FROM loginPassword WHERE login='" + ui->loginTxt->text() + "' AND password='" + ui->passwordTxt->text() + "'");

		int count = 0;

		while (query.next()) {
			count++;
		}

		if (count == 1) {
			loginResult(true);
		}
		else {
			loginResult(false);
		}

	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}
}

void LoginPanel::loginResult(bool result){
	if (result) {
		QSqlQuery dataQuery("SELECT name, age FROM loginPassword WHERE login='" + ui->loginTxt->text() + "'");
		QString name = "";
		int age = 0;

		while (dataQuery.next()) {
			name = dataQuery.value(0).toString();
			age = dataQuery.value(1).toInt();
		}

		ui->loginTxt->clear();
		ui->passwordTxt->clear();
		ui->loginResultText->clear();

		ui->stackedWidget->setCurrentIndex(1);

		ui->welcomeLabel->setText("Welcome " + name + " " + QString::number(age));
	}
	else{
		ui->loginResultText->setText("Login or password are not correct.");
		ui->loginResultText->setStyleSheet("color:red");
	}
}

//void LoginPanel::changePage(int indexPage){ui->stackedWidget->setCurrentIndex(indexPage);}

void LoginPanel::logOut(){
	ui->stackedWidget->setCurrentIndex(0);
}

void LoginPanel::registerPanel(){
	ui->stackedWidget->setCurrentIndex(2);
}

void LoginPanel::backToLogin(){
	ui->stackedWidget->setCurrentIndex(0);
}

void LoginPanel::registerUser(){
	bool emailIsCorrect = verifyData::checkEmail(ui->emailTxt->text().toUtf8().constData());
	//QMessageBox::information(this, "", QString::number(emailIsCorrect));
	if (!emailIsCorrect) {
		ui->emailError->setText("E-mail is not correct");
		ui->emailError->setStyleSheet("color: red");
	}
	else {
		ui->emailError->setText("E-mail is correct");
		ui->emailError->setStyleSheet("color: green");
	}

	bool passwordIsCorrect = verifyData::checkPassword(ui->passwordTxt_2->text().toUtf8().constData());
	if (!passwordIsCorrect) {
		ui->passwordError->setText("Password is not correct");
		ui->passwordError->setStyleSheet("color: red");
	}
	else {
		ui->passwordError->setText("Password is correct");
		ui->passwordError->setStyleSheet("color: green");
	}

	bool nameIsCorrect = verifyData::checkName(ui->nameTxt->text().toUtf8().constData());
	if (!nameIsCorrect) {
		ui->nameError->setText("Name is not correct");
		ui->nameError->setStyleSheet("color: red");
	}
	else {
		ui->nameError->setText("Name is correct");
		ui->nameError->setStyleSheet("color: green");
	}

	bool surnameIsCorrect = verifyData::checkName(ui->surnameTxt->text().toUtf8().constData());
	if (!surnameIsCorrect) {
		ui->surnameError->setText("Surname is not correct");
		ui->surnameError->setStyleSheet("color: red");
	}
	else {
		ui->surnameError->setText("Surname is correct");
		ui->surnameError->setStyleSheet("color: green");
	}

	bool ageIsCorrect = verifyData::checkAge(ui->ageSpinBox->text().toInt());
	if (!ageIsCorrect) {
		ui->ageError->setText("Age must be greater than 0");
		ui->ageError->setStyleSheet("color: red");
	}
	else {
		ui->ageError->setText("Age is correct");
		ui->ageError->setStyleSheet("color: green");
	}
}

void LoginPanel::quit() {
	QApplication::quit();
}















// https://www.youtube.com/watch?v=6_elY8O20I8

// https://www.youtube.com/watch?v=BYQxCyB-TP4