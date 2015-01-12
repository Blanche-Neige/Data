#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int IdSocket;
   char Buf[256];
   struct sockaddr SockAdr;
   
   IdSocket = socket(AF_UNIX, SOCK_STREAM, 0);
   printf("Adresse de socket client : %d \n",IdSocket);   
   SockAdr.sa_family = AF_UNIX;
   sprintf(SockAdr.sa_data,"Socket"); /* Le client doit connaitre l'adresse du
   processus serveur */

   if(connect(IdSocket, &SockAdr, sizeof(SockAdr)) == -1)
   {
      write(1,"Erreur Connect",14);
      exit(-1);
   }
      
   write(IdSocket, "coucou", 6);
   close(IdSocket);
   exit(0);
}

