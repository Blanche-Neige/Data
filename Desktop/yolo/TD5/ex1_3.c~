#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/


char * append (char * base, char * app){
	int i, taille = strlen(app) + strlen(base) + 1;
	base = (char *)realloc(base,taille);
	for (i = 0; i < strlen(app); i++)
		base[strlen(base) + i] = app[i];
	return base;
}

/*
char * lire(){
	char line[1024];
	char * str;
	FILE * fp = fopen ("sortie.txt","r+");
	while (line = fgets(&line, 1024, fp) != NULL){
		str = append(str,line);
	}

	return str;
}
*/

int main(){
	int val_fork1,val_fork2,val_fork3;
	char buffer[2048];
	char line[1024];
	int fp = creat("fichier1.txt" , 0777);
	int fp2 = creat("fichier2.txt", 0777);
	int fp3 = creat("fichier3.txt", 0777);

	// Fils 1
	if((val_fork1 = fork()) == 0){
		

		
		if ((val_fork2 = fork()) == 0){
			
			if ((val_fork3 = fork()) == 0){//Fils 3
			
				close(1);
				dup(fp);
				close(fp);
				close(fp2);
				close(fp3);
				close(0);
				execlp("ls","ls","-l",NULL);
			
			}//endif fils 3
			
			else{ //Fils 2
			
				close(0);
				dup(fp);
				close(1);
				dup(fp2);
				close(fp);
				close(fp2);
				close(fp3);
				wait();
				execlp("tail","tail","-3","/home/administrateur/Bureau/TD5/fichier1.txt",NULL);
			}	
		}//endif fils 2
		
		
		else{//Fils 1
		
			close(0);
			dup(fp2);
			close(1);
			dup(fp3);
			close(fp);
			close(fp2);
			close(fp3);
			wait();
			execlp("wc","wc","-c","/home/administrateur/Bureau/TD5/fichier2.txt",NULL);
		
		}
	}//endif fils 1
	
	else{//Père
		close(0);
		dup(fp3);
		close(fp);
		close(fp2);
		close(fp3);
		read(fp3, buffer,2048);
		printf("Père : %s\n", buffer);
	}
	
	return 0;
}


// fils 3 -- fp - fils 2 -- tube 2 -- fp -- tube 1 -- pere
