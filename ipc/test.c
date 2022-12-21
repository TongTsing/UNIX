#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void child(int * writeFd){
	char buff[1024];
	int n = -99;
	while((n = read(writeFd[0], buff, 1024))){
		printf("read %d bytes from pipe\n", n);
		printf("read buff = %s\n", buff);
	}
	printf("child Done");
}

int main(){
	int fd1[2], fd2[2];
	int childPid;
	char buff[1024];
	int n;
	//pipe(fd1);
	pipe(fd2);
	if((childPid=fork())==0){
		close(fd2[1]);
		child(fd2);
		exit(0);
	}
	close(fd2[0]);
	fgets(buff,1024, stdin);
	n=write(fd2[1], buff, 1024);
	printf("write to  child! content = %s\n", buff);
	printf("wait child:%d exit\n", childPid);
	printf("main Done!\n");
	return 1;
}
