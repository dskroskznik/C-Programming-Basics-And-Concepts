/* Dylan Skroskznik 			APR. 4 2021
 *	This program will support in managing the registrations and attendence list for the 
 *	summer camp using structured functions with linked list to order each person by name, age, email.
 * THIS FILE REPRESENTS THE HEADING FOR ANY FUNCS DECLARED AND STRUCTURES INCLUDED AND UTILIZED FOR THE PROGRAM
 * */

//HEADING STRUCTURE SETS AND FUNCTION DECLARATIONS

#define EMAIL_LEN 100 
#define NAME_LEN 30
#define STATUS_LEN 30
#ifndef REQUEST_H
#define REQUEST_H 

//create request structure for personal information
struct request{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int age;
	char status[STATUS_LEN+1];
	struct request *next;
};

//contruct parameter lists for your attending functions
struct request *append_to_list(struct request *list);
void update(struct request *list);
void print_list(struct request *list);
void clear_list(struct request *list);

#endif
