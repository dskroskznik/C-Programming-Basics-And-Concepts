#include <stdio.h>
//prototype

double array_average(int arr[], int n);

int main()
{
	int a[5]={5, 8, 24, 68, 78};
	double average;
	average = array_average(a, 5); 
	printf("The average is : %lf", average);
	return 0;
}

double array_average(int *arr, int n)
{
	int i;
	int *p=arr; 
	
	int sum =0;
	double average;
	
        for(p=arr; p< arr+n;)
	//for(i = 0; i <n; i++)
	{	sum += *p++;
	
	}
	average = (double) sum/ n;
	return average;
}


