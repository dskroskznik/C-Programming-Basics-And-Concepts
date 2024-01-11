/* Dylan Skroskznik	COP3514		9/1/21
 * 	This program is designed based off the Chinese lunar calendar of chinese zodiac represented
 * 	as aninmals and reputed attributes to each year over a 12-year cycle. We shall use this
 * 	to help calculate the animal sign for any specific year cyclced.
 **/
#include <stdio.h>

int main() 
{
	int b_year, remainder;

	printf("Enter year of birth (YYYY): ");
	scanf("%d", &b_year);

	if(b_year <= 0) printf("The value entered was invalid, aborting program...");
	else 
	  remainder = b_year%12;

	switch(remainder) {
		case 0: printf("The Chinese Animal Sign For This Year Is MONKEY.\n");
			break; 
		case 1: printf("The Chinese Animal Sign For This Year Is ROOSTER.\n");
			break;
		case 2:	printf("The Chinese Animal Sign For This Year Is DOG.\n");
			break;
		case 3: printf("The Chinese Animal Sign For This Year Is PIG.\n");
			break;
		case 4: printf("The Chinese Animal Sign For This Year Is RAT.\n");
			break;
		case 5: printf("The Chinese Animal Sign For This Year Is OX.\n");
			break;	
		case 6: printf("The Chinese Animal Sign For This Year Is TIGER.\n");
			break;
		case 7: printf("The Chinese Animal Sign For This Year Is RABBIT.\n");
			break;
		case 8: printf("The Chinese Animal Sign For This Year Is DRAGON.\n");
			break;
		case 9: printf("The Chinese Animal Sign For This Years Is SNAKE.\n");
			break;
		case 10: printf("The Chinese Animal Sign For This Year Is HORSE.\n");
			break;
 		case 11: printf("The Chinese Animal Sign For This Year Is SHEEP.\n");
			break;
		default: printf("Something went wrong... \n");
			break;
	}

	return 0;
}
