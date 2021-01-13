#include "User.h"

User::User(QString &name, QString &surname, int age, bool active) 
	:userName(name), userSurame(surname), userAge(age), userActive(active) {}

void User::setUserToTable(QTableWidget *usersTable){
	int index = usersTable->rowCount();
	usersTable->setRowCount(index + 1);

	QTableWidgetItem *nameItem = new QTableWidgetItem(this->userName);
	nameItem->setBackground(Qt::gray);
	usersTable->setItem(index, 0, nameItem);
	QTableWidgetItem *surnameItem = new QTableWidgetItem(this->userSurame);
	surnameItem->setBackground(Qt::gray);
	usersTable->setItem(index, 1, surnameItem);
	QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(this->userAge));
	ageItem->setBackground(Qt::gray);
	usersTable->setItem(index, 2, ageItem);
	QTableWidgetItem *activeItem = new QTableWidgetItem(this->userActive ? "Yes" : "No");
	activeItem->setBackground(Qt::gray);
	usersTable->setItem(index, 3, activeItem);
}


