/* Dylan Skroskznik 	cop3514		9/19/21
 *  	This program finds and outputs absent amount of numbers 
 *  	missing from a selection of numbers from an array 
 *	with range [1,n] with 'n' being the array length.
 */

#include <stdio.h>

//initialized function as function header
void find(int n, int a[], int b[]);
int main()
{
	int i, n;//main variables
	
	printf("Enter the length(n) for the input array: ");
	scanf("%d", &n);//scans for array length

	int a[n];//created arrays with preapplied length
	int b[n];

	printf("Enter the input array elements within range [1,%d]: ", n);
	for(i=0;i<n;i++)//adds new integers input for each element in array
		scanf("%d", &a[i]);
	
	//calls the find function attached out of the main func
	find(n,a,b);
	
	//active conditional statements for supporting the
	//find function and outputs necessary values
	printf("Output: ");
	for(i=1;i<=n;++i) {
		if((b[i-1]==0)) { //prints missing ranging numbers from array b
			printf("%d ", i);	
		}
	}

	printf("\n");		
	return 0;
}//end main

void find(int n, int a[], int b[]) 
{
	//variables for conditional loops
	int j, k;
	
	//stored common elements from array a as 1's in array b 
	for(j=0;j<n;++j) {
		for(k=0;k<n;++k) {
	      		if((j+1)==a[k]) {
				b[j]=1;	
			}
		}
	}
}//end find
