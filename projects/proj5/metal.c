/* Dylan Skroskznik 	COP3514		10/17/21
 *  	This program that will calculate for how many 
 *  	metal bar cases are represented in string2 when
 *  	compared to string1, each letter is case sensitive.
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000 //global constant value

int count(char *s1, char *s2);		//count func declared
int read_line(char string[], int n);	//readline func declared

int main()
{
	char string1[MAX+1];	//char stringarray 1
	
	printf("Enter String 1: ");
	read_line(string1,MAX); //assigns char in each array element

	char string2[MAX+1];	//char stringarray 2

	printf("Enter String 2: ");
	read_line(string2,MAX); //assigns char in each array element

	int total = count(string1,string2);//assigns char duplicates to total
	printf("Output: ");	
	printf("%d\n",total);	//prints total value

	return 0;
}//end main

int count(char *s1, char *s2)
{
	char *p, *q;			//char pointer variables
	int count = 0;			//count initialized

	for(p=s1; *p!='\0'; p++) {	//loops through s1 until endline char 
	    for(q=s2; *q!='\0'; q++) {	//loops s2 till endline char
	   	if((*p!=' '&&*q!=' ')&&(*p==*q)) {
			count++;//increments count if *p==*q & *p&&*q != ' '
		}
	    }	
	}	

	return count;
 		
}//end count

int read_line(char *string, int n)
{
	int c;				//char variable
	int i = 0;			

	while((c = getchar()) != '\n') {//gathers char types into a string array
	    if(i < n) {
		*string++ = c;	
		i++;
	    }	
	}

	*string = '\0';

	return i;
}//end read_line
