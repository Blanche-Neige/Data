#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

void getPID(int sig){
	printf("PID : %d, SIGNAL : %d\n", getpid(), sig);
}

int main(){
	int val_fork;

	if((val_fork = fork()) == 0){
		signal(SIGUSR1, getPID);

		sleep(2);
	}
	else{
		sleep(1);
		kill(val_fork, SIGUSR1);
	}	

	return 0;
}
