void aff_redirection(cmd c, int i){
	int j;
	char tab_std[3][7]={"STDIN","STDOUT","STDERR"}
	char tab_redir[5][9]={"WRITE","READ","APPEND","WRITEHDL","READHDL"}
	for (j = 0 ; j < 3 ; j++)
		printf("redirection [%l][%s]=%s, i, tab_std[j], tab_redir[c.redirection[i][j]]);

	for (j = 0 ; j < 3 ; j++)
		printf("type_redirection [%l][%s]=%s, i, tab_std[j], tab_redir[c.type_redirection[i][j]]);

}