/* Dylan Skroskznik			FEB. 6 2021
 *		This program will randomly and automatically generate a PIN number code
 *		that, according to the PIN length, wil not contain any repeat integers.
 *		Use random, creation functions to produce a random PIN number.	
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//create function initalizes a rand number to an array index without repeat digits
void create (int a[], int n, int upper, int lower)
{
	srand(time(NULL));//srand generates new seed integer each time used

	int i, j, num = 0;
	num = (rand()%(upper-lower+1))+lower; //formula to produce a rand innteger in range values
	for(i=0; i<n; i++)//for loop to monitor usage of repeat integers
		a[i] = num;
		for(j=0; j<n; j++)	
			if (!(a[j] == num))			
			num = (rand()%(upper-lower+1))+lower;
			a[j] = num;

	for(i=0; i<n; i++)//prints random chosen index digits for the array
		printf("%d", a[i]);
}

int main (void)
{
	int n, upper = 9, lower = 0;//main variables for user input purposes

	printf("Enter length of the PIN code: ");
	scanf("%d", &n);//waits for input of PIN code length
	if (n <= 1 || n >= 9) {//acknowledges the PIN code must be between 2 to 8 numbers long
		printf("Invalid PIN length.\nRe-enter length of the PIN code: ");
		scanf("%d", &n); }

	int a[n];//assigned array with length n

	printf("Output: ");//prints output
	create(a, n, upper, lower);//from void function create

	return 0;

}//end program
