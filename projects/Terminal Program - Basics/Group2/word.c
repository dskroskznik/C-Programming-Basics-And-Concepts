/* Dylan Skroskznik			9/12/2021
 *  	 This program prompts the user to enter a word input, and then check validation 
 *  	 off letter capitalizing criteria dependent on the users input.
 */

#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;//variable for character type input
	int up=0, low=0, num=0, othr=0;//initializing character type inputs into integer values

	printf("Input: ");

	//standard do-while loop for scanning character inputs until a new-line command
	do {			
		ch = getchar();

		if(ch>='A'&&ch<='Z')
			++up;
		
 		else if(ch>='a'&&ch<='z') 
			++low; 
		
		else if(ch>=48&&ch<=57) 
			++num;	
	
		else if(!((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||(ch>=48&&ch<=57)))
			++othr;

	} while(ch != '\n');//do-while loop ends here

	//output procedure, if-else-if statements for validating the character input
	//based on the integer values condition
	othr-=1;
	printf("Output: ");
	if(up>=1&&low>=1) { //if uppercase and lowercase are included both
	  printf("INVALID\n"); 
	}
	else if(num>0) { //if number is included 
	  printf("INVALID\n");
	}
	else if(othr>0) { //if any other character is included
	  printf("INVALID\n");
	}
	else printf("VALID\n"); //applies only for uppercase or lowercase
		
	return 0;
}//end program
