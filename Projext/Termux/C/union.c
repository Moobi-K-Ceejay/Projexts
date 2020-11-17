#include <stdlib.h>
#include <stdio.h>

typedef union
{
	size_t num1;
	size_t num2;
	
}Alpha;

int main(void)
{
	Alpha *alpha = calloc(2, sizeof(Alpha));

	if (alpha == NULL)
	{
		printf("[!] Failed To Allocate Memory.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter Num1 and Num2 : ");
	scanf("%d %d",&alpha->num1,&alpha->num2);
	
	printf("%d %d\n",alpha->num1, alpha->num2);

	return 0;
}