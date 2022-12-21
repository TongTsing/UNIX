#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
	int fd;
	char *BUF;
	fd = 0;
	BUF = (char *) malloc(sizeof(char) * (sizeof(*argv[1])));
	for(int i=0; i<argc; i++)
	{
		printf("argv[%d]=%s\n", i, argv[i]);
	}
	read(fd, BUF, sizeof(*argv[1]));
	printf("read:%s\n",BUF);
	return 0;
}
