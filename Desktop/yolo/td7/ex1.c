#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <linux/unistd.h>

typedef struct _Calcul { 
	float op1, op2, result; 
} Calcul;


void *somme(void * arg){
	Calcul * calc = (Calcul *) arg;
	calc->result = calc->op1 + calc->op2;

	pthread_exit (0);
	return NULL;
}

int main(){
	pthread_t th1, th2, th3;
	void * ret;
	Calcul c1, c2, c3;

	c1.op1 = 2;
	c1.op2 = 3;
	c2.op1 = 4;
	c2.op2 = 5;
	c3.op1 = 6;
	c3.op2 = 7;
	
	pthread_create (&th1, NULL, somme, &c1);
	pthread_create (&th2, NULL, somme, &c2); 
	pthread_create (&th3, NULL, somme, &c3); 

	pthread_join (th1, NULL);
	pthread_join (th2, NULL);
	pthread_join (th3, NULL);

	printf("Resultat : %f\n", c1.result * c2.result / c3.result);

	return 0;
}
