/* Dylan Skroskznik	cop3514		MAR. 6 2021
 *	This program asks the user to enter a valid email address that verifies the
 *	domain name so it applies a store discount with said domain name '.edu' and displays
 *	a message that indicates whether it's a valid email address for the discount code.
 */

#include <stdio.h>
#define EMAIL_LEN 1000 //initialize a email character cap
int read_line(char *str, int n); //readsarray line and elements
int validate(char *s1);//validate function for email winner confirmation
int main() 
{
	char eml[EMAIL_LEN+1];//char string array for emails indexed on email length
	int valid;// validation variable
	
	printf("Enter an email address to verify if it's a valid address for a discount code. \n(traditional address needed: example123@website.xxx)\n\nInput: ");	
	
	read_line(eml, EMAIL_LEN);//calling read_line func to read through the string array
	
	valid = validate(eml);//calling and initializing validate function to confirm a win or lose
	printf("Output: ");
	if (valid) {//if valid is true
		printf("Verification successful");	
	}
	else {//valid is false
		printf("Not eligible for discount code");
	}
	printf("\n");
	return 0;
}//exit main

int validate(char *s1)
{
	char *p;//character pointer
	int len;//length variable
	for(p=s1;*p!='\0';p++) {//for loop, files over input email for length
		len++;	
	}
	//if statment grabs final 4 charcters input to declare a valid winner
	if((*(s1+len-4)=='.')&&(*(s1+len-3)=='e')&&(*(s1+len-2)=='d')&&(*(s1+len-1)=='u')) {
	  return 1;
	}
	else {//if doesn't return validated
	  return 0;
	}
}//exit function

int read_line(char *str, int n)
{
	int ch, i = 0;
	while((ch = getchar())!='\n') {
		if(i<n) {
			*str++ = ch;
			i++;
		}
	}
	*str = '\0'; //terminates string
	return i; //number of characters stored
}//exit function
