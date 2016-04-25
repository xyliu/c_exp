#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

void func_01(int c)
{

	printf("in fun_01(%d)\n", c);
	longjmp(buf, c);
	printf("can't see");
}

int main()
{
	int r = setjmp(buf); 
	switch(r) {
		case 0:
			printf("catch 0:\n");
			func_01(1);
			break;
		case 1:
			printf("catch 1:\n");
			func_01(2);
			break;
		case 2:
			printf("catch 2:\n");
			func_01(4);
			break;
		default:
			printf("catch others(%d), exit\n", r);
			break;

	}
	return 0;
} 
