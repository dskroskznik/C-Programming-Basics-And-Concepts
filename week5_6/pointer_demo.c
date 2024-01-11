#include <stdio.h>

int main()
{
	// int *p; int* p;
	int * p; //* is for declaring a pointer
	int *q;
	int i = 4;
	int j = 6;

	p = &i;
	q = &j;

	printf("%p\n", p);
	printf("%p\n", &i);

	*p = 32; //update i with *p
	*q = *p;
	printf("%d\n", *p);
	printf("i is %d\n", i);
	printf("j is %d\n", j);

	int k;
	int a[4]= {5,32, 51, 9};
	for(k = 0; k<4; k++)
		printf("%p\n", &a[k]);

	return 0;

}
