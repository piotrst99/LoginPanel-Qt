#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QtWidgets/QMainWindow>
#include "ui_loginpanel.h"
#include "dbController.h"

class LoginPanel : public QMainWindow
{
	Q_OBJECT

public:
	LoginPanel(QWidget *parent = Q_NULLPTR);
	~LoginPanel();
	//virtual ~LoginPanel();

private:
	Ui::LoginPanelClass *ui;
	DatabaseConnect db;

	QString email;

	void setSignals();
	void setComponents();
	void loginResult(bool result);
	bool checkEmailIsNotExist(QString email);

private slots:
	void login();
	void quit();
	void logOut();
	void registerPanel();
	void backToLogin();
	void goToSetting();
	void backToMenu();
	void goToGeneral();
	void goToPrivate();
	//void changePage(int page);
	void registerUser();
	void changeNameSurname();

public slots:

};

#endif // !LOGINPANEL_H

