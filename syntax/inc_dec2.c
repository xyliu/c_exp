#include <stdio.h>

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
	return 0;
}
