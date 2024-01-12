/* Dylan Skroskznik			Jan. 31 2021
 *  	This program interprets the digits of a phone number and translates letter characters
 *  	to corresponding cellphone digits to the input number. 
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char num; //phone number variable of type character
	
	//prompt for user to input phone number
	printf("Number Input: ");
	while (num !='\n'){ //while loop to that grab character type while not character '\n'
		num = getchar();
		num = toupper(num); //updates character input capatilized
		switch (num){ //switch statment assigned direct letter in phone number to corresponding digit
			case 'A': num = '2';
			case 'B': num = '2';
			case 'C': num = '2';
				break;	
			case 'D': num = '3';
			case 'E': num = '3';
			case 'F': num = '3';
				break;
			case 'G': num = '4';
			case 'H': num = '4';
			case 'I': num = '4';
				break;
			case 'J': num = '5';
			case 'K': num = '5';
			case 'L': num = '5';
				break;
			case 'M': num = '6';
			case 'N': num = '6';
			case 'O': num = '6';
				break;
			case 'P': num = '7';
			case 'Q': num = '7';
			case 'R': num = '7';
			case 'S': num = '7';
				break;
			case 'T': num = '8';
			case 'U': num = '8';
			case 'V': num = '8';
				break;
			case 'W': num = '9';
			case 'X': num = '9';
			case 'Y': num = '9';
			case 'Z': num = '9';
				break;
		} 	
		printf("%c", num); //loops num character after replaced by the letter in switch
		
	} 
	return 0; //ends program
}
