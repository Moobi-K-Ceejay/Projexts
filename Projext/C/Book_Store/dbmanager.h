#ifndef DBMANAGER_H
#define DBMANAGER_H


#include <sqlite3.h>
#include <stdio.h>

typedef struct
{
	sqlite3 *db;
	char *zErrMsg;
	int conn;

	void *connectDatabase();
	void *sign_up();
	void *login();
}Database;

#endif