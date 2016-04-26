#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
	int a = 2048;
	int b = 1440;

	double d, e;

	printf("%s x %s\n", argv[1], argv[2]);


	d = (double)( a*a + b*b );
    
	printf("%f \n", d);


	e = sqrt(d);

	printf("%f \n", e);


	return 0;
}

	

