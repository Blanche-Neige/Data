#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){

int i,j,k;
i = fork();
if (i != 0)
	j = fork();

if ((i == 0) && (j == 0))
{
	printf("ça passe gros! j = %d, i = %d",j,i);
	k = fork();
}
printf("test\n");
exit(0);



}
