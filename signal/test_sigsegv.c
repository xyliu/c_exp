/*
 * http://www.alexonlinux.com/how-to-handle-sigsegv-but-also-generate-core-dump
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int signum)
{
	printf("Process %d got signal %d\n", getpid(), signum);
	signal(signum, SIG_DFL);
	kill(getpid(), signum);
}
int main()
{
	struct sigaction sa_segv;
	sa_segv.sa_handler = sighandler;
	sa_segv.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_segv.sa_mask);
	sigaction(SIGSEGV, &sa_segv, NULL);

	/* original code */
	/* signal(SIGSEGV, sighandler); */

	printf("Process %d waits for someone to send it SIGSEGV\n",
			getpid());
	sleep(1000);
	return 0;
}
