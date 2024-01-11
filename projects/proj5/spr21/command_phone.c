/* Dylan Skroskznik	cop3514		MAR. 6 2021
*  	This program interprets user inputs digits of a phone number and translates letter characters
 *  	to corresponding cellphone digits, having been checked if the correct number of arguments are entered
 *  	on the command line inputs which the program displays a message. 
 */

#include <stdio.h>
#include <string.h>//string function library 

void translate(char *word, char *phone_number);//apply function definition for phone digit translation

int main(int argc, char *argv[])
{	
	//input/output array variables declared for command line argument 
	char in[argc-1];
	char out[argc-1];
	
	strcpy(in,argv[1]);//string copy function to copy argument vector to inout string array
	translate(in,out);//traslate function called after calculating
	
	//if statment to support no segmentation fault from command line arguments
	if(argc==2) {
	
  	 printf("Output: ");
	 	printf("%s", out);//prints final calculated output array
	   	printf("\n");//new line
	 
	}
	else printf("Incorrect number of arguments. Usage: ./a.out [TRANSLATE PHONE NUMBER]\n");
	return 0;//completes main
}//exit main

//translate function, points to characters across a phonenumber to replace letters with digits
void translate(char *word, char *phone_number)
{
	char *p;//pointer index
	
	//for loop, filing through input array from the *word pointer
	for(p=word;*p!='\0';p++) { //when not '\0' it increments
		switch(*p) { //switch statment assigned direct letter in phone number to corresponding digit
			case 'A': *phone_number = '2';
				  phone_number++;//increment pointer pointing to output array
				break;
			case 'B': *phone_number = '2';
				  phone_number++;
				break;
			case 'C': *phone_number = '2';
				  phone_number++;;
				break;	
			case 'D': *phone_number = '3';
				  phone_number++;
				break;
			case 'E': *phone_number = '3';
				  phone_number++;
				break;
			case 'F': *phone_number = '3';
				  phone_number++;
				break;
			case 'G': *phone_number = '4';
				  phone_number++;
				break;
			case 'H': *phone_number = '4';
				  phone_number++;
				break;
			case 'I': *phone_number = '4';
				  phone_number++;
				break;
			case 'J': *phone_number = '5';
				  phone_number++;
				break;
			case 'K': *phone_number = '5';
				  phone_number++;
				break;
			case 'L': *phone_number = '5';
				  phone_number++;
				break;
			case 'M': *phone_number = '6';
				  phone_number++;
				break;
			case 'N': *phone_number = '6';
				  phone_number++;
				break;
			case 'O': *phone_number = '6';
				  phone_number++;
				break;
			case 'P': *phone_number = '7';
				  phone_number++;
				break;
			case 'Q': *phone_number = '7';
				  phone_number++;
				break;
			case 'R': *phone_number = '7';
				  phone_number++;
				break;
			case 'S': *phone_number = '7';
				  phone_number++;
				break;
			case 'T': *phone_number = '8';
				  phone_number++;
				break;
			case 'U': *phone_number = '8';
				  phone_number++;
				break;
			case 'V': *phone_number = '8';
				  phone_number++;
				break;
			case 'W': *phone_number = '9';
				  phone_number++;
				break;
			case 'X': *phone_number = '9';
				  phone_number++;
				break;
			case 'Y': *phone_number = '9';
				  phone_number++;
				break;
			case 'Z': *phone_number = '9';
				  phone_number++;
				break;
			default : *phone_number = *p;
				  phone_number++;
				break;//ends case statements
		}
	}
}//exit function
