#include <stdio.h>
#include <stdlib.h>

typedef union
{
	int age;
	double height;
}Person;

int main(void)
{
	Person *p = calloc(2, sizeof(Person));

	p->age = 23;
	p->height = 9.67;

	if (p->age == 23)
		printf("Age    : %d\n",p->age);
		printf("Height : %2.f\n",p->height);
	
	return 0;
}