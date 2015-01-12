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


	if((val_fork = fork()) == 0){
		execlp("ls","ls","-l",NULL);
		// exec l p
		// l pour passer les arguments sous forme de liste
		// p pour utiliser la variable d'environnements PATH
		// et pouvoir utiliser la commande générique "ls"
	}
	else{
		wait();
	}	

	return 0;
}

