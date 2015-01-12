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

	int fd = open("sortie", O_CREAT | O_WRONLY, 0777);

	if((val_fork = fork()) == 0){
		close(1);
		dup(fd);
		close(fd);
		printf("test");
	}
	else{
		// code pere
	}	

	return 0;
}
