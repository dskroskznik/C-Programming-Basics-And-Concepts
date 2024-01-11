#include <stdio.h>

int main(){

	int number, i;

	int count = 0;

	int is_prime;

        int is_palindrome;

        printf("First 100 palindromic prime numbers:\n ");
	for(number = 2; count<100; number++){
		//test if number is prime
		is_prime = 1;
		is_palindrome = 0;
		for(i=2;i<number;i++){
			if(number%i == 0){
				is_prime = 0;
                       		break;
			}
		}
		//test if number is a palindrome
		int n =number, remainder, reverse = 0;
		while(n != 0){
			remainder = n%10;
			reverse = reverse*10 + remainder;
			n = n/10;
		}
		
		if(reverse == number){
			is_palindrome = 1;
		}

		if(is_prime && is_palindrome){
			printf("%d ", number);
			count++;
		}
	}

	printf("\n");
	return 0;
}	
		
