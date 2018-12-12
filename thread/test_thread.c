/* https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html */

#include <stdio.h>
#include <pthread.h>

#define NTHREADS 20
void *thread_function(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

int main()
{
	pthread_t thread_id[NTHREADS];
	int i, j;

	for(i=0; i < NTHREADS; i++)
	{
		pthread_create( &thread_id[i], NULL, thread_function, (void *)&i);
	}

	for(j=0; j < NTHREADS; j++)
	{
		;
		//pthread_join( thread_id[j], NULL);
	}

	/* Now that all threads are complete I can print the final result.     */
	/* Without the join I could be printing a value before all the threads */
	/* have been completed.                                                */

	printf("Final counter value: %d\n", counter);
	printf("main() exited.\n");
	return 0;
}

void *thread_function(void *dummyPtr)
{
	int i = *(int *)dummyPtr;
	printf("[%3d]     Thread number %ld\n", i, pthread_self());
	pthread_mutex_lock( &mutex1 );
	printf("    [%3d] Thread number %ld\n", counter, pthread_self());
	counter++;
	pthread_mutex_unlock( &mutex1 );
}
