/* Dylan Skroskznik 			APR. 4 2021
 *	This program will support in managing the registrations and attendence list for the 
 *	summer camp using structured functions with linked list to order each person by name, age, email.
 * THIS FILE HOLDS THE NECESSARY FUNCTIONS FOR THE MAIN FUNCTION IN ORDER FOR THIS PROGRAM TO WORK PROPERLY
 * */

//FUNCTIONS:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"
#define EMAIL_LEN 100 
#define NAME_LEN 30
#define STATUS_LEN 30

//append_to_list: allocates the size of the request structure and 
//		  ask user to register information to the request list,
// 		  if information has already been implemented, we return
// 		  to the operation code input process for a different option.
struct request *append_to_list(struct request *list)
{
	struct request *new_reg = malloc(sizeof(struct request));
	struct request *cur, *prev;
	
	if (new_reg == NULL) { 
		printf("\n Registration request failed. ");
		return list;
	}
 
	printf("\nPlease enter your following information: \n");
	printf("\nLAST Name: ");
	read_line(new_reg->last, NAME_LEN);//reads line input for lastname
	printf("\nFIRST Name: ");
	read_line(new_reg->first, NAME_LEN);//reads line input for firstname
	printf("\nEMAIL Address: ");
	read_line(new_reg->email, EMAIL_LEN);//reads line input for email

	//for loop for comparing if information already exists
	for(cur=list, prev=NULL;cur!=NULL && strcmp(new_reg->last,cur->last)>0;prev=cur, cur=cur->next) 
		;

	if(cur!=NULL && strcmp(new_reg->last,cur->last)==0 && (new_reg->first==cur->first)) {
		for(cur=cur, prev=prev;cur!=NULL && strcmp(cur->first,new_reg->first)>0 && 
				strcmp(cur->last,new_reg->last)>=0;prev=cur, cur=cur->next)
				;			
	}

	if(cur!=NULL && strcmp(new_reg->first,cur->first)==0 && strcmp(new_reg->last, cur->last)==0) {
		printf("This information already exists in the registration list.\n");
			free(new_reg);
			return list;		
	}

	printf("\nNOW,\nEnter Your Age: ");
	scanf("%d", &new_reg->age); //continues registration with age input
	strcpy(new_reg->status, "pending");//updates registration status to a pending request
	
	//linked-list organizing
	new_reg->next = cur;//caps off linked-list with NULL next
	if(prev==NULL) {
		return new_reg;//returns the request struct if list is NULL
	}
	else {
		prev->next = new_reg;//and assigns next postition to the latest registration made
		return list;
	}
}//end append_to_list

struct request *delete_from_list(struct request *list)
{
	struct request *delete = malloc(sizeof(struct request));
	struct request *cur, *prev; 	

	printf("\nPlease enter your following information: \n");
	printf("\nLAST Name: ");
	read_line(delete->last, NAME_LEN);//reads line input for lastname
	printf("\nFIRST Name: ");	
	read_line(delete->first, NAME_LEN);//reads line input for firstname
	printf("\nEMAIL Address: ");
	read_line(delete->email, EMAIL_LEN);//reads line input for email	
	
	for(cur=list, prev=NULL; cur!=NULL && !((strcmp(cur->last,delete->last)==0)&&(strcmp(cur->first,delete->first)==0)
			&&(strcmp(cur->email,delete->email)==0)); prev=cur, cur=cur->next)
	;  
	
	   if(cur==NULL) {	
	   	printf("Information is not found within list.\n");
		return list;
	   }
	   if(prev==NULL) {
	   	printf("Information updated.\n");
	   	list=list->next;
	   }
	   else {
	   	printf("Information updated.\n");
	   	prev->next=cur->next;
	   }

	free(cur);
	return list;
}

//update: calls the request list for an updating process, this will determine
//	  if an existing member will update their registration status after
//	  it has become pending. Though, if no one exists, this will send them
//	  back to register or select a different operation code.
void update(struct request *list)
{	
	struct request *update = malloc(sizeof(struct request));
	struct request *u;		
	char new_status;
		
	printf("\nPlease enter your following information: \n");
	printf("\nLAST Name: ");
	read_line(update->last, NAME_LEN);//reads line input for lastname
	printf("\nFIRST Name: ");
	read_line(update->first, NAME_LEN);//reads line input for firstname
	printf("\nEMAIL Address: ");
	read_line(update->email, EMAIL_LEN);//reads line input for email

	//iteration loop to detect an inexistent registration request found while in this operation
	for(u=list;u!=NULL;u=u->next) {
		if(strcmp(u->last,update->last)||strcmp(u->first,update->first)
		   ||strcmp(u->email,update->email)) {
			printf("This information can not be located in the registration list.\n"
				"Maker sure you put the information accurately or exit back and type 'a'" 
				"and be appended to the list.");	
			return;					
		}	

	}
	u = list;
	//proceeds through operation to allow user to update status
	printf("\nNOW,\n Update your request with a status(\"approved\",\"declined\", or \"waiting\"): \n");
	scanf("%30s", &new_status);//reads input for a new status and updates to main list 
	if(strcmp(&new_status,"approved")) strcpy(u->status, &new_status);
	if(strcmp(&new_status,"declined")) strcpy(u->status, &new_status);
	if(strcmp(&new_status,"waiting")) strcpy(u->status, &new_status);

}

//print_list: prints the request registration list throughout each
//	      operation enacted by the users own evaluations
void print_list(struct request *list)
{
	struct request *pl;
	//for loop to output each value printed until it reaches a NULL index
	printf("\n-=================================================================================-\n");	
	for(pl=list;pl!=NULL;pl=pl->next) {
		printf(">> %7s, \t%7s, \t%15s, \t%5d, \t%5s\n", pl->last, pl->first, pl->email , pl->age , pl->status);
	} 
	printf("\n-=================================================================================-\n");

}//end print_list

//clear_list: a function that releases memory occupied by the structure nodes 
//            within the linked-list as the termination of the program
//            is in effect.0
void clear_list(struct request *list)
{
	struct request *cl;
	
	//
	while(list != NULL) {
		cl = list;
		list = list->next;
		if(cl != NULL) {
		  free(cl);
		}
	}
 
}//end clear_list

