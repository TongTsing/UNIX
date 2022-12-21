#include <stdio.h>
#include <fcntl.h>
#include <time.h>

int main(){
	open("2.txt", O_WRONLY|O_CREAT, '666');
	return 1;
}
