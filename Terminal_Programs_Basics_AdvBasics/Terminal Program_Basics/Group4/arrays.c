/* Dylan Skroskznik			10/6/2021
 *	This program asks the user set up an array of elements, then calculates
 *	if the users array holds any duplicate elements, if so, it prints 
 *	a new array of elements that are duplicates from the user array
 */

#include <stdio.h>
//establish function and its parameters 
void find_duplicates(int n, int *a, int *b, int *size);

int main()
{
	//array index set variables 
	int i, n, s;
	printf("Enter the length of the array: ");
	scanf("%d",&n);//scans user input
	
	int x[n];
	int y[n/2];
	//array with size initialized
	printf("Enter the elements of the array: "); 
	for(i=0;i<n;++i) { 
		scanf("%d",&x[i]);//scans for each array element
	}
	
	find_duplicates(n,x,y,&s);//calls find_duplicates function calculation

//	printf("%d\n", s);
	printf("Output: ");//prints the developed duplicate array
	for(i=0;i<s;++i) {
		printf("%d ", y[i]); 
		
	}
	return 0;

}//end main

void find_duplicates(int n, int *a, int *b, int *size)
{
	//local variables for function 
	int *p;
	int *q;
	int bsize;

	//for loop structure set to run though
	//and find duplicate elements
	for(p=a;p<a+n;++p) {
	   for(q=p;q<a+n;++q) {
		if(p==q) {
			continue;
		}
		if(*p==*q) {
			*(b++)=*p;
			bsize++;
		}
							
	   }	
	}
	*size=bsize;
	
}//end find_duplicates
