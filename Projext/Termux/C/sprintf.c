#include <stdio.h>

int main(void)
{
	char full_names[50];
	char first_name[] = "Kabelo";
	char last_name[] = "Moobi";

	sprintf(full_names,"Hi, am %s %s \n",first_name, last_name);
	printf("%s \n",full_names);
	
	return 0;
}