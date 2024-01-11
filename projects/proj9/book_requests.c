/* Dylan Skroskznik 	COP3514		NOV. 14 2021
 *	This program will ask user input to manage a compiled list of book requests
 *	for your daycare center, filing each book request by title, author name, price, & class.
 *	Each function supports in adding books to the list, searching the list, printing or clearing it too.
 *
 * */
//include C program function libraries & define constants
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "book.h"
#include "readline.h"
#define BOOK_LEN 150 
#define NAME_LEN 50
#define CLASS_LEN 50

int main()
{
	//main function variables in use
	char ch; 
	struct book *req = NULL; 
	
	//daycare prompt
	printf("\n\t-=DayCare Book Request Database=-\n\nChoose from the following options for managing the book request database:\n"
	" 'a' - add a book to the database list of book requests.\n 's' - search the book database for certain books.\n 'p' - print a current version of the book requests list.\n 'c' - clear the entire current database of book requests.\n 'q' - quit prompt.\n\n");
	for(;;) { //infinite for loop
	//scans an input option that calls each functions use
		printf("Enter an option once: ");
		scanf("%c", &ch);
		while(getchar()!='\n') 
			;
		switch(ch) { //directly accesses the function by each case
			case 'a': req=add_to_end(req);
				  break;
			case 's': search(req);
				  break;
			case 'p': print_list(req);
				  break;
			case 'c': clear_list(req);
				  printf("List cleared\n");
				  break;
			case 'q': return 0;
			default : printf("Invalid input\n");
				  break;
			}
		printf("\n");
	}
}//end main

