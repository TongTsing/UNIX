#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(){
        int sourceFD;
        int flags;
	int BUF_SIZE = 10;
	char * BUF;
	char tmp[10]={'0'};
	BUF = (char *)malloc(sizeof(char) * BUF_SIZE);
	if(BUF==-1)
	{
		printf("malloc failed!\n");
		return -1;
	}
	for(int i=0; i<10; i++){
		*(BUF+i) = 65+i;
	}
        sourceFD = open("1.txt",O_WRONLY|O_CREAT, 666);
        if (sourceFD == -1)
        {
                printf("open File failed! exit......\n");
                return -1;
        }
        flags = fcntl(sourceFD, F_GETFL);
        if (flags == -1)
        {
                printf("get sourceFD flags faild! exit....\n");
		close(sourceFD);
                return -1;
        }
        printf("sourceFD flags is: %d\n", flags);
        if(flags|O_ACCMODE == O_WRONLY)
                printf("file flags is O_WRONLY\n");

        printf("we will set flags for sourceFD!\n ");

        flags = fcntl(sourceFD, F_SETFL, flags|O_APPEND);
        if (flags == -1){
                printf("set flags for sourceFD failed!\n");
		close(sourceFD);
                return -1;
        }
        printf("set flag for sourceFD success!\n");
	write(sourceFD, BUF, BUF_SIZE);
	close(sourceFD);
        return 0;
}
