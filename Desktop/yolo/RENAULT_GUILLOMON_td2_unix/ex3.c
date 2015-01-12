#include <stdio.h>
#include <stdlib.h>

/*
RENAULT Kévin
GUILLOMON Nicolas
*/

int main(){
	int status;
	int val_fork1;
	int val_fork2;
	int val_fork3;
	int a=1,b=2,c=3,d=4,e=5,f=6;
	float res = 0;

	if((val_fork1 = fork()) == 0){
		// code fils 1
		printf("Fils 1\n");
		return a+b;
		exit(2);
	}
	else{
		if((val_fork2 = fork()) == 0){
			// code fils 2
			printf("Fils 2\n");
			return c+d;
			exit(2);
		}
		else{
			if((val_fork3 = fork()) == 0){
				// code fils 3
				printf("Fils 3\n");
				return e+f;
				exit(2);
			}
			else{				
				// code pere
				printf("Pere\n");
				
				// recuperation du resultat du fils 1
				waitpid(val_fork1, &status,0);
				a = WEXITSTATUS(status);
				
				// recuperation du resultat du fils 2
				waitpid(val_fork2, &status,0);
				c = WEXITSTATUS(status);
				
				// recuperation du resultat du fils 3
				waitpid(val_fork3, &status,0);
				e = WEXITSTATUS(status);
				
				
				res = (float)a*(float)c/(float)e;				

				printf("%.2f\n", res);
				exit(0);
			}
		}
	}
	
	return 0;
}
