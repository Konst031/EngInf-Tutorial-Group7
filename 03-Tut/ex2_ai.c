#include <stdio.h>
#include <stdlib.h>

void my_flush(void);



int main(int argc, char const *argv[])
{
    char string[50] = {0};

    // get input
    printf("Please enter a string:\n");
    fgets(string,50,stdin);
    fflush(stdin);     // my_flush(); if fflush doesn't work

    printf("Your string was:\n%s",string);

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