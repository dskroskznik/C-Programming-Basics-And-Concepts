#include <stdio.h>

#define QUARTERS 25
#define NICKELS 5
#define DIMES 10
#define PENNIES 1

int main(void)
{
	double  num_quarters, num_dimes, num_nickels, num_pennies;

	printf("Enter quarter amount: ");
		scanf("%lf", &num_quarters);
	printf("Enter dimes amount: ");
		scanf("%lf", &num_dimes);
	printf("Enter nickels amount: ");
		scanf("%lf", &num_nickels);
	printf("Enter pennies amount: ");
		scanf("%lf", &num_pennies);

	double amount = (num_quarters * QUARTERS) + (num_dimes * DIMES) + (num_nickels * NICKELS) + num_pennies;

	printf("total is %.2lf", amount);
	return 0;
}
