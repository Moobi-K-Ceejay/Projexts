#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

#define MAXRCVL 500

typedef struct
{
	char buffer[MAXRCVL + 1];
	struct sockaddr_in dest;
	int my_socket;
}Network;


int main(int argc, char **argv)
{
	errno = 0;
	if (argc != 3)
	{
		fprintf(stderr,"[!] Example : ./client -address -port\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		Network *net = malloc(sizeof(Network));
		if (net == NULL)
		{
			fprintf(stderr,"[!] Failed To Allocate Memory\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			(*net).my_socket = socket(AF_INET,SOCK_STREAM,0);
			memset(&(*net).dest, 0, sizeof((*net).dest));

			(*net).dest.sin_family = AF_INET;
			/* set dest IP */
			(*net).dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
			/* set dest PORT */
			(*net).dest.sin_port = htons(atoi(argv[2]));
			connect((*net).my_socket,(struct sockaddr *)&(*net).dest, sizeof(struct sockaddr_in));

			int length = recv((*net).my_socket,(*net).buffer,MAXRCVL,0);
			/* null terminate received data*/
			(*net).buffer[length] = '\0';

			fprintf(stdout,"[!] Received %s (%d bytes).\n",(*net).buffer,length);
			/* kill socket */
			close((*net).my_socket);
		}
	}

	return 0;
}