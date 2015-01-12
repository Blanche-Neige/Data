void aff_membres(cmd *c){
	int i;
	int j;
	printf("cmd_initiale= ''%s''\n", c->cmd_initiale);
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("cmd_membres[%d] = ''%s''\n", i, c->cmd_membres[i]);
		
	printf("nb_cmd_membres=%d\n", c->nb_cmd_membres);
}

