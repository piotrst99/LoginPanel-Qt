#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include <QSqlDatabase>

class DatabaseConnect {
	QSqlDatabase mDatabase;
	QString mServer;
	QString mDriver;
	QString mUser;
	QString mPassword;
	QString mDatabaseName;
	bool mTrustedConnection;
public:
	DatabaseConnect(const QString& server,
		const QString& driver,
		const QString& user,
		const QString& password,
		const QString& databaseName);
	bool openDatabase();
	~DatabaseConnect();
};

#endif // !DBCONTROLLER_H
