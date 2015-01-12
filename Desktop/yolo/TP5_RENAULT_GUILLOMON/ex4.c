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
	int val_fork,n;
	char buffer[100];
	int tube1 [2];
	int tube2 [2];
	pipe(tube1);
	pipe(tube2);

	if((val_fork = fork()) == 0){
		// Tube 1
		// Sortie - tube 1
		dup2(tube1[1],1);
		

		// Tube 2
		// Entrée - tube 2
		dup2(tube2[0],0);

		close(tube2[1]);
		close(tube1[0]);
		 
		// 6 E/S, 4 close -> 2 liaisons restantes
		// Test	
		printf("Message de 40 caractères : Bonjour ! ! !\n");
		fflush(stdout);	

		n=read(0,buffer,100);
		write(2,buffer, n);

		n=read(0,buffer,100);
		write(2,buffer, n);

		// Fermeture fin du processus
		close(tube1[1]);
		close(tube2[0]);

	}
	else{
		// Tube 2
		// Entrée - tube 2
		dup2(tube1[0],0);

		// Tube 1
		// Sortie - tube 1
		dup2(tube2[1],1);

		close(tube2[0]);
		close(tube1[1]);

		// Test 
		n=read(0,buffer,100);
		write(1,buffer,n);
		printf("Bonjour à toi ! ! !");

		// Fermeture fin du processus
		close(tube1[0]);
		close(tube2[1]);
	}	

	return 0;
}