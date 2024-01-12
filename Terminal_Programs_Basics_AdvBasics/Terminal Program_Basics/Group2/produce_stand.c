/* Dylan Skroskznik			Jan. 31 2021
 *  	This program calculates the charge of selects items by their charge
 *  	per pound and quantity to a total, this program only accepts cash. 
 */
#include <stdio.h>

#define LEMONS 0.21 	//lemon price
#define LETTUCE 2.39 	//lettuce price
#define POTATOES 0.79 	//potatoes price
#define BEANS 0.99 		//beans price
#define AVOCADO 1.50 	//avocado price
#define TOMATOES 1.99 	//tomatoes price

int main(void)
{
	double w, pay, change, total; //variable display type double money transaction charges
	int s, q; //variable integers for selection list and quantity unknown

	printf("Please select from the list of items:\n"); //Select list of items 
	printf(" 1. Lemons - $%.2lf each \n",LEMONS); 
	printf(" 2. Lettuce - $%.2lf each \n",LETTUCE);	
	printf(" 3. Potatoes - $%.2lf/lb \n",POTATOES);		
	printf(" 4. Beans - $%.2lf/lb \n",BEANS);	
	printf(" 5. Avocado - $%.2lf each \n",AVOCADO);
	printf(" 6. Tomatoes - $%.2lf/lb \n",TOMATOES);	
	printf("Complete this order by selecting 0 product.\n\n"); //input zero to complete order

	do { //do while loop to attribute reoccurence of user input when input is rejected
		printf("Enter produce selection: ");
		scanf("%d",&s);
		while (s > 6) {
			printf("Invalid selection number.\nRe-enter produce selection from 1 - 6: ");
			scanf("%d",&s); }	
		switch (s) { //switch statement distributing calculations for price off quantity and weight 
			case 1: printf("Enter number of items: "); //case for LEMONS
				scanf("%d",&q);
					double amount1 = (double)q * LEMONS;
					total += amount1;
				break;
			case 2: printf("Enter number of items: "); //case for LETTUCE
				scanf("%d",&q);
					double amount2 = (double)q * LETTUCE;
					total += amount2;
				break;
			case 3: printf("Enter weight(lb): "); //case for POTATOES
				scanf("%lf",&w);
					double amount3 = w * POTATOES;
					total += amount3;
				break;
			case 4: printf("Enter weight(lb): "); //case for BEANS
				scanf("%lf",&w);
					double amount4 = w * BEANS;
					total += amount4;
				break;
			case 5: printf("Enter number of items: "); //case for AVOCADOS
				scanf("%d",&q);
					double amount5 = (double)q * AVOCADO;
					total += amount5;
				break;
			case 6: printf("Enter weight(lb): "); //case for POTATOES
				scanf("%lf",&w);
					double amount6 = w * TOMATOES;
					total += amount6;
				break;
			}
	} while (s > 0); //do while ends if user input is zero

		printf("\nTotal amount due($): $%.2lf",total);//prints total due
		
		printf("\n\nEnter cash received($): ");//user inputs cash payment
		scanf("%lf", &pay);
			change = pay - total;
		printf("\nYour total change is $%.2lf", change);//total change back

	return 0;
}
















