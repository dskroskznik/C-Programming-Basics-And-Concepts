#include <stdio.h>
#include <ctype.h>

// printable loop that outputs all printable characters within the ASCII table
int main()
{
	char c;
	for(c = ' ';c<='~';c++)
	{	
		
		printf("%d  %c \n",c,c);
		 
	}

	
	return 0;
}
