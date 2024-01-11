/* Dylan Skroskznik 	cop3514		APR. 4 2021
 *	This program will support in managing the registrations and attendence list for the 
 *	summer camp using structured functions with linked list to order each person by name, age, email.
 *
 * */
//include C program function libraries & define constants
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100 
#define NAME_LEN 30
#define STATUS_LEN 30

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
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
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
}

//append_to_list: allocates the size of the request structure and 
//		  ask user to register information to the request list,
// 		  if information has already been implemented, we return
// 		  to the operation code input process for a different option.
struct request *append_to_list(struct request *list)
{
	struct request *new_reg = malloc(sizeof(struct request));
	struct request *a;
	
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

	for(a=list;a!=NULL;a=a->next) {//for loop for comparing if information already exists
		if(!strcmp(a->first, new_reg->first)&&(!strcmp(a->last, new_reg->last))
		   &&!strcmp(a->email, new_reg->email)) {
			printf("This information already exists in the registration.\n"
				"If you have new information avaliable, input 'u' to input"
				"your new information.\n");	
			return list;//returns back list information
		}	
	}

	printf("\nNOW,\nEnter Your Age: ");
	scanf("%d", &new_reg->age); //continues registration with age input
	strcpy(new_reg->status, "pending");//updates registration status to a pending request
	
	//linked-list organizing
	new_reg->next = NULL;//caps off linked-list with NULL next
	if(list==NULL) {
		return new_reg;//returns the request struct if list is NULL
	}

	a = list;
	while(a->next!=NULL) {
		a = a->next;//while the next iteration is NOT NULL, 'a' becomes the next in the linked-list
	}
	
	a->next = new_reg;//and assigns next postition to the latest registration made
	return list;

}//end append_to_list

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
}
