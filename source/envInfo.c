#include <stdio.h>
//environ 保存本程序从shell继承的环境变量;
//本程序用来打印程序的环境变量

extern char **environ;

int main()
{	
	int length = 0;
	length = sizeof(environ);
	for(int i=0; i<length; i++)
		printf("environ[%d]::::%s\n", i,*(environ+i));
	return -1;
}
