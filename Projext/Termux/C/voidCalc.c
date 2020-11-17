#include <stdlib.h>
#include <string.h>
#include <stdio.h>

double _add(double x, double y);
double _sub(double x, double y);
double _div(double x, double y);
double _mult(double x, double y);
double _mod(double x, double y);

int main(int argc, char *argv[])
{
	/*
	* argv[0] = ./voidCalc
	* argv[1] = double
	* argv[2] = operand
	* argv[3] = double
	*/
	if (argc != 4)
	{
		double (*sum)(double,double) = NULL;

		if (strcmp(argv[2],"+") == 0)
		{
			sum = _add;
			fprintf(stdout,"",
			sum(atoi(argv[1]),);
		}
		else if (strcmp(argv[2],"-") == 0)
		{
			
		}
		else if (strcmp(argv[2],"/")== 0)
		{
			
		}
		else if (strcmp(argv[2],"*") == 0)
		{
			
		}
		else if (strcmp(argv[2],"%")== 0)
		{
			
		}
		else
		{
			fprintf(stderr,"[!] Invalid Operand.\n");
		}
	}
	else
	{
		fprintf(stderr,"[!] Example : ./voidCalc int operand int\n");
	}


	return 0;
}

double _add(double x, double y)
{
	if (x != 0 && y != 0)
	{
		return (x + y);
	}
	else
	{
		return -1;
	}
}
double _sub(double x, double y)
{
	return (x - y);
}
double _div(double x, double y)
{
	if (x != 0 && y != 0)
	{
		return (x / y);
	}
	else
	{
		return -1;
	}
}
double _mult(double x, double y)
{
	if (x != 0 && y != 0)
	{
		return (x * y);
	}
	else
	{
		return -1;
	}
}
double _mod(double x, double y)
{
	if (x != 0 && y != 0)
	{
		return ((int)x % (int)y);
	}
	else
	{
		return -1;
	}
}