#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int read_line(char str[], int n);

int compare_strings(const void *p, const void *q);
int main()
{
    char input_buffer[1001];
    int length = 0;
//    char *sentence = NULL;
	
    char *sentences[50];    
    int i, num_sentences = 0;


    for(;;){

	printf ("Please type a sentence: ");
    	read_line(input_buffer, 1000);
    
       	length = strlen(input_buffer);

    	if(length == 0) break;

    	printf ("Allocating %d bytes to hold the sentence\n\n", length+1);

	sentences[num_sentences] = malloc(length+1);
   	if(sentences[num_sentences] == NULL){
		printf("malloc failed");
		return 1;
	}

  //  sentence[num_words] = input_buffer;		
    	strcpy (sentences[num_sentences], input_buffer);
   
    	num_sentences++;
	
	if(num_sentences==50) break;
	
    }

    qsort(sentences, num_sentences, sizeof(char *), compare_strings);
    for(i=0;i<num_sentences;i++) 
    	printf ("%s\n", sentences[i]);

   printf("deallocating memory");
    for(i=0; i<num_sentences;i++)
    	free(sentences[i]);

    return 0;
}
int read_line(char str[], int n)
{
  int ch, i = 0;
  
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

int compare_strings(const void *p, const void *q)
{
	return strcmp(*(char **)p, *(char **)q);
}

