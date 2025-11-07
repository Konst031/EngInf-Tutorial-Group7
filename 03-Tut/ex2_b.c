#include <stdio.h>
#include <stdlib.h>

void my_flush(void);

int main(int argc, char const *argv[])
{
    char string[10] = {0};

    // get input
    printf("Please enter a number:\n");
    fgets(string,10,stdin);
    fflush(stdin);     // my_flush(); if fflush doesn't work

    long int num = atoi(string);
    printf("Your number was:\n%i",num);

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