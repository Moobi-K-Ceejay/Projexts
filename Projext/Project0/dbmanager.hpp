/*
*************************************************
*												*
*
*
*											    *
*************************************************
*/
#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>
#include <errno.h>

typedef struct
{
	PGconn *conn;
		
}Database;


void exit_good(PGconn *conn)
{
	PQfinish(conn);
	exit(EXIT_FAILURE);
}
// func to connect to database
void connect_database(Database *db)
{
	(*db).conn = PQconnectdb("user=regalo dbname=MusicStore");

	// check if connection is established
	if (PQstatus((*db).conn) != CONNECTION_OK)
	{
		fprintf(stderr,"[!] Failed To Connect To Database : %s\n",
		PQerrorMessage((*db).conn));
		exit_good((*db).conn);
		
	}
}
