#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
/* 1 argument est pass\'e en param\`etre	*/
{
   int IdSocket, DescripteurCanal, LgAdr;
   int retourlisten;
   char Buf[256];
   struct sockaddr SockAdr;
   int nb_serv, NB_SERV_MAX, val;
   
   if (argc != 2) {
   	printf("Il faut 1 argument et 1 seul.\n");
	exit(-1);
   }
   
   NB_SERV_MAX=atoi(argv[1]);	/*l'argument est le nombre max de services \`a rendre*/
      printf("%d\n",NB_SERV_MAX);
 
 	/* on fait du processus un "dŽmon" */     
   if (fork()!=0)
   {
   	exit(0);
   }
   setsid();
   
   	/* voilˆ ! */
	
   IdSocket = socket(AF_UNIX, SOCK_STREAM, 0);
   printf("Adresse de socket serveur : %d  \n",IdSocket); 
   /* Le domaine utilisŽ est AF_UNIX, local au système */
   /* Le principe reste inchangŽ si on utilise AF_INET, seul la forme de l'adresse change */
   SockAdr.sa_family = AF_UNIX;
   sprintf(SockAdr.sa_data,"Socket");
      
   if(bind(IdSocket, &SockAdr, sizeof(SockAdr))==-1)
   {
   	write(1,"Erreur bind",11);
   	exit(-1);
   }
   retourlisten = listen(IdSocket, 1); /* seule 1 connection pendante est autorisŽe. Sur un domaine AF_UNIX, ça suffit ! */
     printf("listen : %d \n",retourlisten); 
  
   signal(SIGCHLD,SIG_IGN); /* On ignorera la mort des fils */
   nb_serv=0;
   while (nb_serv<NB_SERV_MAX) { 
   	if ((DescripteurCanal = accept(IdSocket, &SockAdr, &LgAdr)) == -1) {
	perror("erreur accept\n");
	}
     	printf("Adresse de l'accept serveur : %d \n",DescripteurCanal); 
   	if (fork()==0) {
		close(IdSocket); /*fermeture socket d'Žcoute */
   		read(DescripteurCanal, Buf, sizeof(Buf)); /*lecture de la requte */
   		printf("Le serveur a lu %s\n", Buf);
		
   		close(DescripteurCanal); /*lˆ, c'est pour faire propre ...*/
   		exit(1);
   	}
	close(DescripteurCanal);
	nb_serv++;
   }
   close(IdSocket);
   wait(&val); /* Comme on ignore la "mort d'un fils", on attend tous les fils */
}

