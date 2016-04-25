#include "stdio.h"
#include "sys/types.h"
#include "unistd.h"


pid_t do_fork() {
	pid_t r = fork();
	if (r <  0) {
		printf(" [E] error in fork\n");
	} else if(r == 0) {
		printf(" [I] I am child(%d) from father(%d)\n", getpid(), getppid());
	} else {
		printf(" [I] I am father(%d)\n", getpid());
	}
	return r;
}

int main()
{
	pid_t pid1;
	pid_t pid2;
	pid_t pid3;

	printf("pid is %d\n", getpid());

	printf("-- fork 1 ---\n");
	pid1 = do_fork();
	sleep(2);

	printf("-- fork 2 ---\n");
	pid2 = do_fork();
	sleep(2);

	printf("-- fork 3 ---\n");
	pid3 = do_fork();
	sleep(2);

	printf("self:%d ppid:%5d  pid1:%5d pid2:%5d pid3:%5d\n", getpid(), getppid(), pid1, pid2, pid3);

	while(1);
	return 0;
}

/* 
 * Updated a good article:
 *
 * http://www.geeksforgeeks.org/fork-and-binary-tree/
 */

/*
 *      $ ./pstree -p
	├─bash(32006)───test_fork(18117)─┬─test_fork(18118)─┬─test_fork(18120)───test_fork(18124)
	│                                │                  └─test_fork(18122)
	│                                ├─test_fork(18119)───test_fork(18123)
	│                                └─test_fork(18121)

	$ ./test_fork
	pid is 18117
	-- fork 1 ---
	 [I] I am father(18117)
	 [I] I am child(18118) from father(18117)
	-- fork 2 ---
	 [I] I am father(18117)
	-- fork 2 ---
	 [I] I am father(18118)
	 [I] I am child(18119) from father(18117)
	 [I] I am child(18120) from father(18118)
	-- fork 3 ---
	 [I] I am father(18117)
	-- fork 3 ---
	 [I] I am father(18118)
	-- fork 3 ---
	 [I] I am father(18119)
	 [I] I am child(18121) from father(18117)
	-- fork 3 ---
	 [I] I am father(18120)
	 [I] I am child(18123) from father(18119)
	 [I] I am child(18122) from father(18118)
	 [I] I am child(18124) from father(18120)

	self:18117 ppid:32006  pid1:18118 pid2:18119 pid3:18121
	self:18118 ppid:18117  pid1:    0 pid2:18120 pid3:18122
	self:18119 ppid:18117  pid1:18118 pid2:    0 pid3:18123
	self:18122 ppid:18118  pid1:    0 pid2:18120 pid3:    0
	self:18121 ppid:18117  pid1:18118 pid2:18119 pid3:    0
	self:18123 ppid:18119  pid1:18118 pid2:    0 pid3:    0
	self:18124 ppid:18120  pid1:    0 pid2:    0 pid3:    0
	self:18120 ppid:18118  pid1:    0 pid2:    0 pid3:18124

*/

