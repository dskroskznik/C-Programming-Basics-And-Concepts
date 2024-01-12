/* Dylan Skroskznik			Jan. 31 2021
 *  	This program calculates the charge of selects by which they cost per quantity
 *  	and subtotals individual selection purchases until users end confirmation to
 *  	provide a total dollar amount split between 10 total persons. 
 */

#include <stdio.h>
#define EBARS 3.99 //energy bars price per box
#define CANDY 2.39 //candy bars price per box
#define CHIPS 4.79 //chips price per bag
#define PRETZELS 2.99 //pretzels price per bag
#define POPCORNS 3.50 //popcorn price per bag
#define EDRINKS 4.99  //energy drinks price by half dozen

int main()
{
	double cost_per_p, total; //variable display type double money transaction charges
	int quantity, select; //variable integers for selection list and quantity unknown

	printf("Please select from the list of snacks:\n"); //print list of items 
	printf(" 1. Energy Bars - $ %.2lf/box \n",EBARS); 
	printf(" 2. Candy Bars - $ %.2lf/box \n",CANDY);	
	printf(" 3. Chip Bags - $ %.2lf/bag \n",CHIPS);		
	printf(" 4. Pretzel Bags - $ %.2lf/bag \n",PRETZELS);	
	printf(" 5. Popcorn Bags - $ %.2lf/bag \n",POPCORNS);
	printf(" 6. Energy Drinks - $ %.2lf/half-dozen \n",EDRINKS);	

	do { //do while loop to have reoccurence for user input when input is rejected
		printf("Enter selection # from 1-6, to confirm order enter 0: ");
		   scanf("%d", &select);	
		
		while(select > 6 && select != 0) { //if statement to allow another try for entering a valid selection
		   printf("Invalid selection.\nRe-enter selection # from 1-6, complete purchase by entering 0 : ");
		   scanf("%d", &select); 
		}
		//switch statement to calculate prices for each individual item purchase
		switch(select) {
 			case 1: printf("Enter number of boxes: "); //case for energy bars
				scanf("%d",&quantity);
					double subtotal1 = (double)quantity*EBARS;
					total += subtotal1;
				break;
			case 2: printf("Enter number of boxes: "); //case for candy
				scanf("%d",&quantity);
					double subtotal2 = (double)quantity*CANDY;
					total += subtotal2;
				break;
			case 3: printf("Enter number of bags: "); //case for chips
				scanf("%d",&quantity);
					double subtotal3 = (double)quantity*CHIPS;
					total += subtotal3;
				break;
			case 4: printf("Enter number of bags: "); //case for pretzels
				scanf("%d",&quantity);
					double subtotal4 = (double)quantity*PRETZELS;
					total += subtotal4;
				break;
			case 5: printf("Enter number of bags: "); //case for popcorn
				scanf("%d",&quantity);
					double subtotal5 = (double)quantity*POPCORNS;
					total += subtotal5;
				break;
			case 6: printf("Enter number of drinks by half dozen(6 ,12, etc..): "); 
				//case for energy drinks
				scanf("%d",&quantity);
					double subtotal6 = (double)quantity*(EDRINKS/6);
					total += subtotal6;
				break;
			}

	} while(select != 0); //do while ends if user input is zero		
	
	cost_per_p = total/10; //divides the total into a split of 10 
	printf("\nCost per person($): $%.2lf", cost_per_p);//prints cost per person out of total
	printf("\n\n");
	
	return 0;	
}//end program











