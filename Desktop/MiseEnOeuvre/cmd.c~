#include "cmd.h"

void aff_args(cmd *c){
	int i;
	int j;
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		for (j = 0 ; j < c->nb_args[i] ; j++)
			printf("cmd_args[%d][%d] = ''%s''\n", i, j, c->cmd_args[i][j]);
			
	for (i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("nb_args[%d]=%d\n", i, c->nb_args[i]);
}

void free_args(cmd *c){
	
}

void parse_args(cmd *c){}

void aff_membres(cmd *c){
	int i;
	int j;
	printf("cmd_initiale= ''%s''\n", c->cmd_initiale);
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("cmd_membres[%d] = ''%s''\n", i, c->cmd_membres[i]);
		
	printf("nb_cmd_membres=%d\n", c->nb_cmd_membres);
}

void parse_membres(char *chaine, cmd *ma_cmd){	
	int nbToken = 0;
	char * token;

	ma_cmd->cmd_initiale = strdup(chaine);
   
	token = strtok(ma_cmd->cmd_initiale, "|");

	while( token != NULL ) 
	{
		nbToken++;
		ma_cmd->cmd_membres = (char **)realloc(ma_cmd->cmd_membres, sizeof(char **) * nbToken);
		
		ma_cmd->cmd_membres[nbToken-1] = strdup(token);

		token = strtok(NULL, "|");

		//printf("%s\n", ma_cmd->cmd_membres[nbToken-1]);
	}
	
	ma_cmd->nb_cmd_membres = nbToken;
	printf("%s\n", ma_cmd->cmd_initiale);
}

void free_membres(cmd *ma_cmd){}

int parse_redirection(unsigned int i,cmd *c){
	return 0;
}

void free_redirection(cmd *c){}

void aff_redirection(cmd c, int i){
	int j;
	char tab_std[3][7]={"STDIN","STDOUT","STDERR"};
	char tab_redir[6][9]={"WRITE","READ","APPEND","READ+","NULL"};
	for (j = 0 ; j < 3 ; j++)
		printf("redirection [%d][%s]=%s", i, tab_std[j], tab_redir[c.redirection[i][j]]);

	for (j = 0 ; j < 3 ; j++)
		if (c.type_redirection[i][j] )
			printf("type_redirection [%d][%s]=%s", i, tab_std[j], tab_redir[c.type_redirection[i][j]]);
		else
			printf("type_redirection [%d][%s]=NULL", i, tab_std[j]);
}

void main(){
	int i,j;

	cmd * ma_cmd = (cmd *)malloc(sizeof(cmd));
	parse_membres("cat < fichier.txt | grep lol", ma_cmd);
	aff_membres(ma_cmd);
	
	for(
	ma_cmd.type_redirection[0][1] = 1;
}
