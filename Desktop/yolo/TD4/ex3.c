#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

void fct(int sig, siginfo_t * info, void * content){
	char buffer[40];

	read(0, buffer, 40);
	printf("%s\n",buffer);
}

int main(){
	int tube[2];
	int val_fork;
	int i;
	pipe(tube);
	struct sigaction new_sigaction, old_sigaction;
	new_sigaction.sa_sigaction = fct;
	sigemptyset(&new_sigaction.sa_mask);
	new_sigaction.sa_flags = SA_SIGINFO;
	

	if((val_fork = fork()) == 0){
		close(tube[1]);
		close(0);
		dup(tube[0]);
		close(tube[0]);
		sigaction(SIGUSR1, &new_sigaction, &old_sigaction);
		
		for ( i = 0 ; i < 350000000 ; i++){
			if ( (i%10000000) == 0)
				printf("%d\n",i);
		}


		sleep(5);
	}
	else{
		close(1);
		dup(tube[1]);
		close(tube[1]);
		close(tube[0]);

		printf("Salut fiston !");
		sleep(1);
		kill(val_fork, SIGUSR1);
		
	}
		

	return 0;
}
