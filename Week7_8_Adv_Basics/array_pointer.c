#include <stdio.h>
#define N 5

int main()
{

	int a[N] = {23, 4, 6, 19, 3};
	int i;
	
	
	printf("&a[0]: %p\n", &a[0]);

	printf("a: %p\n", a);
	
	for(i=1; i<N; i++)
	{
		printf("&a[%d]: %p\n", i, &a[i]);
		printf("a + %d: %p\n", i, a+i);
	}	
	return 0;
}
