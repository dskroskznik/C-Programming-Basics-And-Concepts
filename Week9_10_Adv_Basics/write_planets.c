#include <stdio.h>
#define MAX_LEN 1000

int main()
{
    FILE* pFile;

    char *planets[] = {"Mercury", "Venus", "Earth",
	                   "Mars", "Jupiter", "Saturn",
	                   "Uranus", "Neptune", "Pluto"};



    pFile = fopen("planets.txt", "w");

    if (pFile == NULL)
    {
        printf ("Error opening file\n");
        return 1;
    }

    int i;
    for(i = 0; i<9; i++)
    {
	fputs(planets[i], pFile);
	fputs("\n", pFile); 
    }

    fclose(pFile);
    printf ("File planets.txt written\n");
    return 0;
}

