#include "loginpanel.h"
#include <QtWidgets\qgridlayout.h>
#include <qmessagebox.h>
#include <qsqlquery.h>
#include "verifyData.h"
#include "settingsFunction.h"
#include <QFileDialog>
#include <QBuffer>

LoginPanel::LoginPanel(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::LoginPanelClass),
	db("localhost",
		"{ODBC Driver 17 for SQL Server}",
		"administrator",
		"12345",
		"login"){

	ui->setupUi(this);
	ui->stackedWidget->setCurrentIndex(0);
	ui->settingsStackedWidget->setCurrentIndex(0);
	setSignals();
	setComponents();
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
	connect(ui->settingsButton, SIGNAL(clicked()), this, SLOT(goToSetting()));
	connect(ui->backMenuButton, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui->backMenuButton_2, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui->generalButton, SIGNAL(clicked()), this, SLOT(goToGeneral()));
	connect(ui->privateButton, SIGNAL(clicked()), this, SLOT(goToPrivate()));
	connect(ui->changeNameSettings, SIGNAL(clicked()), this, SLOT(changeNameSurname()));
	connect(ui->addPhotoButton, SIGNAL(clicked()), this, SLOT(addPhoto()));
	connect(ui->changeProfileButton, SIGNAL(clicked()), this, SLOT(changeProfilePhoto()));
	connect(ui->deleteProfileButton, SIGNAL(clicked()), this, SLOT(deleteProfilePhoto()));
	connect(ui->changeEmailSettings, SIGNAL(clicked()), this, SLOT(changeEmail()));
	connect(ui->changePasswordSettings, SIGNAL(clicked()), this, SLOT(changePassword()));
	connect(ui->activeUserButton, SIGNAL(clicked()), this, SLOT(goToActiveUser()));
}

