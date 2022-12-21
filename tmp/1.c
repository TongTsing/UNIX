#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd;
	fd = open("1.tmp", O_WRONLY);
	write(fd, "hehe", 5);
	printf("ok, exit....");
	close(fd);
	return 0;
}
