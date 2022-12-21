#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv){	
	int res=-11;
	int fd = -1;	
	struct stat *restrict buf;
	if(argc == 0)
		printf("请输入要查看的文件属性：\n");
	buf =(struct stat *) malloc(sizeof(struct stat));
	fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		printf("openfile failed!\n");
		return -1;
	}
	res = fstat(fd, buf);
	printf("res:%d\n", res);
	printf("fileMode: %d\n", buf->st_mode);
	close(fd);
	return res;
}
