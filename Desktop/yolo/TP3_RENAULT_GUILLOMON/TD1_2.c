#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char * argv[])
{	
	int mode;
	int m;
	struct stat sb;
	char * nomFichier;

	struct dirent * lecture;
	DIR * rep;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	
	rep = opendir(argv[1]);
	while ((lecture = readdir(rep))) {

		if (stat(lecture->d_name, &sb) == -1) {
			perror("stat");
			exit(EXIT_SUCCESS);
		}

		// numero i-noeud
		printf("%ld\t", (long) sb.st_ino);

		// droits
		mode = (long long) sb.st_mode%512;
		m=64;
		while (m >= 1){
				
			if((mode/m)==4 || (mode/m)==5 || (mode/m)==6 || (mode/m)==7)
				printf("r");
			else
				printf("-");
		
			if((mode/m)==2 || (mode/m)==3 || (mode/m)==6 || (mode/m)==7)
				printf("w");
			else
				printf("-");
		
			if((mode/m)==1 || (mode/m)==3 ||(mode/m)==5 || (mode/m)==7)
				printf("x");
			else
				printf("-");
			mode %= m;
			m = m/8;
		}
		printf(" ");

		// nombres de liens
		printf("%ld\t", (long) sb.st_nlink);
		// UID 
		printf("%s\t", getpwuid(sb.st_uid)->pw_name);
		// GUID
		printf("%s\t", getgrgid(sb.st_gid)->gr_name);
		// taille du fichier
		printf("%lld octets\t", (long long) sb.st_size);
		// date de la derniere modification
		printf("%d\t", ctime(&sb.st_mtime));
		// nom de fichier
		printf("%s\n", lecture->d_name);
	}
	closedir(rep);

	exit(EXIT_SUCCESS);
}
