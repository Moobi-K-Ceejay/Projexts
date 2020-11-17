#include <stdio.h>

typedef enum
{
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
}DayOfWeek;

int main(void)
{
	DayOfWeek day = 2;

	printf("Day : %d\n",day);

	return 0;
}