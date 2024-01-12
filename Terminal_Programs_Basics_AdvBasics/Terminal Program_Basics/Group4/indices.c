/* Dylan Skroskznik			10/6/2021
 *	This program asks the user for an array, and discovers two indices within the array
 *	to calculate a sum such that the sum equals a user input key number 
 */

#include <stdio.h>
//establish function and its parameters 
void find_indices(int a[], int n, int key, int *index1, int *index2);

int main()
{
	int index1, index2;//array index set variables 
	int i, n;
	printf("Enter the length of the array: ");
	scanf("%d",&n);//scans user input
	
	int a[n];//array with size initialized
	printf("Enter the elements of the array: "); 
	for(i=0;i<n;++i) { 
		scanf("%d",&a[i]);//scans for each array element
	}
	
	int k;//key number variable
	printf("Enter the key value: ");
	scanf("%d",&k);//inputs key number

	find_indices(a,n,k,&index1,&index2);//calls find_indices function calculation
	
	//printf output for if the array indices cannot equal key
	if(index1==0&&index2==0)
		printf("Output: No two indices sum to %d\n", k);
	
	//printf output for each array index located
	else printf("Output: %d %d\n", index1, index2); 

	return 0;

}//end main

void find_indices(int a[], int n, int key, int *index1, int *index2)
{
	//local varaibles for function 
	int p;
	int q;
	
	//for loop structure set to find key indices
	//that add to the key number
	for(p=0;p<n-1;p++) {
		for(q=1;q<n;q++) {
			if(key==a[p]+a[q]) {
				*index1=p;
				*index2=q;	
			}
		}
	}

}//end find_indices
