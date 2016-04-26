#include <stdio.h>

#define CHECK(_test_, fmt, arg...) { \
	if ((_test_) == 0) { \
		printf(": "fmt, ##arg); \
		return -1; \
	} }

void signal_handler(int sig)
{  
	int a, b;
	a = sig;
	if (sig++)
		sig--;
	b = sig;
	printf ("%d --> %d\n", a, b);
	/* exiting = 1; */
}

int main()
{
	int  i;
	for (i=-5; i<5; i++)
		signal_handler(i);


	printf("test cehck return \n");
	CHECK(1, "%d\n", 1);

	printf(" go here!\n");

	CHECK(0, "%d\n", 0);

	printf(" go here!\n");

	return 0;
}
