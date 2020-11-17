/*
*
*
*
*
*
*
*
*
*
*
*/
#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <sqlite3.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct
{
	sqlite3 *DB;
	char *errMsg;
	int conn;	
}Sqlite;

/*
	function : boll connect_database(const char *db,
				Sqlite *bd
	input    : const char *db
			 : Sqlite *sql
	output   : return true on connected to db
			 : return false on failed
*/
void connect_database(const char *db)
{
	errno = 0;
	
	Sqlite *sql = calloc(3, sizeof(Sqlite));			
	if (sql != NULL)
	{
	
		sql->conn = sqlite3_open(db, &sql->DB);
		
		if (sql->conn != SQLITE_OK)
		{
			fprintf(stderr,"[!] Failed To Connect To Database : %s\n",sqlite3_errmsg(sql->DB));
			sqlite3_close(sql->DB);
			exit(EXIT_FAILURE);
		}
		fputs("\n",stdout);
		fprintf(stdout,"Connected\n");
	}
	else
	{
		errno = 0;
		
		fprintf(stderr,"%s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void select_data(const void *id,Sqlite *sql)
{
	sql = calloc(3,sizeof(Sqlite));
	if (sql != NULL)
	{
			
	}
	else
	{
		
	}
}
#endif // DBMANAGER_H
