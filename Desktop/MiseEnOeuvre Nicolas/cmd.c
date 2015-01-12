#include "cmd.h"

void aff_args(cmd *c){
	int i;
	int j;
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		for (j = 0 ; j < c->nb_args[i] + 1 ; j++)
			printf("cmd_args[%d][%d] = ''%s''\n", i, j, c->cmd_args[i][j]);
			
	for (i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("nb_args[%d]=%d\n", i, c->nb_args[i]);
}

void free_args(cmd *c){
	
}

void parse_args(cmd *c){
	char * tmp_cmd_membre;
	char * token;
	int nbToken = 0;
	int i;

	c->cmd_args = (char ***)realloc(c->cmd_args, sizeof(char ***) * c->nb_cmd_membres);
	c->nb_args = (int *)realloc(c->nb_args, sizeof(int *) * c->nb_cmd_membres);

	for(i = 0; i < c->nb_cmd_membres; i++){
		/* definition du token */
		tmp_cmd_membre = strdup(c->cmd_membres[i]);
		token = strtok(tmp_cmd_membre, " ");
		while( token != NULL )
		{
			/* Elimation des redirections et de leurs chemins */
			if((strchr(token, '<') != NULL) || (strchr(token, '>') != NULL) || (strchr(token, '/') != NULL))
				break;
			/* reallocation */
			nbToken++;
			c->cmd_args[i] = (char **)realloc(c->cmd_args[i], sizeof(char **) * nbToken);

			/* recuperation du token et copie */
			c->cmd_args[i][nbToken-1] = strdup(token);
			/* on change de token */
			token = strtok(NULL, " ");
			/* maj nb args */
			c->nb_args[i] = nbToken;
		}
		c->cmd_args[i][nbToken] = NULL;
		nbToken = 0;

		/* allocation redirection */
		c->redirection = (char ***) calloc(c->nb_cmd_membres,sizeof(char***));
		/* allocation type redirection */
		c->type_redirection = (int **) calloc(c->nb_cmd_membres,sizeof(int**));
	}
	free(tmp_cmd_membre);
}

void parse_membres(char *chaine, cmd *ma_cmd){	
	int nbToken = 0;
	char * token;
	char * tmp_cmd_ini;

	ma_cmd->cmd_initiale = strdup(chaine);
   	tmp_cmd_ini = strdup(chaine);
	/* definition du token */
	token = strtok(tmp_cmd_ini, "|");

	while( token != NULL ) 
	{
		nbToken++;
		ma_cmd->cmd_membres = (char **)realloc(ma_cmd->cmd_membres, sizeof(char **) * nbToken);
		
		/* recuperation du token et copie */
		ma_cmd->cmd_membres[nbToken-1] = strdup(token);
		/* on change de token */
		token = strtok(NULL, "|");
	}
	
	ma_cmd->nb_cmd_membres = nbToken;
	free(tmp_cmd_ini);
}

void aff_membres(cmd *c){
	int i;
	int j;
	printf("cmd_initiale= ''%s''\n", c->cmd_initiale);
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("cmd_membres[%d] = ''%s''\n", i, c->cmd_membres[i]);
		
	printf("nb_cmd_membres=%d\n", c->nb_cmd_membres);
}

void free_membres(cmd *ma_cmd){}

int parse_redirection(unsigned int i,cmd *c){
	c->redirection[i] = (char**)calloc(3,sizeof(char**));
	
/*	if(strstr(c->cmd_membres[i], "2>>")) != NULL){
		c->type_redirection[i][0] = 5;
	} else if(strstr(c->cmd_membres[i], "2>")) != NULL){
		c->type_redirection[i][STDIN] = 4;
	} else if(strstr(c->cmd_membres[i], ">>")) != NULL){
		c->type_redirection[i][STDIN] = 3;
	} else if(strstr(c->cmd_membres[i], ">")) != NULL)){
		c->type_redirection[i][STDIN] = 2;
	} else if(strstr(c->cmd_membres[i], "<")) != NULL)){
		c->type_redirection[i][STDIN] = 1;	
	}else
		c->type_redirection[i][STDIN] = 0;
	}*/
	return 0;
}

void free_redirection(cmd *c){}

void aff_redirection(cmd c, int i){
	int j;
	char tab_std[3][7]={"STDIN","STDOUT","STDERR"};
	char tab_redir[6][13]={"NULL","INPUT","OUTPUT","APPEND","OUTPUT ERR","APPEND ERROR"};

	//Chemin de redirection
	for (j = 0 ; j < 3 ; j++)
		if (c.redirection != NULL)
			printf("redirection [%d][%s]=%s", i, tab_std[j], c.redirection[i][j]);
		else
			printf("redirection [%d][%s]= NULL", i, tab_std[j]);

	//Type de redirection
	for (j = 0 ; j < 3 ; j++)
			printf("type_redirection [%d][%s]=%s", i, tab_std[j], tab_redir[c.type_redirection[i][j]]);
}


void main(){
	cmd * ma_cmd = (cmd *)malloc(sizeof(cmd));
	parse_membres("cat < /var/log/messages | grep ACPI | wc -l >> truc.txt", ma_cmd);
	aff_membres(ma_cmd);
	printf("--------------------\n");
	parse_args(ma_cmd);
	aff_membres(ma_cmd);
	aff_args(ma_cmd);
	parse_redirection(0, ma_cmd);
	aff_redirection(*ma_cmd,0);
}
