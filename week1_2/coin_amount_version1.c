#include <stdio.h>

int main(void)
{
	int num_quarters = 6;
	int num_dimes = 10;
	int num_nickels = 3;
	int num_pennies = 2;

	int amount = (num_quarters * 25) + (num_dimes * 10) + (num_nickels * 5) + num_pennies;

	printf("\nYou have %d quarters, %d dimes, %d nickels and %d pennies\n", num_quarters, num_dimes, num_nickels, num_pennies);
	printf("total is $%d\n USD", amount);
	return 0;
}
