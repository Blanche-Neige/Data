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
	printf("PID : %d, PID DU SIGNAL : %d,  SIGNAL : %d\n", getpid(), info->si_pid, sig);
}

int main(){
	int val_fork;
	struct sigaction new_sigaction, old_sigaction;
	new_sigaction.sa_sigaction = fct;
	sigemptyset(&new_sigaction.sa_mask);
	new_sigaction.sa_flags = SA_SIGINFO;
	

	if((val_fork = fork()) == 0){
		sigaction(SIGUSR1, &new_sigaction, &old_sigaction);
		sigaction(SIGUSR2, &new_sigaction, &old_sigaction);
		sigaction(SIGPIPE, &new_sigaction, &old_sigaction);
		//sigaction(SIGALRM, &new_sigaction, &old_sigaction);
		//sigaction(SIGCONT, &new_sigaction, &old_sigaction);
		//sigaction(SIGTSTP, &new_sigaction, &old_sigaction);


		sleep(5);
	}
	else{
		sleep(1);
		kill(val_fork, SIGUSR2);
		kill(val_fork, SIGUSR1);
		kill(val_fork, SIGPIPE);
		// evidence
		kill(val_fork, SIGUSR1);
		kill(val_fork, SIGUSR1);
		kill(val_fork, SIGUSR1);
		kill(val_fork, SIGUSR1);
		//kill(val_fork, SIGALRM);
		//kill(val_fork, SIGCONT);
		//kill(val_fork, SIGUSR1);
		//kill(val_fork, SIGTSTP);
	}	

	return 0;
}

