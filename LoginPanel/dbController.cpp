#include "dbController.h"

DatabaseConnect::DatabaseConnect(const QString& server,
	const QString& driver,
	const QString& user,
	const QString& password,
	const QString& databaseName)
	:mDatabase(QSqlDatabase::addDatabase("QODBC3")),
	mServer(server),
	mDriver(driver),
	mUser(user),
	mPassword(password),
	mDatabaseName(databaseName){
	/*this->mDatabase = QSqlDatabase::addDatabase("QODBC3");
	this->mDatabaseName = databaseName;
	this->mServer = server;
	this->mDriver = driver;
	this->mUser = user;
	this->mPassword = password;*/
}

DatabaseConnect::~DatabaseConnect(){
	if (mDatabase.open())
		mDatabase.close();
}

bool DatabaseConnect::openDatabase(){
	mDatabase.setDatabaseName(QString("DRIVER={%1};SERVER=%2;DATABASE=%3;UID=%4;PWD=%5")
		.arg(mDriver)
		.arg(mServer)
		.arg(mDatabaseName)
		.arg(mUser)
		.arg(mPassword));

	mDatabase.setDatabaseName(QString("DRIVER="+mDriver+";SERVER="+mServer+";DATABASE="+mDatabaseName+""));
	mDatabase.setUserName(""+mUser+"");
	mDatabase.setPassword(""+mPassword+"");

	//mDatabase.setDatabaseName("DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=login;");
	//mDatabase.setUserName("administrator");
	//mDatabase.setPassword("12345");

	if (!mDatabase.open()) {
		//if (error != nullptr) {
			//*error = mDatabase.lastError().text();
		//}
		return false;
	}
	return true;
}