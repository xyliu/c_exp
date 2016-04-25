#include <signal.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>

static sigjmp_buf jmpbuf;

static void myfunc(int signo)
{
	printf("SIGQUIT(0x%x)\n", signo);
	siglongjmp(jmpbuf, 1);
}

int main()
{
	struct sigaction act;
	act.sa_handler = myfunc;
	act.sa_flags = SA_INTERRUPT;
	sigemptyset(&act.sa_mask);

	if (sigaction(SIGQUIT, &act, NULL) < 0)
		perror("sigaction");

	if (sigsetjmp(jmpbuf, 1) == 1)
	{
		printf("I'm jumped ");
	}
	else
	{
		raise(SIGQUIT);
	}

	printf("I'm here ");

	return 0;
}

