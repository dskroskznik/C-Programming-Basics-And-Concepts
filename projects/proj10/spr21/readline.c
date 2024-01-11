/* Dylan Skroskznik 	cop3514		APR. 4 2021
 *	This program will support in managing the registrations and attendence list for the 
 *	summer camp using structured functions with linked list to order each person by name, age, email.
 * THIS FILE HOLDS THE NECESSARY FUNCTION "read_line" 
 * * */

//READLINE FUNCTION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';

return i;
}//end read_line
