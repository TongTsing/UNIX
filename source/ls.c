#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char **argv){
	char * pathName;
	struct stat buf;
	if(argc==1){
		printf("please input pathname!\n");
		exit(1);
	}
	stat(argv[1], &buf);
	printf("文件权限：%d\n", buf.st_mode);
	printf("文件inode 号：%ld\n", buf.st_ino);
	printf("设备号（文件系统）：%ld\n", buf.st_dev);
	printf("设备和（特殊字符）：%ld\n", buf.st_rdev);
	printf("链接数量：%ld\n", buf.st_nlink);
	printf("文件所属用户的ID：%d\n", buf.st_uid);
	printf("文件所属用户组的ID：%d\n", buf.st_gid);
	printf("文件大小（bytes）：%ld\n", buf.st_size);
	printf("最新访问时间：%ld\n", buf.st_atime);
	printf("最新修改时间：%ld\n", buf.st_mtime);
	printf("最新创建时间：%ld\n", buf.st_ctime);
	printf("最佳I/O 块 大小：%ld\n", buf.st_blksize);
	printf("占用磁盘块数：%ld\n", buf.st_blocks);
	return 1;
}

