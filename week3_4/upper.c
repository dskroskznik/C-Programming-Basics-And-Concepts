#include <stdio.h>


int main()
{

	char ch;
	char uch;	
	printf("Enter a message: ");
	
	printf("Output: ");
	do {
		ch = getchar();
		if(ch>='a' && ch<='z')
			uch = ch -'a'+'A';
		else uch = ch;
			printf(" %c", uch);
	
		
	} while(ch != '\n');
			
	printf(" `\n");
	return 0;
}
