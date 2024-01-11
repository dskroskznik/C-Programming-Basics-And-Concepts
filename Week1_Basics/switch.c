#include <stdio.h>

#define GRADE 4
int main(void)
{
	switch(GRADE) {
		case 5: printf("Excellent ");
		case 4: printf("Great ");
		case 3: printf("Average ");
		case 2: printf("Poor ");
		case 1: printf("Failing ");
		default: printf("Illegal Grade \n");
	}
	return 0;
}
