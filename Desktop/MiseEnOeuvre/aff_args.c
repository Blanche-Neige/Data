void aff_args(cmd *c){
	int i;
	int j;
	for ( i = 0 ; i < c->nb_cmd_membres ; i++)
		for (j = 0 ; j < c->nb_args[i] ; j++)
			printf("cmd_args[%d][%d] = ''%s''\n", i, j, c->cmd_args[i][j]);
			
	for (i = 0 ; i < c->nb_cmd_membres ; i++)
		printf("nb_args[%d]=%d\n", i, c->nb_args[i]);
}
