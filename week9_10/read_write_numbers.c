#include <stdio.h>
#define MAX_LEN 1000
void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main()
{
    int a[MAX_LEN];
    FILE *myFile;
    FILE *wFile;
    int count =0;

    myFile = fopen("numbers.txt", "r");
    wFile = fopen("sorted_numbers.txt", "w");
    if (myFile == NULL)
    {
        printf ("Error opening file\n");
        return 1;
    }


   while (!feof(myFile)&&!ferror(myFile))   
    {
        /* Read next number of file. */
        if(fscanf (myFile, "%d", &a[count])==1)   
        count++;
    }

   printf("There are %d numbers in the file.", count); 

   selection_sort(a, count);

   //printf("In ascending order:\n");   
   int i;
   for(i=0; i<count; i++)
   {
//	printf("%d\t", a[i]);
	fprintf(wFile, "%d\n", a[i]);
   }
  

   fclose(myFile);
   fclose(wFile);
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
            
