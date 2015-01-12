#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h>

int main(){
	int idS;
	char buff[100];
	struct sockaddr_in sockAddr;
	idS = socket(AF_INET, SOCK_STREAM, 0);

	inet_pton(AF_INET,"127.0.0.1",&(sockAddr.sin_addr));

	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(1234);

	if (connect(idS, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == -1){
		printf("Je n'ai pas pu me connecter.\n");
		exit(-1);
	}
	
	while(1){
		scanf("%s", buff);
		send(idS, buff, strlen(buff), 0);
		send(idS, "\n", 2, 0);
	}

	close(idS);
	return 0;
}