void LoginPanel::setComponents() {
	ui->centralWidget->setStyleSheet("background-color:#353535");
	ui->loginLabel->setStyleSheet("color:white;");
	ui->passwordLabel->setStyleSheet("color:white;");	
	styleLineEdit(ui->loginTxt);
	styleLineEdit(ui->passwordTxt);

	//ui->loginBox->setStyleSheet("border: 4px solid #1C74B2; border-radius: 15px; ");
	ui->loginButton->setStyleSheet("QPushButton{""background-color:#36D62D;" "border-radius:5px;" "outline:none;" "width:75px;" "height:24px;""}" "QPushButton:hover{""background-color:#14B40B;""}");
	ui->registerButton->setStyleSheet("QPushButton{""background-color:#1c74b2;" "border-radius:5px;" "outline:none;" "width:75px;" "height:24px;""}" "QPushButton:hover{""background-color:#0A5290;""}");
	ui->quitButton->setStyleSheet("QPushButton{""background-color:#c20f02;" "border-radius:5px;" "outline:none;" "width:75px;" "height:24px;" "color:#CCC""}" "QPushButton:hover{""background-color:#A00D00;""}");
	
	ui->registerLabel->setStyleSheet("color:white;");
	ui->emailLabel->setStyleSheet("color:white;");
	ui->passwordLabel_2->setStyleSheet("color:white;");
	ui->nameLabel->setStyleSheet("color:white;");
	ui->surnameLabel->setStyleSheet("color:white;");
	ui->ageLabel->setStyleSheet("color:white;");
	styleLineEdit(ui->emailTxt);
	styleLineEdit(ui->passwordTxt_2);
	styleLineEdit(ui->nameTxt);
	styleLineEdit(ui->surnameTxt);
	ui->registerButton_2->setStyleSheet("QPushButton{""background-color:#36D62D;" "border-radius:5px;" "outline:none;" "width:75px;" "height:24px;""}" "QPushButton:hover{""background-color:#14B40B;""}");
	ui->backButton->setStyleSheet("QPushButton{""background-color:#c20f02;" "border-radius:5px;" "outline:none;" "width:75px;" "height:24px;" "color:#CCC""}" "QPushButton:hover{""background-color:#A00D00;""}");

	styleIconButton(ui->settingsButton, QString("..\\LoginPanel\\image\\settingsIcon2.png"));
	styleIconButton(ui->logOutButton, QString("..\\LoginPanel\\image\\logOutIcon2.png"));
	styleIconButton(ui->backMenuButton, QString("..\\LoginPanel\\image\\backIcon2.png"));
	styleIconButton(ui->backMenuButton_2, QString("..\\LoginPanel\\image\\backIcon2.png"));
	//sciezka jest do zmiany i dodac obrazek aktywni uzytkownicy
	styleIconButton(ui->activeUserButton, QString("..\\LoginPanel\\image\\backIcon2.png"));

	ui->welcomeLabel->setStyleSheet("color:#CCC;");
	ui->settingsLabel->setStyleSheet("color:#CCC;");
	ui->nameMainLabel->setStyleSheet("color:#CCC;");
	ui->surnameMainLabel->setStyleSheet("color:#CCC;");
	ui->profilePhoto->setStyleSheet("border: 5px solid white; border-radius:10px;");

	styleButtonInSettings(ui->generalButton);
	styleButtonInSettings(ui->privateButton);

	ui->settingsLeft->setStyleSheet("background-color:#2b333e;");
	ui->topSettingsLeft->setStyleSheet("background-color:#333c48;");
	styleLineEdit(ui->nameTxtSet);
	styleLineEdit(ui->surnameTxtSet);
	ui->nameLabelSet->setStyleSheet("color:white;");
	ui->surnameLabelSet->setStyleSheet("color:white;");
	ui->changeNameSettings->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->addPhotoButton->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->changeProfileButton->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->deleteProfileButton->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->changeEmailSettings->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->changePasswordSettings->setStyleSheet("QPushButton{""background:#626f82;" "border:1px solid #2b333e;" "border-radius:5px;" "width:75px;" "height:24px;" "outline:none;" "color:#CCC""}" "QPushButton:hover{""background-color:#404D60;""}");
	ui->photoLabel->setStyleSheet("color:white;");
	ui->emailSetLabel->setStyleSheet("color:white;");
	ui->passwordSetLabel->setStyleSheet("color:white;");
	ui->changeEmailLabel->setStyleSheet("color:white;");
	ui->changePasswordForEmailLabel->setStyleSheet("color:white;");
	ui->changePasswordLabel->setStyleSheet("color:white;");
	ui->changePasswordLabel_2->setStyleSheet("color:white;");
	ui->changePasswordLabel_3->setStyleSheet("color:white;");
	styleLineEdit(ui->emailTxtSet);
	styleLineEdit(ui->passwordForEmailTxt);
	styleLineEdit(ui->oldPasswordTxt);
	styleLineEdit(ui->newPasswordTxt);
	styleLineEdit(ui->newPasswordTxt_2);

	ui->activeUserLabel->setStyleSheet("color:white;");
}

void LoginPanel::login() {
	if (db.openDatabase()) {
		QSqlQuery query("SELECT id FROM loginPassword WHERE login='" + ui->loginTxt->text() + "' AND password='" + ui->passwordTxt->text() + "'");
		int count = 0;
		while (query.next()) { count++; }
		(count == 1) ? loginResult(true) : loginResult(false);
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}
}

