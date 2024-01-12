#include <stdio.h>
#include <string.h>
#define TEL_LEN 15
int read_line(char *str, int n);
int main()
{
	char tels[TEL_LEN];
	int len;
	char *pch;

	printf("Please enter the phone numbers in (xxx)xxx-xxxx form, press enter key when you are done:\n");
	for(;;)	
	{
		read_line(tels, TEL_LEN);
		len = strlen(tels);
		if(len==0) {
			break; }
		pch = strtok(tels, "-()");	
		/* (555)987-6543
 		*  555
 		*  987
 		*  6543*/
		printf("Area code: %s ", pch);
		printf("Phone number: ");
		while (pch != NULL) {
			pch = strtok(NULL, "-()");
			if (pch != NULL) {
				printf("%s", pch);
				}
			
		}
	}
	

	return 0;
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


