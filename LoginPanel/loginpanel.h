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

private slots:
	void quit();
	void test();

public slots:

};

#endif // !LOGINPANEL_H

