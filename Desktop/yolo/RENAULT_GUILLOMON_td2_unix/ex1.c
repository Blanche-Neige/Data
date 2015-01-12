#include <stdio.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

int main(){
	printf("Programme\n");
	printf("PID : %d, PPID : %d\n", getpid(), getppid());
	printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());

	int val_fork;
	val_fork = fork();

	if(val_fork == 0){
		// code fils
		printf("Fils\n");
		printf("PID : %d, PPID : %d\n", getpid(), getppid());
		printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());
	}
	else{
		// code pere
		printf("Pere\n");
		printf("PID : %d, PPID : %d\n", getpid(), getppid());
		printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());
	}
	
	return 0;
}
