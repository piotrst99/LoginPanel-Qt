#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QtWidgets/QMainWindow>
#include "ui_loginpanel.h"

class LoginPanel : public QMainWindow
{
	Q_OBJECT

public:
	LoginPanel(QWidget *parent = Q_NULLPTR);
	~LoginPanel();

private:
	Ui::LoginPanelClass *ui;
	void loadComponent();

};

#endif // !LOGINPANEL_H

