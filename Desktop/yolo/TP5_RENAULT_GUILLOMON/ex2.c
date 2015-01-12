#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

int main(){
	int val_fork;
	char buffer[100];
	int tube [2];
	pipe(tube);

	if((val_fork = fork()) == 0){
		close(tube[1]);
		//close(1); la sortie standard est fermé via dup2
		dup2(1,tube[0]);
		close(tube[0]);
		sleep(1);
		printf("tata tutu\n");
		printf("tete toto");
	}
	else{
		close(tube[0]);
		//close(0); l'entrée standard est fermé via dup2
		dup2(0,tube[1]);
		close(tube[1]);
		fgets(buffer,100,stdin);
		printf("%s\n", buffer);
	}	

	return 0;
}