#include <stdio.h>

void fn();
int counter = 0;

int main()
{
    int i;
    printf ("Program storage starting\n");
    for (i = 0; i < 5; i++)
    {
        fn();
    }
    printf ("Normal termination\n");
	 return 0;
    
}
void fn()
{
    counter++;
    printf ("This function has been called %d times\n", counter);
}

