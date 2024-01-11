#include <stdio.h>

#define QUARTERS 25
#define NICKELS 5
#define DIMES 10
#define PENNIES 1

int main(void)
{
	int num_quarters, num_dimes, num_nickels, num_pennies;

	printf("Enter quarter amount: ");
		scanf("%d", &num_quarters);
	printf("Enter dimes amount: ");
		scanf("%d", &num_dimes);
	printf("Enter nickels amount: ");
		scanf("%d", &num_nickels);
	printf("Enter pennies amount: ");
		scanf("%d", &num_pennies);

	int amount = (num_quarters * QUARTERS) + (num_dimes * DIMES) + (num_nickels * NICKELS) + num_pennies;

	printf("total is %d\n", amount);
	return 0;
}
