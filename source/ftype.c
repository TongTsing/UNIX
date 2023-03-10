#include "apue.h"
#include <apue.h>

int main(int argc, char **argv){
	int i;
	struct stat buf;
	char * ptr;
	for(i=1; i<argc; i++){
		printf("%s: ", argv[i]);
		if(lstat(argv[i], &buf) < 0){
			err_ret("lstat error");
			continue;
		}
		else if(S_ISREG(buf.st_mode)){
			ptr = "regular";
		}
		else if(S_ISCHR(buf.st_mode)){
			ptr = "character special";
		}
		else if(S_ISBLK(buf.st_mode)){
			ptr = "bock special";
		}
		else if(S_ISFIFO(buf.st_mode)){
			ptr = "felse ifo";
		}
		else if(S_ISLNK(buf.st_mode)){
			ptr = "symbolic link";
		}
		else if(S_ISSOCK(buf.st_mode)){
			ptr = "socket";
		}
		else
			ptr="** unknown mode **";
		printf("%s\n", ptr);

	}
	exit(0);
}
