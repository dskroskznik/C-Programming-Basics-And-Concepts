/* Dylan Skroskznik	cop3514		FEB. 28  2021
 *	This program asks the user to insert an arbitrary number(x) into an array and rearrange
 *	so that all array elements are less than or equal to the number(x) are positioned before number(x),
 *	and array elements after number(x) are greater than number(x).
 */

#include <stdio.h>
//assign the rearrage array function before main
void rearrange(int *a, int *b, int n, int insert);

int main()
{
	int i, n, x;//user input variables for array length, elements, and insertion
	
	printf("Enter the length of the array: ");
	scanf("%d", &n);//scans user input for array lengths

	int a[n];//array 'a' with assigned length
	int b[n+1];//array 'b' with assigned length plus 1

	printf("Enter the elements of the array: ");
	for(i=0;i<n;i++) //files each array number into every element of the array
		scanf("%d", &a[i]);//scans for each array element user inputs

	printf("Enter the arbitrary number inserted in the array: ");
	scanf("%d", &x);//scans the user for arbibtrary number

	rearrange(a, b, n, x); //calls rearrange function to 
	
	printf("Output:\n"); //prints final array output

	for(i=0;i<n+1;i++) {
		printf(" %d", b[i]);
		}

	printf("\n"); 
	return 0;

}//end main

void rearrange(int *a, int *b, int n, int insert)
{
	int *p;

	for(p=a;p<(a+n);p++) {
		if(insert>=*p) { 
			*b = *p;
			b++;
		} 
	}

	*b = insert;
	b++;	

	for(p=a;p<(a+n);p++) {
		if(insert<*p) { 
			*b = *p;	
			b++;	
		}	
	}
	
}//end rearrange	
