#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char * a;
	int n = -11;
	int fd=-1;
	a = (char *) malloc(sizeof(char) * 3);
	fd = open("1.txt", O_RDONLY);
	n = read(fd, a, 4);
	printf("read %d bytes! content=%s\n", n, a);
	return 1;
}
