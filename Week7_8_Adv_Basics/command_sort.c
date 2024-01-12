
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//prototypes
void selection_sort(int a[], int n);
int find_largest(int a[], int n);

// ./a.out 1 2 26 75, (argc = 5)
int main(int argc, char *argv[])
{
     int a[argc-1];
     int i;
     if(argc >1){
	// put contant in argv to array 'a' 	
	for (i=0;i<argc-1 ;i++) {
		a[i] = atoi(argv[i+1]);
		}	
	selection_sort(a, argc-1);	
	for(i=0;i<argc-1;i++) {
		printf("%d\n", a[i]);
		}
        printf("\n");
      }
      else
        printf("usage: ./a.out followed by numbers for sorting\n");
      return 0;
}

void selection_sort(int a[], int n)
{
  int largest = 0, temp;

  if (n == 1)
    return;

 
  largest = find_largest(a, n);

  if (largest < n - 1) {
    temp = a[n-1];
    a[n-1] = a[largest];
    a[largest] = temp;
  }

  selection_sort(a, n - 1);
}

int find_largest(int a[], int n)
{
   int largest_index = 0; 
   int i;
   for (i = 1; i < n; i++)
    if (a[i] > a[largest_index])
      largest_index = i;
   return largest_index;
}


