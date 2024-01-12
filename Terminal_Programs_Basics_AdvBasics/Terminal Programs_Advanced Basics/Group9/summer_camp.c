/* Dylan Skroskznik 			APR. 4 2021
 *	This program will support in managing the registrations and attendence list for the 
 *	summer camp using structured functions with linked list to order each person by name, age, email.
 *
 * */

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"
#define EMAIL_LEN 100 
#define NAME_LEN 30
#define STATUS_LEN 30


int main(void)
{
  char code;
//introduce the program and beginning input scanning
  struct request *request_list = NULL;  
  printf("\n\t-=WELCOME TO YOUR REGISTRATION FOR SUMMER CAMP=-\n\n"
	 "Operation Code:\n Enter 'a' for appending to the list, 'u' for updating a request"
	  ",'p' for printing the list, and 'q' for quit.\n");

  for (;;) { //infinite for loop
    printf("Enter operation code('a','u','p','q'): ");
    scanf(" %c", &code);//awaiting operation code scan
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) { //switches to different functions to operate request code
      case 'a': request_list = append_to_list(request_list);
                break;
      case 'u': update(request_list);
                break;
      case 'p': print_list(request_list);
                break;
      case 'q': clear_list(request_list);
		return 0;
      default:  printf("Illegal input\n"); //default output for illegal input
    }
    printf("\n");
  }
}//end main

