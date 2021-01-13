#ifndef USER_H
#define USER_H

#include <QString>
#include <QTableWidget>

class User {
	QString userName;
	QString userSurame;
	int userAge;
	bool userActive;

public:
	User(QString &name, QString &surname, int age, bool active);
	void setUserToTable(QTableWidget *userTableWidget);
};

#endif // !USER_H
