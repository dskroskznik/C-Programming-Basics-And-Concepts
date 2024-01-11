/* Dylan Skroskznik 	COP3514		NOV. 23 2021
 *	This C file includes the readline function which is instrumental to
 *	supporting the program functions to read through lines scanned in text,
 *
 * */
//include C program function libraries & define constants
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"
	
//when called, it reads and stores a character line in array
int read_line(char str[], int n) 
{
	int ch, i = 0;
	while(isspace(ch=getchar()))
		;
	str[i++]=ch;
	while((ch=getchar())!='\n') {
		if(i<n) {
			str[i++]=ch;
		}
	}

	str[i]='\0';
	
	return i;
}//end read_line

