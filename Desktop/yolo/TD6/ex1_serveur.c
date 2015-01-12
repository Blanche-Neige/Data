#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <netinet/in.h>

int main(){
	char buff[100];
	int nbLu, lgAdr;
	int idS, descCan;
	struct sockaddr_in sockAddr;
	idS = socket(AF_INET, SOCK_STREAM, 0);

	inet_pton(AF_INET,"127.0.0.1",&(sockAddr.sin_addr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(1234);

	if (bind(idS, (struct sockaddr*) &sockAddr, sizeof(sockAddr)) != 0){
		printf("Echec Bind.");
	}
	
	listen(idS, 1);

	if ( (descCan = accept(idS, (struct sockaddr*) &sockAddr, &lgAdr)) == -1){
		printf("Echec Accept.");
	}
	
	
	nbLu = read(descCan, buff, sizeof(buff));
	printf("%.*s\n", nbLu, buff);

	close(descCan);
	close(idS);
	return 0;
}