void LoginPanel::loginResult(bool result){
	if (result) {
		QSqlQuery dataQuery("SELECT name,surname,profilePhoto FROM loginPassword WHERE login='" + ui->loginTxt->text() + "'");
		QString name = "";
		QString surname = "";
		QPixmap profilePhoto(150,150);

		while (dataQuery.next()) {
			name = dataQuery.value(0).toString();
			surname = dataQuery.value(1).toString();
			this->name = name;
			this->surname = surname;
			if (dataQuery.value(2).toByteArray() == nullptr) {
				profilePhoto.fill(QColor(255, 255, 255));
				ui->profilePhoto->setPixmap(profilePhoto);
				ui->profilePhotoLabel->setPixmap(profilePhoto);
				email = ui->loginTxt->text();
			}
			else {
				profilePhoto.loadFromData(dataQuery.value(2).toByteArray());
				ui->profilePhoto->setPixmap(profilePhoto);
				ui->profilePhotoLabel->setPixmap(profilePhoto);
			}
		}
		
		ui->nameMainLabel->setText(name);
		ui->surnameMainLabel->setText(surname);

		ui->emailTxtSet->setText(ui->loginTxt->text());
		ui->loginTxt->clear();
		ui->passwordTxt->clear();
		ui->loginResultText->clear();

		ui->stackedWidget->setCurrentIndex(1);

		ui->welcomeLabel->setText("Welcome " + name);

		ui->nameTxtSet->setText(name);
		ui->surnameTxtSet->setText(surname);

		
	}
	else{
		ui->loginResultText->setText("Login or password are not correct.");
		ui->loginResultText->setStyleSheet("color:red");
	}
}

//void LoginPanel::changePage(int indexPage){ui->stackedWidget->setCurrentIndex(indexPage);}

void LoginPanel::logOut(){
	ui->stackedWidget->setCurrentIndex(0);
	ui->welcomeLabel->clear();
	ui->profilePhoto->clear();
	ui->nameTxtSet->clear();
	ui->surnameTxtSet->clear();
	ui->profilePhotoLabel->clear();
	ui->emailTxtSet->clear();
	ui->nameMainLabel->clear();
	ui->surnameMainLabel->clear();
}

void LoginPanel::registerPanel(){
	ui->stackedWidget->setCurrentIndex(2);
	ui->loginResultText->clear();
}

void LoginPanel::backToLogin(){
	ui->stackedWidget->setCurrentIndex(0);

	ui->emailTxt->clear();
	ui->passwordTxt_2->clear();
	ui->nameTxt->clear();
	ui->surnameTxt->clear();
	ui->ageSpinBox->clear();

	ui->emailError->clear();
	ui->passwordError->clear();
	ui->nameError->clear();
	ui->surnameError->clear();
	ui->ageError->clear();
}

void LoginPanel::goToSetting(){
	ui->stackedWidget->setCurrentIndex(3);
}

void LoginPanel::backToMenu(){
	ui->stackedWidget->setCurrentIndex(1);
	clearPrivateSettings();
	setGeneralSettings();
}

void LoginPanel::goToGeneral(){
	ui->settingsStackedWidget->setCurrentIndex(0);
	clearPrivateSettings();
}

void LoginPanel::goToPrivate(){
	ui->settingsStackedWidget->setCurrentIndex(1);
	setGeneralSettings();
}

void LoginPanel::goToActiveUser(){
	ui->stackedWidget->setCurrentIndex(4);
}

