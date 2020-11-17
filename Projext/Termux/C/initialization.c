#include <stdio.h>

int main(void)
{
	
	int x,y,z;

	z = 23;
	x = (y = z); //initialize x and y with z value

	printf("Value of X : %d\n", x);
	printf("Value of Y : %d\n", y);
}
