#include <stdio.h> #include <stdlib.h> #include <string.h> #include <unistd.h> #include <arpa/inet.h> #include <sys/types.h> #include <netinet/in.h> #include <sys/socket.h>
#defineMAXRCVLEN500 #definePORTNUM2300
int main(int argc,char *argv[])
{ char buffer[MAXRCVLEN+1]; /*+1sowecanaddnullterminator*/
int len,mysocket; struct sockaddr_indest;
mysocket=socket(AF_INET,SOCK_STREAM,0);
memset(&dest,0, sizeof(dest)); /*zerothestruct*/ dest.sin_family=AF_INET; dest.sin_addr.s_addr=htonl(INADDR_LOOPBACK); /*setdestinationIPnumber- localhost,127.0.0.1*/
*/ dest.sin_port=htons(PORTNUM); /*setdestinationportnumber
connect(mysocket,(struct sockaddr*)&dest, sizeof(struct sockaddr_in)); len=recv(mysocket,buffer,MAXRCVLEN,0);
/*Wehavetonullterminatethereceiveddataourselves*/ buffer[len]='\0';
printf("Received%s(%dbytes).\n",buffer,len);
close(mysocket);
} return EXIT_SUCCESS;
}