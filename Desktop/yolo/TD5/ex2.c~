#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <signal.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/


int val_fork;

void hdlr(){
	printf("Suicide... Au revoir.\n");
	kill(val_fork,SIGKILL);
}

int main(){
	
	int i;
	int j;
	int tube[2];
	pipe(tube);


	if((val_fork = fork()) == 0){
		for (i = 0 ; i < INT_MAX ; i++)
			for (j = 0 ; j < INT_MAX; j++);
		printf("Fils terminé, le père est trop lent.\n");
	
	}
	else{
		signal(SIGALRM,hdlr);
		alarm(5);
		wait();
	}

}
