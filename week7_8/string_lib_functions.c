#include <stdio.h>
#include <string.h>

int main()
{
	char str1[10]="hello";
	char str2[10]="hello";
//        char *str3 = "hello"; //string literal 	
/*	if(str1== str2) 
		printf("str1 == str2 is true");
	else
		printf("str1 == str2 is NOT true");
*/
/*	if(strcmp(str1, str2)== 0) 
		printf("str1 and str2 contain the same set of characters\n");
*/
	char str3[10];

	strcpy(str3, str1);
	strcat(str3, " there");
	printf("str3 is :%s\n", str3);


	return 0;
}
