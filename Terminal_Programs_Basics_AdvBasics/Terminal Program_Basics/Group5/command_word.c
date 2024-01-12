/* Dylan Skroskznik			10/17/21
 *  	 This program prompts the user to enter a word input, 
 *  	 and then check validation off letter capitalizing 
 *  	 criteria dependent on the users command line inputs.
 */

#include <stdio.h>
#include <ctype.h>

int validate(char *word);//func validates correct syntax for commandline input

int main(int argc, char *argv[]) 	//cmnd argu length & cmnd argu array
{	
	int valid;			//int type declared as funcs value
	
	//if and only if argu contains the prog name, command, and input,...
	//will call func for validation and orduce a valid/invalid conclusion
	if(argc==2) {			
		valid=validate(argv[1]);
		if(valid!=0) {		//Boolean test for validation
		    printf("valid\n");
		}
		else printf("invalid\n");
	}			
	else printf("Incorrect amount of arguments. usage: './a.out [PASSWORD]'\n");
	return 0;
}//end main

int validate(char *word)
{
	int upper, lower, other; 	//ASCII types int declared variables
	char *p;			//char pointer variable
	
	for(p=word; *p!='\0'; p++) 	//search 'word' for condition declar
	{
		if((*p>='A')&&(*p<='Z')) {//CAPITAL LETTER set
			upper=1;
		}
		if((*p>='a')&&(*p<='z')) {//lower case letter set
			lower=1;
		}
		else {			//non-alphabetic ASCII sets
			other=1;
		}	
	}

	if(upper==0&&lower==1&&other==0) {
		return 1;
	}
	else if(upper==1&&lower==0&&other==0) {	
		return 1;
	}
	else {
		return 0;
	}
}//end validate
