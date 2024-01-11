/* Dylan Skroskznik			OCT. 30 2021
 * 	This program checks a text file collected of email address,
 * 	and compile ever "usf.edu" addressed email into an output
 * 	file, assuming ever email address checked is vaild.
 */

#include <stdio.h> 
#include <string.h> //String based library func
#define LEN 2000 //MAX LEN assumed for file 

int is_USF_email(char *email); //declare an integer func for finding 'usf.edu' based emails
int main()
{
	char fname[100]; //input file name array
	char emails[LEN+1]; //email string arraylist
	char new_fname[100]; //new output file name array 
	FILE *rF; //FILE read func ptr
	FILE *wF; //FILE write func ptr		

	printf("Enter the file name to open: ");
	scanf("%s", fname); //scans in file name

	rF = fopen(fname, "r"); //opens input file
	if(fname==NULL) { //detects faults in file
		printf("Error opening file.\n");
		return 1;
	}
	
	//concatonate USF_ prefix to each new file
	strcpy(new_fname, "USF_"); 
	strcat(new_fname, fname);
		
	//creates and opens write file to store new strings
	wF = fopen(new_fname, "w");
	
	//not during file end & not when file error occurs
	while(!feof(rF)&&!ferror(wF)) 
	{
		//fgets the emails strings and reads by line
		while(fgets(emails,LEN+1,rF)!=NULL) {
			
			//when a usf email shows, stores string in new file
			if(is_USF_email(emails)) {
				
				fprintf(wF, "%s", emails);
			}
				
		}
 
	}
	
	//prints the concluding file name with usf email address list
	printf("Output file name is %s", new_fname);
	printf("\n");

	fclose(rF); //close readfile
	fclose(wF); //close writefile
	return 0;

}//end main

int is_USF_email(char *email)
{	
	char *a = "usf.edu"; //char string for usf address
	char *p = strstr(email, a); //str match across each email with *a

	if(p) {
		return 1;
	}
	else {
		return 0;
	}

}//end is_USF_email
