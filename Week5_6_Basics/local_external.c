#include <stdio.h>

void print_one_row();
void print_all_rows();
//external variable

int main()
{
	print_all_rows();
	return 0;
}
void print_one_row(void)
{
	 int i;
	  for (i = 1; i <= 10; i++)
	    printf("*");
}
void print_all_rows(void)
{
	 int i;
	  for (i = 1; i <= 10; i++) {
	 // printf("i is %d\n", i);
	    print_one_row();
	 // printf("\ni is %d\n", i);
	    printf("\n");
	  }
}
