#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int fun1(){
	printf("hello fun1\n");
	return 1;
}

int fun2(){
	sleep(0.1);
	printf("hello fun2\n");
}

int main(){
	int pipe1[2], pipe2[2];
	pid_t childpid;
	//pipe(pipe1);
	//pipe(pipe2);
	if((childpid=fork())==0){
		fun1();
	}
	else
		fun2();

	waitpid(childpid, NULL, 0);
	return 1;
}
