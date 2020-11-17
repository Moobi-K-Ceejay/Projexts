/*
*******************************************************
*					dbmanager.hpp				      *
*
*
*
*
*												      *
*******************************************************
*/
#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include <libpq-fe.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define USERNAME ""
#define DATABASE ""
#define PASSWORD " "

void do_exit(PGconn *conn, PGresult *res)
{
	fprintf(stderr,"[!]%s",PQerrorMessage(conn));

	PQclear(res);
	PQfinish(conn);
	exit(EXIT_FAILURE);
}

bool connect_database()
{
	PGconn *conn = PQconnectdb("user=USERNAME password=PASSWORD dbname=DATABASE");

	if (PQstatus(conn) != CONNECTION_BAD)
	{
		return true;
	}
	else
	{
		PQfinish(conn);
		return false;
	}
}

#endif // DBMANAGER_HPP
