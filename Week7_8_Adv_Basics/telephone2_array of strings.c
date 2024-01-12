#include <stdio.h>
#include <string.h>
#define NUM_TEL 50
#define TEL_LEN 15
#define AREA_LEN 4
int readline(char *str, int n);
void extract (char phone_numbers[][TEL_LEN], int n, char area[][AREA_LEN]); 
int main()
{
	char tels[NUM_TEL][TEL_LEN];
	char area_codes[NUM_TEL][AREA_LEN];
	int i, len, count =0;

	printf("Please enter the phone numbers in (xxx)xxx-xxxx form, press enter key when you are done:");
	for(;;){
		read_line(tels[count], TEL_LEN);
		len = strlen(tels[count]);
		if(len==0) break;
		else count++;
		printf("Enter the next phone number:");
	}

	extract(tels, count, area_codes);

	printf("Printing area code:\n");
	for(i=0;i<count;i++)
		printf("%s\t", area_codes[i]);
	printf("\n");
	return 0;
}

	
void extract (char phone_numbers[][TEL_LEN], int n, char area[][AREA_LEN])
{
	char *pch;
	int i;
   	for(i=0;i<n;i++)
	{
		pch = strtok(phone_numbers[i], "()-");
		strcpy(area[i],pch);

	}


}

int read_line(char *str, int n)
{
          int ch; int i = 0;

          while ((ch = getchar()) != '\n')
          {  if (i < n)
             { *str++= ch;
	      i++;
             }
	  }
          *str = '\0';   /* terminates string */
          return i;        /* number of characters stored */
}


