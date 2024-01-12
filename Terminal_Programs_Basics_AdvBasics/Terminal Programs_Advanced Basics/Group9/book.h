/* Dylan Skroskznik 			NOV. 23 2021
 *	This program header file includes the necessary function definitions representing
 *	the book requests list functions, along with the book object struct 
 *
 * */
//include C program function libraries & define constants
#ifndef BOOK_H
#define BOOK_H
#define BOOK_LEN 150 
#define NAME_LEN 50
#define CLASS_LEN 50

struct book { 
//structure for each book information
	char title[BOOK_LEN+1];
	char a_first[NAME_LEN+1];
	char a_last[NAME_LEN+1];
	double price;
	char classroom[CLASS_LEN+1];
	struct book *next;
};

//function defintions
struct book *add_to_end(struct book *list);
void search(struct book *list);
void print_list(struct book *list);
void clear_list(struct book *list);

#endif

