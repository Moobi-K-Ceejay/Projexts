#include <stdio.h>

int main(void)
{
	char info[50];
	char dept[] = "HR";
	int emp_no = 10;

	sprintf(info,"The %s department has %d members.\n",dept,emp_no);
	printf("%s",info);
	
	return 0;
}
