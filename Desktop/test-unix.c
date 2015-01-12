#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


#define MAXFORK 10


int main()
{
  int pid[MAXFORK];
  int i,j;
  int fini;
  for(i=0;i<MAXFORK;i++)
	pid[i]=-5;

  for(i=0;i<MAXFORK;i++){
    pid[i]=fork();
    if (pid[i]==-1) {
      // ERREUR
      fprintf(stderr, "Impossible de créer un fils (%d)\n",i);
    } else if (pid[i]==0) {
      // FILS
	if (i == 0 || i == 9)
		continue;
      printf("Fils %1d (PID=%d) : pid[%d]=%d - pid[%d]=%d - pid[%d]=%d - Activé\n",i,getpid(),i-1,pid[i-1],i,pid[i],i+1,pid[i+1]);
      fflush(stdout);
      for(j=0;j<5000000;j++);
      printf("Fils %1d (PID=%d): Fin\n",i,getpid());
      fflush(stdout);
      exit(0);
    } else {
      printf("Père : Activation du fils %2d\n", i);
      fflush(stdout);
    }
  }

  for (i=0;i<MAXFORK;i++)
	printf("Valeur pid du fils %d : %d\n",i,pid[i]);
  printf("Père : Fin des activations\nAttente ...\n");
  fflush(stdout);
  fini=0;
  while (!fini) {
    fini=1;
    for(i=0;i<MAXFORK;i++){
      if (pid[i]>0) {
        if (waitpid(pid[i],NULL,WNOHANG)==0) {
          printf("Père: fin du fils %2d (PID=%d)\n", i, pid[i]);
          fflush(stdout);
          pid[i]=0;
        }
      } else {
        fini=0;
      }
    }
  }


  printf("Fin de tous les fils.");
  fflush(stdout);


  return 0;
}
