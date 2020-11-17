#include <stdlib.h>
#include <stdio.h>

void sayHi(int times);

int main(void)
{
	void (*greetings)(int) = sayHi;

	if (greetings == NULL)
	{
		fprintf(stderr,"Failed To Allocate Memory\n");
	}
	else
	{
		greetings(6);
	}

	return 0;
}

void sayHi(int times)
{
	/* function : void sayHi(int time)
	   input    : int time(number of times to print)
	   output   : print 'Hi' times
	*/
	int i = 0;
	for (i = 0; i < times; i++)
	{
		printf("[%d] Hi\n", i);
	}
}