#include <stdio.h>
#include <stdlib.h>

int addSum(int x, int y);

int main(int argc, char *argv[])
{

	if (argc != 3)
	{
		fprintf(stderr,"[!] Example : ./sumVoidPtr int int\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		int (*sum)(int, int) = addSum;

		if (sum != NULL)
		{
			fprintf(stdout,"[+] Sum : %d\n", sum(atoi(argv[1]),atoi(argv[2])));
		}
		else
		{
			fprintf(stderr,"[!] Failed To Allocate Memory\n");
		}
	}
	
	return 0;
}

int addSum(int x, int y)
{
	int sum = x + y;
	
	return sum;
}