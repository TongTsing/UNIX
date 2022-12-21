#include <stdio.h>
#include <fcntl.h>

void main(){
	int newFd = -1;
	newFd = dup2(0, 11);
	printf("newFd: %d\n", newFd);
}

