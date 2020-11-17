#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr,"[!]Example : ./voidAdd name age\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		char *name = argv[1];
		int age = atoi(argv[2]);

		void *ptr = NULL;
		if (ptr == NULL)
		{
			printf("Value of Name   : %s\n", name);
			ptr = &name;
			printf("Address of Name : %p\n", ptr);
			printf("Value of Age    : %d\n", age);
			ptr = &age;
			printf("Address of Age  : %p\n", ptr);
		}
		else
		{
			fprintf(stderr,"[!] Failed To Allocated Memory.\n");
			exit(EXIT_FAILURE);
		}
		
	}

	return 0;
}