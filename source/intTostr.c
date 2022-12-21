#include <stdio.h>

int tens(int s){
	int res=1;
	if(s==0)
		return res;
	while(s){
		res *= 10;
		s -= 1;
	}
	return res;
}

int main(){
	char *str;
	int now, old;
	now=0;
	old=0;
	num = 1032103;
	now = tens(3);
	printf("result: %d\n",now);
	return 0;

}
