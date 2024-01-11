/* Dylan Skroskznik 			NOV. 23 2021
 *	This C file compiles all relative functions supporting the
 *	book request list program.
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

//mass gathers users specifc information on a book
//that proceeds to compare existing information to the database
//to lower multiple requests included, but stores nonexisting
//data into the book request list
struct book *add_to_end(struct book *list)
{
	//function variable allocated and initialized
	struct book *new_book = malloc(sizeof(struct book));
	struct book *i;
	
	//when structer is empty the system fails
	if(new_book==NULL) {
		printf("Request has failed.\n");
		return list;
	}

	//enters required information for each book
	printf("Please enter the below information:\n");
	printf("\tBook Title: ");
	read_line(new_book->title,BOOK_LEN);
	printf("\n\tAuthor's First Name: ");
	read_line(new_book->a_first,NAME_LEN);
	printf("\n\tAuthor's Last Name: ");
	read_line(new_book->a_last,NAME_LEN);
	printf("\n\tClassroom Library: ");
	read_line(new_book->classroom,CLASS_LEN);

	//tests for any similar books included in the list
	for(i=list;i!=NULL;i=i->next) {
		if(!strcmp(i->title,new_book->title)&&!strcmp(i->a_first,new_book->a_first)
			&&!strcmp(i->a_last, new_book->a_last)&&!strcmp(i->classroom,new_book->classroom)) {
			printf("The current information already exists in the request list.\n"
				"Returning back to prompt page.\n");
			return list;
		}
	}
	
	printf("\nPlease enter the book price: ");
	scanf("%lf",&new_book->price);
	
	//linked lists organizing
	new_book->next=NULL;
	if(list==NULL) {
		return new_book;
	}
	//stores new book to end of list
	i=list;
	while(i->next!=NULL) {
		i=i->next;
	}
	i->next=new_book;
	
	return list;
}//end add_to_end

//obtains users specific information to help search a required book
void search(struct book *list) 
{
	//function variables allocated and initialized
	struct book *search = malloc(sizeof(struct book));
	struct book *s;
		
	printf("Please enter the below information:\n");
	printf("\tBook Title: ");
	read_line(search->title,BOOK_LEN);
	
	//checks for information absent in the list
	for(s=list;s!=NULL;s=s->next) {
		if(strcmp(s->title,search->title)) {
			printf("This information can not be located in the request list.\n"
				"Please check your information to find the book,\n"
				"or please add the book information to the request list.");
			return;
		}
	}
	//applies the discovered information to print
	s=list;
	printf("\nThe following information have been found in the request list:\n%6s,\t%6s,\t%6s,\t$%.2lf,\t%3s \n",s->title,s->a_first,s->a_last,s->price,s->classroom);
	
}//end search

//gathers each memeber entered for the list structer and prints out
void print_list(struct book *list)
{
	//function variable defined
	struct book *pr;
	
	for(pr=list;pr!=NULL;pr=pr->next) {
		printf("%6s,\t%6s,\t%6s,\t$%.2lf,\t%3s \n",pr->title, pr->a_first, pr->a_last, pr->price, pr->classroom);
	}	
	printf("\n");

}//end print_list

//reads through a structed list and whipes it clear from information
void clear_list(struct book *list) 
{
	//func variable defined
	struct book *clear;

	while(list!=NULL) {
		clear=list;
		list=list->next;
		if(clear!=NULL) {
			free(clear);
		}
	}

}//end clear_list

