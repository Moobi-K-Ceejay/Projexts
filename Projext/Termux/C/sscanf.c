#include <stdio.h>

int main(void)
{
	char info[] = "18 is Kabelo";
	char name[10];
	char div[10];
	int age;

	sscanf(info, "%d %s %s", &age, div, name);

	printf("%s %s %d \n", name, div, age);

	return 0;
}
