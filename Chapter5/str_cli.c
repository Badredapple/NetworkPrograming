//This is from the tcpli01.c 
//This is the client reflect program code
//which maybe writen in the same file.

#include "unp.h"
void
str_cli(FIFE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	
	while(Fgets(sendline, MAXLINE, fp) != NULL){
	
		Writen(sockfd, sendline, strlen(sendline));
		
		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli:server terminated prematruely");
			
		Fputs(recvline, stdout);
				
		}
	
	}