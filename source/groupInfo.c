#include <stdio.h>
#include <grp.h>

int main(int argc, char ** argv){
	struct group *tmpGroup;
	int memCount = -1;
	/*
	tmpGroup = (struct group *)malloc(sizeof(struct group));
	if(!tmpGroup){
		printf("malloc Error!\n");
		return -1;
	}
	*/
	if(argc==0){
		printf("ERROR->:   you need to input one params!\n");
		return -1;
	}
	printf("everything seems ok!\n");
	tmpGroup = getgrnam(argv[1]);
	printf("addr model:%lud\n",sizeof(tmpGroup->gr_name));
	memCount = sizeof(tmpGroup->gr_mem)/4;
	printf("memCount=%d\n", memCount);

	printf("Group%s->name=%s\n",tmpGroup->gr_name, tmpGroup->gr_name);
	printf("Group%s->members:",tmpGroup->gr_name);
	for(int i=0; i<memCount; i++)
		printf("%s,", (tmpGroup->gr_mem)[i]);
	//free(tmpGroup);
	return 0;
	
}
