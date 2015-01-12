#include <stdio.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

int main(){
	printf("Programme\n");
	printf("PID : %d, PPID : %d\n", getpid(), getppid());
	printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());

	int i;
	int val_fork;
	val_fork = fork();

	if(val_fork == 0){
		// code fils
		printf("Fils\n");
		printf("PID : %d, PPID : %d\n", getpid(), getppid());
		printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());

		// pour section 3
		if (sleep(2) == 0)
			printf("Fin sleep\n");

		printf("Fin code fils\n");
	}
	else{
		// code pere
		printf("Pere\n");
		printf("PID : %d, PPID : %d\n", getpid(), getppid());
		printf("Proprietaire : %d, Group : %d\n\n", getuid(), getpgid());
		
		// pour section 1
		/*for(i=0; i<1000000; i++){}*/

		// pour section 2
		/*if (sleep(1) == 0)
			printf("Fin sleep\n");*/

		// pour section 3
		wait(NULL);

		printf("Fin code pere\n");
	}
	
	return 0;
}
