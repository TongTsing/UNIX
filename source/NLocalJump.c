#include <stdio.h>
#include <setjmp.h>



static jmp_buf env;
//这里使用static 定义函数的原因是；已初始化的静态函数为强符号；已初始化的强
static void fn2(void){
	longjmp(env, 2);
}

static void fn1(int argc){
	if(argc == 1)
	{
		longjmp(env, 1);
	}
	printf("entry fn2\n\n");
	fn2();
}
// setjmp()第一次返回0;第二次返回longjmp(env, tag)的tag值
int main(int argc, char ** argv){
	switch (setjmp(env)){
		case 0://setjmp(env)执行完成后会返回一个0；等待后续的longjmp(env, val)会返回指定的val

		        printf("Call fn1 after initial setjmp()\n");
	       	        fn1(argc);
			break;
		case 1:
			printf("we jumped back from fn1()\n");
			printf("we will entry fn2()\n");
			fn2();
	 		break;
		case 2:
			printf("we jumped back from fn2()\n");
			break;		
	}

	exit(0);
}
