#include <stdio.h>


int duplicates(int *a, int n);

int main()
{
	int i;
	int n;
	printf("enter the size of the array: ");
	scanf("%d", &n);
	int a[n];
	printf("enter %d array elements: ", n); 
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);

	int result = duplicates(a, n);
	if(result)
		printf("there are duplicates in the array\n"); 
	else
		printf("no duplicates\n"); 
	
	return 0;
}

int duplicates(int *a, int n)
{
	
}
