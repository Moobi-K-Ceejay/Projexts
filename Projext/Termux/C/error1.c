#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(void)
{
	/*
		variable : char *ptr
		input    : allocate 4GB of memory to ptr
		output   : none
	*/

	char *ptr = malloc(4000000000L);

	if (ptr != NULL)
	{
		fprintf(stdout,"[!] Allocated 4GB Of Memory To Ptr\n");
		free(ptr);
	}
	else
	{
		perror("[!] Failed To Allocate 4GB Of Memory To Ptr\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}