//This is Caphter 5  :a example of C/S in TCP

//This is the server main function.
//Maybe I will change it's udp.h ,but now it just is that

#include "udp.h"
int
main(int argc, char **argv)
{
	int		listenfd, connfd;
	pid_t 	childpid;
	socklen_t chlilen;
	
	struct sockaddr_in cliaddr, servaddr;
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);     //This is a nomal address such as 192.168.1.60
	
	servaddr.sin_port = htons(SERV_PORT);			  //This the port of the server
	
	Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	
	Listen(listenfd, LISTENQ);
	
	for(; ;){
		clilen =sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *) &cliaddr, &clilen);
		//make block in ,wait for post from client
		if( (childpid = Fork()) == 0){
			Close(listenfd);
			str_echo(connfd);		//this is the reflect server cdoe
			exit(0);
		}
		Close(connfd);			//parent close connected socket
	}
	
}


