#include <stdlib.h>
#include <signal.h>
#include <stdio.h>


static void catch_function(int signal);

int main(void)
{
	if (signal(SIGINT, catch_function) == SIG_ERR)
	{
		fputs("An error occured while setting a signal handler.\n", stderr);
		return EXIT_FAILURE;
	}
	puts("Raising the interactive attension signal");
	if (raise(SIGINT) != 0)
	{
		fputs("Erroe raising the signal.\n",stderr);
		return EXIT_FAILURE;
	}
	fputs("Exiting.\n",stdout);
	
	return (0);
}

static void catch_function(int signal)
{
	puts("Interactive signal caught.");
}
