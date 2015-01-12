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
	float buffer[2];
	float resultat[2];
	
	read(0, buffer, 2);

	resultat[0] = info->si_pid;
	resultat[1] = buffer[0] * buffer[1];

	write(1, resultat,2);
}

int main(){
	int tube1[2];
	int tube2[2];
	int val_fork;
	int i;
	float tab[2];
	float resultat[2];
	char buffer[40];
	pipe(tube1);
	pipe(tube2);
	struct sigaction new_sigaction, old_sigaction;
	new_sigaction.sa_sigaction = fct;
	sigemptyset(&new_sigaction.sa_mask);
	new_sigaction.sa_flags = SA_SIGINFO;
	

	if((val_fork = fork()) == 0){
		close(1);
		dup(tube2[1]);
		close(tube2[1]);

		close(0);
		dup(tube1[0]);
		close(tube1[0]);

		close(tube1[1]);
		close(tube2[0]);

		sigaction(SIGUSR1, &new_sigaction, &old_sigaction);


		sleep(20);
		
		return 0;
	}
	else{

		printf("Premier operande :\n");
		gets(buffer);
		tab[0] = atoi(buffer);

		printf("Deuxieme operande :\n");
		gets(buffer);
		tab[1] = atoi(buffer);

		write(tube1[1],tab,2);
		sleep(1);
		kill(val_fork, SIGUSR1);
		sleep(5);
		read(tube2[0], resultat, 2);
		printf("Pid : %f, résultat : %f\n", resultat[0], resultat[1]);

		close(tube1[1]);
		close(tube1[0]);
		close(tube2[1]);
		close(tube2[0]);

		return 0;	
	}
		

	return 0;
}

