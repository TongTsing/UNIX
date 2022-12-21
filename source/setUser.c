#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char **argv){
	printf("uid=%d, gig=%d, euid=%d, egid=%d\n", getuid(), getgid(), geteuid(), getegid());

}


