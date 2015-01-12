#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

int tube[2],i;
char buffer[5];
char buffer2[5];
pipe(tube);
i = fork();
if (i ==0)
	write(tube[1],"abcdefghij",10);
else{
	sleep(1);
	write(tube[1],"0123456789",10);
	while (read(tube[0],buffer,5) != 0)
		printf("%s\n",buffer);
}
exit(0);
}
