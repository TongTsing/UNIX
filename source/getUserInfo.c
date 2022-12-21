#include <stdio.h>
#include <pwd.h>
// struct passwd保存在pwd.h头文件中

int main(int argc, char **argv){
	struct passwd * ret;
	if(!argc){
		printf("no input params!");
		return -1;
	}
	ret = getpwnam(argv[1]);
	printf("name: %s\n", ret->pw_name);
	printf("用户的初始工作目录: %s\n", ret->pw_dir);
	return 1;
}
