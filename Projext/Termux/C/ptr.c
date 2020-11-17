#include <stdio.h>
#include <graphics.h>
int main(void)
{
	int arr[] = {12,13,14,15};
	int *ptr = arr;

	int i;
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", *(ptr + i));
	}

	return 0;
}