#include <stdio.h>

int main(void)
{
	int num_quarters;
	int num_dimes;
	int num_nickels;
	int num_pennies;

	printf("Enter quarters amount: "); 
		scanf("%d", &num_quarters);
	printf("Enter dimes amount: ");
		scanf("%d", &num_dimes);
	printf("Enter nickels amount: ");
		scanf("%d", &num_nickels);
	printf("Enter pennies amount: ");
		scanf("%d", &num_pennies);

        int amount = (num_quarters * 25) + (num_dimes * 10) + (num_nickels * 5) + num_pennies;

        printf("total is %d\n", amount);
        return 0;
}
