/* Dylan Skroskznik	cop3514		MAR. 21 2021
*  	This program will calculate the number of times that a Short Tandem Repeats(STRs) 
*  	or a sequence of DNA located in DNA strands provided by an accessed file
*/

#include <stdio.h>
#include <string.h>//string function library 
#define MAX_LEN 20000
int count_repeats(char *sequence, char *STR);//declare function name and parameter to count_repeats
int main()
{	//input arrays set to MAX_LEN for filename input,
	// main file information buffer and STR input buffer
	char fname[MAX_LEN];
	char fseq[MAX_LEN];
	char fSTR[MAX_LEN];
	FILE* pFile;//applies pointer to file accessed
	
	printf("Enter the file name for the DNA sequence: ");
       	 scanf("%18s",fname); //user inputs filename in 'fname' array

	pFile = fopen(fname, "r");//reads opened file from array

	//if file doesn't exist, or NULL, gives ERROR message
	if(pFile == NULL) {
		printf("ERROR OPENING FILE\n");
		return 1;
	}
	
	while(fgets(fseq,MAX_LEN+1,pFile)!=NULL) {
		//while file material gotten doesn't apply to NULL
		//file material is scanned into 'fseq' array
		fscanf(pFile, "%s", fseq);
	}	

	printf("Enter STR to search for: ");
	 scanf("%5s",fSTR);//user inputs STR information in 'fSTR' array
	
	int repeats=0;
	repeats = count_repeats(fseq, fSTR);//gives int variable repeats

	printf("STR '%s' repeats in DNA %d times\n", fSTR, repeats);//info message
	
	fclose(pFile); //closes file access
	return 0;
}//exit main

//integer function calculates a count of when a STR is encounter within the DNA sequence
int count_repeats(char *sequence, char *STR)
{
	int n=0;//initalize return variable
	char *p = sequence;//points to sequence array
	char *q = STR;//points to STR array
	//while sequence of the sequences position starting
	//from the STR is NOT NULL it will increment 'n' and
	//add the string length of STR array to original sequence
	while((p=strstr(p,q))!=NULL) {	
		n++;
		p+=strlen(q);		
		
	}
	
	return n;//returns repeats

}//exit function
