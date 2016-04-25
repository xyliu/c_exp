/* 
 * https://android.googlesource.com/platform/ndk/+/4e159d95ebf23b5f72bb707b0cb1518ef96b3d03/docs/system/libc/SYSV-IPC.TXT
 *
 * For example, there is no way to automatically release a SysV semaphore
 * allocated in the kernel when:
 *   - a buggy or malicious process exits
 *   - a non-buggy and non-malicious process crashes or is explicitely killed.
 * Killing processes automatically to make room for new ones is an
 * important part of Android's application lifecycle implementation. This means
 * that, even assuming only non-buggy and non-malicious code, it is very likely
 * that over time, the kernel global tables used to implement SysV IPCs will fill
 * up.
 */

#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#define  NUM_SEMAPHORES  32
#define  MAX_FAILS       10


int  main(void)
{
	int   counter = 0;
	int   fails   = 0;
	if (counter == IPC_PRIVATE)
		counter++;
	printf( "%d (NUM_SEMAPHORES=%d)\n", counter, NUM_SEMAPHORES);
	for (;;) {
		int  ret = fork();
		int  status;
		printf("loop: status=%d\n", status);
		if (ret < 0) {
			perror("fork:");
			break;
		}
		if (ret == 0) {
			/* in the child */
			ret = semget( (key_t)counter, NUM_SEMAPHORES, IPC_CREAT );
			if (ret < 0) {
				return errno;
			}
			return 0;
		}
		else {
			/* in the parent */
			ret = wait(&status);
			printf("parent: 01 status=%d\n", status);
			if (ret < 0) {
				perror("waitpid:");
				break;
			}
			if (status != 0) {
				printf("parent: 02  status=%d\n", status);
				status = WEXITSTATUS(status);
				fprintf(stderr, "child %d FAIL at counter=%d: %d\n", ret,
						counter, status);
				if (++fails >= MAX_FAILS)
					break;
			}
		}
		counter++;
		if ((counter % 1000) == 0) {
			printf("%d\n", counter);
		}
		if (counter == IPC_PRIVATE)
			counter++;
	}
	return 0;
}
