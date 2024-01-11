/* Dylan Skroskznik 	cop3514		9/19/21i
 *  	This program evalutaed a set of arrays of which are similar or different
 *  	and applies modifications to an array to detect if it becomes similar
 *  	to the other array, from these conditions we apply true value when
 *  	comparing the arrays
 */
#include <stdio.h>

// initializing function shift to support array equivalance
void shift(int n, int a[]);
int main()
{
	int i, j, n, value=1; //variable initializing for main func
	
	printf("Enter the length(n) for the input array: ");
	scanf("%d", &n); //gets user input for array length

	int a[n], b[n]; //creates both arrays with array length applied
	
	printf("Enter %d elements for the first array, a[]: \n", n);
	for(i=0;i<n;++i)
		scanf("%d", &a[i]); //inputs each integer for element in array

	printf("Enter %d elements for the second array, b[]: \n", n);
	for(i=0;i<n;++i)
		scanf("%d", &b[i]); //inputs each integer for elements in array

	printf("Output: ");
	
	//for loops and conditional statement managing the array comparison
	//practice to apply a truth value based on the array distinction
	for(i=0;i<n;++i) {
		if(a[i] == b[i]) { //if the element is similar
			for(j=0;j<n;++j) {
				if(a[j]==b[j]) value=1; //if both qare similar 
			}
		}
		else if(a[i] != b[i]) {//if the element is not the same
			shift(n,a); //calls shift func and activates outside main
			for(j=0;j<n;++j) {
				if(a[j]!=b[j]) value=0; //if both are not similar
			}
		}
	}

	//if the value is false or true formed from the previous conditions
	if(value)
		printf("True");
	else
		printf("False");
	
	printf("\n");
	return 0;
}//end main

//array editing function 
void shift(int n, int a[])
{
	//variables supporting the shift action 
	int i;
	int temp;
	
	temp=a[0]; //assigns array element 0 as temp
	for(i=0;i<n-1;++i) {
		a[i]=a[i+1]; //shifts the next array over 1 position
	} 
	
	a[n-1]=temp;//the temp value of array element 0 is now the last element
	
}//end shift
