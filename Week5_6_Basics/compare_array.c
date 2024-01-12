#include <stdio.h>

int compare_array(int a[], int n, int value);

int main()
{  int count=0;
   int a[7] = {3, 42, 52, 91, 2, 13, 49};
   count = compare_array(a, 7, 25);
   printf("the number of elements greater than 25 is: %d\n", count);
   return 0;
}


int compare_array(int a[], int n, int value)
{	
   int i, count = 0;
   for(i= 0; i <n; i++) {
	   if(a[i]>value)
	      count ++;
   }
   return count;
}

