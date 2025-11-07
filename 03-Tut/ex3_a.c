#include <stdio.h>
#include <stdlib.h>
#include "ex1-sol.c"

void my_flush(void);

int main(int argc, char const *argv[])
{
    char input;
    // get input
    printf("Please enter a char:\n");
    input = getchar();

    // output like in exercise
    switchTest(input);
    return 0;
}

void my_flush(void)
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    
}