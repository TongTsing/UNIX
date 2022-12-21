#include <stdio.h>
#include <stdlib.h>

union list_node{
	char *chPtr;
	int *intPtr;
};

int main(){
	union list_node a;
	a.chPtr = (char *)malloc(sizeof(char));
	printf("a.chPtr=%ld\n", a.chPtr);
	printf("typeof a.chPtr:%d\n", sizeof(a.chPtr));
	return 0;
}

