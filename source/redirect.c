#include <stdio.h>
#include <fcntl.h>

#define bufsize 1024

int main(){
	int *buf;
	buf = (int *) malloc(sizeof(int)*bufsize);
	for(int i=0; i<bufsize; i++)
	{
		*(buf+i) = i;
	}
	close(0);
	dup2(1, 0);
	write(0, buf, bufsize);
	return bufsize;
}

