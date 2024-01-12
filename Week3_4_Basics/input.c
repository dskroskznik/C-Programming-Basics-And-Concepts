#include <stdio.h>

// input validation of a number for the range of 0 to 5
int main()
{
	int number;
	
	for(;;)
	{	
		printf("Please enter a number in the range of 0 to 5, inclusive:");	
		scanf("%d", &number);

		if(number <=5 && number >=0) //number is valid
			break;
		else
			continue;
	}

	
	return 0;
}
