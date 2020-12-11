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

	void setSignals();
	void loginResult(bool result);

private slots:
	void login();
	void quit();
	void logOut();
	void registerPanel();
	void backToLogin();

public slots:

};

#endif // !LOGINPANEL_H

