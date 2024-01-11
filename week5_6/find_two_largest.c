#include <stdio.h>
#define N 10

void find_two_largest(int arr[], int n, int *largest, int *second_largest);

//find the largest and the second largest value in an array

int main()
{
	int i, max, second_max;
	int a[N];

	printf("Enter %d elements for the arary: ", N);
	for(i=0;i<N;i++)
		scanf("%d", &a[i]);		

	find_two_largest(a, N, &max, &second_max);
	printf("the largest value is: %d and the second largest is: %d\n", max, second_max);

	return 0;

}

void find_two_largest(int arr[], int n, int *largest, int *second_largest)
{
	int i;
        int max, max2;
	
	//initialize max and max2
	
	if(arr[0]>arr[1])
        {
                max=arr[0];
                max2=arr[1];
        }else{
                max = arr[1];
                max2 = arr[0];
        }

        for(i = 2;i< n; i++)
        {
                if(arr[i]>max)
                  {
                        max2 = max;
                        max = arr[i];
                }
                else if(arr[i]>max2)
                        max2= arr[i];

       }

	*largest = max;
	*second_largest = max2;
}

