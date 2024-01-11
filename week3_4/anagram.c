#include <stdio.h>
#define N 26

int main()
{


	char ch;
	int letter_counts[N]= {0};
	int i;
	int count =0;
	
	printf("enter a word: ");

	while((ch=getchar())!= '\n')
		
	{
		letter_counts[ch - 'a']++;

	}

	for(i =0;i<N;i++)
		printf("%d", letter_counts[i]);

		
	printf("enter the second word: ");
	while((ch=getchar())!= '\n')
		
	{
		letter_counts[ch - 'a']--;

	}

	for(i =0;i<N;i++)
		printf("%d", letter_counts[i]);

	for(i =0;i<N;i++)
		if(letter_counts[i]==0)
			count++;


	if(count == N)
		printf("The words are anagrams.\n");
	else
	
		printf("The words are NOT anagrams.\n");
		
        	
	return 0;
}       
        	
        
        	
        	
        
