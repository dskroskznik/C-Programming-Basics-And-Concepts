#include <stdio.h>
#define LEN 9000

void selection_sort(int a[], int n);

int main(void)
{
  int a[LEN];

  FILE *rF;
  FILE *wF;
  int count=0;
  
  rF = fopen("numbers.txt", "r");
  if(rF==NULL) {
	printf("Error opening input file.");
	return 1;
  } 

  wF = fopen("sorted_numbers.txt", "w");
  if(wF==NULL) {
	printf("Error opening output file.");
	return 1;
  }

  while(!feof(rF)&&!ferror(wF)) { 
  	if(fscanf(rF, "%d", &a[count])==1) {
		printf("%d\n", a[count]);
		count++;
	}
  }
  
  printf("There are %d numbers in the file.\n", count);
  selection_sort(a, count);

  int i;
  for(i=0; i<count; i++) {
	fprintf(wF, "%d", a[i]);
	
  }
  fclose(rF);
  fclose(wF);
  return 0;
}

void selection_sort(int a[], int n)
{
  int i, largest = 0, temp;

  if (n == 1)
    return;

  for (i = 1; i < n; i++)
    if (a[i] > a[largest])
      largest = i;

  if (largest < n - 1) {
    temp = a[n-1];
    a[n-1] = a[largest];
    a[largest] = temp;
  }

  selection_sort(a, n - 1);
}
