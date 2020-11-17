#include <stdlib.h>
#include <stdio.h>
#include "dbmanager.h"

Database *db = calloc(sizeof(Database),6);

void *connectDatabase()
{
	db.conn = sqlite3_open("database.db");
}