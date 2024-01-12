/*Dylan Skroskznik	COP3514		10/4/21
 *	
 * 	*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
void multi_vec(int *v1 , int *v2 , int *v3 , int n);
int main()
{
	int i, size;
	
	printf("Please enter the length of the vector: \n");
		scanf("%d", &size);
		int a[size];
		int b[size];
		int c[size];

	printf("Enter the first vector: ");
	for(i=0;i<size;i++) {
		scanf("%d", &a[i]);
	}	
	printf("Enter the second vector: ");
	for(i=0;i<size;i++) {
		scanf("%d", &b[i]);
	}	
	
	multi_vec(a , b , c , size);
	
	for(i=0;i<size;i++) {
		scanf("%d\n", &c[i]);
	}
	
	return 0;
		
}
	
void multi_vec(int v1[] , int v2[] , int v3[] , int n)
{
	int *p, *q, *r;
	
	for(p=&v1[0], q=&v2[0], r=&v3[0] ; p<&v1[n] ;p++, q++, r++) {
		*r = *p * *q;
	}

}
