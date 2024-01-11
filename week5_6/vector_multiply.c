#include <stdio.h>
#define TRUE 1
#define FALSE 0

void multi_vec(int *v1, int *v2, int *v3, int n);

int main(void)
{

	int i;
	int size;
        printf("Please enter the length of the vectors:\n");
        scanf("%d", &size);
        int a[size];
        int b[size];
        int c[size];
        printf("enter the first vector");
        for(i=0;i<size;i++)
        {
           scanf("%d", &a[i]); 
        }
        printf("enter the second vector");
        for(i=0;i<size;i++)
        {
           scanf("%d", &b[i]); 
        }
	multi_vec(a, b, c, size);
        for(i=0;i<size;i++)
        {
           printf("%d\t", c[i]); 
        }

	return 0;

}

void multi_vec(int *a, int *b, int *c, int n)
{
      int *p;
      int *q=b;
      int *l=c;
     
      for(p=a; p<a+n;p++)
	*l++=*p**q++;
}

	