void LoginPanel::registerUser(){
	/*bool emailIsCorrect = verifyData::checkEmail(ui->emailTxt->text().toUtf8().constData());
	bool emailIsNotExist = checkEmailIsNotExist(ui->emailTxt->text());
	if (!emailIsCorrect || !emailIsNotExist) {
		ui->emailError->setText("E-mail is not correct or is exist");
		ui->emailError->setStyleSheet("color: red");
	}
	else {
		ui->emailError->setText("E-mail is correct");
		ui->emailError->setStyleSheet("color: green");
	}*/

	bool emailIsCorrect = verifyData::emailCheck(ui->emailTxt->text().toUtf8().constData());
	bool emailIsNotExist = checkEmailIsNotExist(ui->emailTxt->text());
	if (!emailIsCorrect || !emailIsNotExist) {
		ui->emailError->setText("E-mail is not correct or is exist");
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

	if (emailIsCorrect && emailIsNotExist && passwordIsCorrect && nameIsCorrect && surnameIsCorrect && ageIsCorrect) {
		if (db.openDatabase()) {
			QSqlQuery insertQuery;
			insertQuery.exec("INSERT INTO loginPassword (name,surname,age,login,password)" "VALUES ('" + ui->nameTxt->text() + "','" +
				ui->surnameTxt->text() + "','" + ui->ageSpinBox->text() + "','" + ui->emailTxt->text() + "','" + ui->passwordTxt_2->text() + "')");

			QMessageBox::information(this, "Register tesult", "Account has been created.");
		}
		else {
			QMessageBox::information(this, "Database driver", "Database is not open.");
		}
	}
}

void LoginPanel::changeNameSurname(){
	if (db.openDatabase()) {
		QSqlQuery updateQuery;
		updateQuery.exec("UPDATE loginPassword SET name='" + ui->nameTxtSet->text() + "' , surname='" + ui->surnameTxtSet->text() 
			+ "' WHERE login='" + ui->emailTxtSet->text() + "'");
		QMessageBox::information(this, "", "Dates was changed.");
		ui->nameMainLabel->setText(ui->nameTxtSet->text());
		ui->surnameMainLabel->setText(ui->surnameTxtSet->text());
		this->name = ui->nameTxtSet->text();
		ui->nameTxtSet->setText(this->name);
		this->surname = ui->surnameTxtSet->text();
		ui->surnameTxtSet->setText(this->surname);
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}
}

void LoginPanel::addPhoto(){
	QString fileName = QFileDialog::getOpenFileName(this,tr("Load Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
	QPixmap profilePhoto(fileName);
	filePhotoName = fileName;
	ui->profilePhotoLabel->setPixmap(profilePhoto);
}

void LoginPanel::deleteProfilePhoto(){
	if (db.openDatabase()) {
		QPixmap pixmap(150, 150);
		QSqlQuery deletePhotoQuery;
		deletePhotoQuery.exec("UPDATE loginPassword SET profilePhoto=NULL WHERE login='" + ui->emailTxtSet->text() + "' ");
		pixmap.fill(QColor(255, 255, 255));
		ui->profilePhoto->setPixmap(pixmap);
		ui->profilePhotoLabel->setPixmap(pixmap);
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}
}

void LoginPanel::changeProfilePhoto(){
	if (db.openDatabase()) {
		QPixmap pixmap(filePhotoName);
		QSqlQuery query;
		query.exec("UPDATE loginPassword SET profilePhoto=(SELECT * FROM OPENROWSET(BULK '" + filePhotoName + "',SINGLE_BLOB) AS img) WHERE login='" + ui->emailTxtSet->text() + "' ");
		QMessageBox::information(this, "", "Image was saved");
		ui->profilePhoto->setPixmap(pixmap);
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}
}

void LoginPanel::changeEmail(){
	bool passwordIsCorrext = false;
	bool emailIsValid = false;

	if (db.openDatabase()) {
		QString password;
		QSqlQuery getPasswordQuery;
		getPasswordQuery.exec("SELECT password FROM loginPassword WHERE login='" + email + "'");
		while (getPasswordQuery.next()) {
			password = getPasswordQuery.value(0).toString();
			if (password == ui->passwordForEmailTxt->text()) {
				passwordIsCorrext = true;	
			}
			else {
				passwordIsCorrext = false;
			}
		}
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}

	if (passwordIsCorrext) {
		ui->passwordSetError->setText("Password is valid");
		ui->passwordSetError->setStyleSheet("color:green;");
	}
	else {
		ui->passwordSetError->setText("Password is not valid");
		ui->passwordSetError->setStyleSheet("color:red;");
	}

	emailIsValid = verifyData::emailCheck(ui->emailTxtSet->text().toUtf8().constData());
	if (emailIsValid) {
		ui->emailSetError->setText("E-mail is valid");
		ui->emailSetError->setStyleSheet("color:green;");
	}
	else {
		ui->emailSetError->setText("E-mail is not valid");
		ui->emailSetError->setStyleSheet("color:red;");
	}

	if (passwordIsCorrext && emailIsValid) {
		if (db.openDatabase()) {
			int id;
			QSqlQuery getIdQuery;
			getIdQuery.exec("SELECT id FROM loginPassword WHERE login='" + email + "'");
			while (getIdQuery.next()) {
				id = getIdQuery.value(0).toInt();
			}

			QSqlQuery changeEmailQuery;
			changeEmailQuery.exec("UPDATE loginPassword SET login='" + ui->emailTxtSet->text() + "' WHERE id='" + QString::number(id) + "' ");
			QMessageBox::information(this, "", "E-mail is changed.");
			email = ui->emailTxtSet->text();
		}
		else {
			QMessageBox::information(this, "Database driver", "Database is not open.");
		}
		ui->passwordForEmailTxt->clear();
		ui->emailSetError->clear();
		ui->passwordSetError->clear();
	}
}

void LoginPanel::changePassword(){
	bool oldPasswordIsCorrect=false;
	bool newPasswordIsValid = false;

	if (db.openDatabase()) {
		QString password;
		QSqlQuery getPasswordQuery;
		getPasswordQuery.exec("SELECT password FROM loginPassword WHERE login='" + email + "'");
		while (getPasswordQuery.next()) {
			password = getPasswordQuery.value(0).toString();
			if (password == ui->oldPasswordTxt->text()) {
				oldPasswordIsCorrect = true;
			}
			else {
				oldPasswordIsCorrect = false;
			}
		}
	}
	else {
		QMessageBox::information(this, "Database driver", "Database is not open.");
	}

	if (oldPasswordIsCorrect) {
		ui->passwordSetError_2->setText("Password is valid");
		ui->passwordSetError_2->setStyleSheet("color:green;");
	}
	else {
		ui->passwordSetError_2->setText("Password is not valid");
		ui->passwordSetError_2->setStyleSheet("color:red;");
	}

	newPasswordIsValid = (verifyData::checkPassword(ui->newPasswordTxt->text().toUtf8().constData())
		&& verifyData::checkPassword(ui->newPasswordTxt_2->text().toUtf8().constData())
		&& ui->newPasswordTxt->text() == ui->newPasswordTxt_2->text());

	if (newPasswordIsValid) {
		ui->passwordSetError_3->setText("Password are not valid");
		ui->passwordSetError_3->setStyleSheet("color:green;");
	}
	else {
		ui->passwordSetError_3->setText("Password are not valid");
		ui->passwordSetError_3->setStyleSheet("color:red;");
	}

	if (oldPasswordIsCorrect && newPasswordIsValid) {
		if (db.openDatabase()) {
			QSqlQuery checkPasswordQuery;
			checkPasswordQuery.exec("UPDATE loginPassword SET password='"+ui->newPasswordTxt->text()+"' WHERE login='" + email + "'");
			QMessageBox::information(this, "", "Password is changed.");
			ui->oldPasswordTxt->clear();
			ui->newPasswordTxt->clear();
			ui->newPasswordTxt_2->clear();
			ui->passwordSetError_2->clear();
			ui->passwordSetError_3->clear();
		}
		else {
			QMessageBox::information(this, "Database driver", "Database is not open.");
		}
	}
}

bool LoginPanel::checkEmailIsNotExist(QString email) {
	if (db.openDatabase()) {
		QSqlQuery query("SELECT id FROM loginPassword WHERE login='" + ui->emailTxt->text() + "'");
		int count = 0;
		while (query.next()) { count++; }
		return (count == 0) ? true : false;
	}
	else {
		return false;
	}
}

void LoginPanel::clearPrivateSettings(){
	ui->emailTxtSet->setText(email);
	ui->passwordForEmailTxt->clear();
	ui->emailSetError->clear();
	ui->passwordSetError->clear();
	ui->oldPasswordTxt->clear();
	ui->newPasswordTxt->clear();
	ui->newPasswordTxt_2->clear();
	ui->passwordSetError_2->clear();
	ui->passwordSetError_3->clear();
}

void LoginPanel::setGeneralSettings(){
	ui->nameTxtSet->setText(this->name);
	ui->surnameTxtSet->setText(this->surname);
}

void LoginPanel::quit() {
	QApplication::quit();
}