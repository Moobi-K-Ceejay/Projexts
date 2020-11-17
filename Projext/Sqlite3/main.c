#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "dbmanager.h"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr,"[!] Example : ./main db_name\n");	
		exit(EXIT_FAILURE);
	}
	
	connect_database(argv[1]);
	
	char *options[] = {
	"SELECT","INSERT","DELETE","UPATE"
	};
	size_t j, option;

	for (j = 0; j < 4; j++)
	{
		fprintf(stdout,"[%d] %s DATA\n",j, options[j]);
	}

	do {
		fprintf(stdout,"[!] Enter Option Number : ");
		scanf("%d",&option);
	}while((option < 1) || (option > 4));

	switch(option)
	{
		case 1:
			size_t id;;
			fprintf(stdout,"[+] Enter ID : ");
			scanf("%d",&id);
		  break;
		case 2:
			// some code
		  break;
		case 3:
			// some code
		  break;
		case 4:
			// some code
	}
	return 0;
}

