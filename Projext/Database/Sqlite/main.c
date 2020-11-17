#include <sqlite3.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
	sqlite3 *db; //
	sqlite3_stmt *res; //
	char *errMsg; //
	int conn; // 
	char *query; //
	int step_data;
}Sqlite;

typedef struct
{
	char *full_names; // store user fullnames
	char gender; // store user gender
	char *color; // store user color
	size_t age; // store user age
	int id;
	void *data[5]; 
}User;

void draw_line();

int main(int argc, char **argv)
{
	
	if (argc != 2) // check if passed args is not 2
	{
		fprintf(stderr,"[!] Example : ./main db_name\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		Sqlite *sql = malloc(sizeof(Sqlite)); // allocate memory for struct
		if (sql != NULL) // check if memory is allocated
		{
			(*sql).conn = sqlite3_open(argv[1],&(*sql).db); // open database
			if ((*sql).conn != SQLITE_OK)
			{
				fprintf(stderr,"[!] Failed To Open Database : %s",
				sqlite3_errmsg((*sql).db));
				sqlite3_close((*sql).db);				
			}
			else
			{

				User *user = malloc(sizeof(User));
				if (user == NULL)
				{
					fprintf(stderr,"[!] Failed To Allocate Memory Aborting...\n");
					exit(EXIT_FAILURE);
				}

				char *options[] = {
					"SELECT","INSERT","UPDATE","DELETE"
				};
				size_t i;
				for (i = 0; i < 4; i++)
				{
					fprintf(stdout,"[%d] %s DATA\n",i,options[i]);
				}
				
				int option;

				do{
					fprintf(stdout,"\n[+] Enter Option To Continue : ");
					scanf("%d",&option);
				// check if option is not less 1 or greater 4				
				}while(option < 1 || option > 4);

				switch(option)
				{
					case 1: 
						draw_line();

						fprintf(stdout,"[+] Enter ID : ");
						scanf("%d",&(*user).id); // take user id
						
						(*sql).query = "SELECT Id, FullNames, Gender, Color, Age FROM People WHERE ID = ?";
						(*sql).conn = sqlite3_prepare_v2((*sql).db,(*sql).query,-1,&(*sql).res,0);

						if ((*sql).conn != SQLITE_OK)
						{
							fprintf(stderr,"[!] Failed To Execute Statemnt : %s\n",sqlite3_errmsg((*sql).db));
							exit(EXIT_FAILURE);
						}
						else
						{
							sqlite3_bind_int((*sql).res,1,(*user).id);
						}

						(*sql).step_data = sqlite3_step((*sql).res);
						if ((*sql).step_data == SQLITE_ROW)
						{
							void *DATA[] = {
								sqlite3_column_text((*sql).res, 0),
								sqlite3_column_text((*sql).res, 1),
								sqlite3_column_text((*sql).res, 2),
								sqlite3_column_text((*sql).res, 3),
								sqlite3_column_text((*sql).res, 4)
							};
							size_t j;
							for (j = 0; j < 5; j++)
							{
								(*user).data[j] = &sqlite3_column_text((*sql).res, j);
							}
							/*
								assign values using void *data = { &age, &gende...}
							*/
						}
					  break;
					case 2:

					  break;
					case 3:

					  break;
					case 4:
						
					  break;
					default:
						fprintf(stderr,"[!] Invalid Option.\n");

				}
				
			}
		}
		else
		{
			fprintf(stderr,"[!] Failed To Allocate Memory Aborting...\n");
			exit(EXIT_FAILURE);
		}
	}

	return 0;
}

bool linear_search(int *array, int size, int data)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (array[i] == data)
		{
			return true;
		}
	}
	return false;
}

void draw_line()
{
	size_t i;
	for (i = 0; i < 20; i++)
	{
		fprintf(stderr,"-");
	}
	fprintf(stdout,"\n");
}