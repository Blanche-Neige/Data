#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <linux/unistd.h>


void *ecrire(void * arg){
	int i;
	FILE * fd = fopen((char *)arg, "w");		

	for(i = 0 ; i < 20 ; i++){
		putc('A' + (int)(26.0*rand()/(RAND_MAX+1.0)) , fd);
	}
	
	close(fd);
	pthread_exit (0);
	return NULL;
}

void *lire(void * arg){
	int i;
	char buffer[20];
	FILE * fd = fopen((char *)arg, "r");
	sleep(1);
	for(i = 0 ; i < 20 ; i++){
		printf("%i ", fgetc(fd));
	}
	printf("\n");

	close(fd);

	pthread_exit (0);
	return NULL;
}

int main(){
	int i;
	char nom [] = "testEx2.txt";
	pthread_t th1, th2;

	pthread_create (&th1, NULL, ecrire, &nom);
	sleep(1);
	pthread_create (&th2, NULL, lire, &nom);

	pthread_join(th1,NULL);
	sleep(1);
	pthread_join(th2,NULL);

	return 0;
}
