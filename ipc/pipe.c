#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAXLINE 1024

int client(int readFd, int writeFd){
	int len;
	ssize_t n;
	ssize_t wrnum;
	char buff[MAXLINE];
	printf("child=%d::: please input pathname!\n", getpid());
	fgets(buff, MAXLINE, stdin);
	printf("child=%d::: input over!\n", getpid());
	len = strlen(buff);
	printf("inputFile=%s", buff);
	if(buff[len-1]=='\n'){
		len--;
	}
	printf("client:: ready to write pipe!\n");
	wrnum = write(writeFd, buff, len);
	printf("clent::: wrnum = %d\n", wrnum);
	if((n=read(readFd, buff, MAXLINE)) > 0){
	    write(stdout, buff, n);
	    printf("client::: read %d from inputfile!\n", n);
	}
	return len;
}

int server(int readFd, int writeFd){
	int fd;
	ssize_t n;
	char buff[MAXLINE+1];
	sleep(10);
	if((n=read(readFd, buff, MAXLINE))==0){
		printf("server::: read data failed!\n");
	}
	//buff[n] = '\0';//
	printf("server::: buf=%s,total=%d\n", buff, n);
	if( (fd = open(buff, O_RDONLY)) < 0 ){
		printf("server:::  open target file: %s failed!\n", buff);
		n = strlen(buff);
		write(writeFd, buff, n);
	} else {
		while((n = read(fd, buff, MAXLINE)) >0)
			write(writeFd, buff, n);
		close(fd);
	}
	return n;

}


int server2(int readFd, int writeFd){
	int BUFSIZE = 10;
	char * BUF;
	BUF = (char *) malloc(sizeof(char)*BUFSIZE);
	read(readFd, BUF, BUFSIZE);
	printf("receive from pipe: %s\n", BUF);
	

}

int main(int argc, char **argv){
	pid_t childpid;
	int pipe1[2], pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	if ((childpid = fork())==0){
		close(pipe1[0]);
		close(pipe2[1]);
		server(pipe1[1], pipe2[0]);
		exit(0);
	}
	close(pipe1[0]);
	close(pipe2[1]);
	client(pipe2[0], pipe1[1]);
	waitpid(childpid, NULL, 0);
	exit(0);
	return 1;
}
