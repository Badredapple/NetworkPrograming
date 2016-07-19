//This is the reflect server program code 
//which is called str_echo()


#include "unp.h"

void
str_ech(int 	socket)
{	
	ssize_t 	n;
	char		buf[MAXLINE];
	
again:
	while( (n = read(sockfd, buf, MAXLINE)) > 0)
		Writen(sockfd, buf, in);
		
	
	if(n < 0 && errno == ETNER)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
	
	
	}