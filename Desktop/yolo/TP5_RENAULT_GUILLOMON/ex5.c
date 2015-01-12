#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

int main(){
	int val_fork1,val_fork2,n;
	char buffer[100];
	int tube [2];
	pipe(tube);

	if((val_fork1 = fork()) == 0){
		dup2(tube[1],1);
		close(tube[0]);
		close(tube[1]);
		close(0);

		printf("Message fils 1\n");
	}
	else{
		if((val_fork2 = fork()) == 0){
			dup2(tube[1],1);
			close(tube[0]);
			close(tube[1]);
			close(0);
			printf("Message fils 2\n");
		}
		else{
			dup2(tube[0],0);
			close(tube[0]);
			close(tube[1]);
			
			wait(val_fork1);
			wait(val_fork2);
		
			read(0, buffer, 100);
			printf("%s",buffer);			
		}
		
	}	

	return 0;
}
