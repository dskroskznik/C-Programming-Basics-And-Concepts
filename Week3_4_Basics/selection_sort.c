
#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void)
{
  int i;
  int a[N];

  printf("Enter %d numbers to be sorted: ", N);
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  selection_sort(a, N);

  printf("In sorted order:");
  for (i = 0; i < N; i++)
    printf(" %d", a[i]);
  printf("\n");

  return 0;
}

void selection_sort(int a[], int n)
{
  int largest = 0, temp;

  //fill in code


}

int find_largest(int a[], int n)
{
   //fill in code
}

