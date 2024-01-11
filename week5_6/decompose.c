#include <stdio.h>

void decompose(double x, int *int_part, double *frac_part);

int main()
{
	double x;
	int integer_part;
        double fractional_part;
	printf("Enter a floating point number:");

	scanf("%lf", &x);

	decompose(x, &integer_part, &fractional_part);

	printf("The integer part is %d\n", integer_part);
	printf("The fractional part is %f\n", fractional_part);
	
	return 0;
}

//int * before int_part is declaring int_part as an int pointer 
void decompose(double x, int *int_part, double *frac_part)
{
	 *int_part = (int) x; //* is the indirection operator
	 *frac_part = x - *int_part;
}
