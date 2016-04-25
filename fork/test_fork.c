#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"

int main()
{
	pid_t pid1;
	pid_t pid2;
	pid_t pid3;

	printf("pid is %d\n", getpid());

	pid1 = fork();
	pid2 = fork();
	pid3 = fork();

	printf("self:%d ppid:%5d  pid1:%5d pid2:%5d pid3:%5d\n", getpid(), getppid(), pid1, pid2, pid3);

	while(1);
	return 0;
}

/*
 * Output 
 *
 * $ ./test_fork 
 * pid is 15832
 * self:15832 ppid:32006  pid1:15833 pid2:15834 pid3:15835
 * self:15835 ppid:15832  pid1:15833 pid2:15834 pid3:    0
 * self:15834 ppid:15832  pid1:15833 pid2:    0 pid3:15837
 * self:15837 ppid:15834  pid1:15833 pid2:    0 pid3:    0
 * self:15833 ppid:15832  pid1:    0 pid2:15836 pid3:15838
 * self:15838 ppid:15833  pid1:    0 pid2:15836 pid3:    0
 * self:15836 ppid:15833  pid1:    0 pid2:    0 pid3:15839
 * self:15839 ppid:15836  pid1:    0 pid2:    0 pid3:    0
 *
 *
 * $ ./pstree -p
 *
 * ├─bash(32006)───test_fork(15832)───test_fork(15833)─┬─test_fork(15836)───test_fork(15839)
 *                                        │            └─test_fork(15838)
 *                                        ├─test_fork(15834)───test_fork(15837)
 *                                        └─test_fork(15835)
 *
 *
 */
