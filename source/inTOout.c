#include <stdio.h>
#include <fcntl.h>

int main(){
	int n;
	char buf[1024];
	int flag=0;
	int readCount = 0;
	while(!flag){
	     readCount = read(0, buf, 1024);
             if(write(1, buf, readCount)==-1){
	         printf("write eroor!\n");
	     }     
	}	
	return 0;
}
