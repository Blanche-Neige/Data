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
	int tube1[2];
	int tube2[2];
	pipe(tube1);
	pipe(tube2);
	fcntl(tube1[1],F_SETFL,0 | O_NONBLOCK);
	fcntl(tube2[1],F_SETFL,0 | O_NONBLOCK);

	// mkfifo my_pipe

	if((val_fork1 = fork()) == 0){
		dup2(tube1[1],1);
		close(tube1[0]);
		close(tube1[1]);
		close(tube2[0]);
		close(tube2[1]);
		close(0);

		printf("Message fils 1\n");
	}
	else{
		if((val_fork2 = fork()) == 0){
			dup2(tube2[1],1);
			close(tube2[0]);
			close(tube2[1]);
			close(tube1[0]);
			close(tube1[1]);
			close(0);
			printf("Message fils 2\n");
		}
		else{
			dup2(tube1[0],0);
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