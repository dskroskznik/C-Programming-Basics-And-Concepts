/* Dylan Skroskznik	cop3514		FEB. 6  2021
 *	This program asks the user to input an integer array of numbers, than have the numbers be
 *	replaced by the index numerials from a key array provided as 0 - 9. 
 *	Swaps input numbers from an array to key arrays index numbers.
 */
#include <stdio.h>

//encode function to maintain and arrage array indexes based on indexes number
void encode (int a[], int b[], int key[], int n)
{
	int i, j;
	for(i=0; i<n; i++)//nested for loop sorts and arrage indexes 
		for(j=0; j<n; j++)
		if (a[i] == key[j])
			j = b[i];

}

//main user input and display funtions
int main (void)
{
	int n, i;//variables and array for operating usage
	int key[10] = {0, 9, 1, 8, 2, 7, 3, 6, 4, 5};	

	printf("Enter size of the input array(not >10): ");
	scanf("%d", &n);//allows user input for the array

	int a[n], b[n];

	printf("\nEnter the array numbers: ");
		for(i=0;i<n;i++);//checks nd gives numbers into array 
		scanf("%d", &a[i]);
	printf("\nKey Array: %d", key[10]);//displays key array
	
	encode(a, b, key, n);//encode functions encodes and shows rearranged output array

	return 0;

}
