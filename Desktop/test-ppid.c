#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main{

int val_fork, i;

	val_fork = fork();
	if (val_fork == 0)
{//Fils
	for (i = 0 ; i < 1000000; i++)
		if (i%100000 == 0)
			printf("Pid du fils : %d	Pid du père %d" , getpid(),getppid());


}

printf("Fin du père.");


}
