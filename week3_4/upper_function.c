#include <stdio.h>
#include <ctype.h>

int main()
{

	char ch;
	char uch;	
	printf("Enter a message: ");
	ch = getchar();
	while(ch != '\n')
	{
		if(isalpha(ch))
		  uch = toupper(ch);
		else uch = ch;
		printf("%c", uch);
	
		ch = getchar();
	}
	printf("\n");
	return 0;
}
