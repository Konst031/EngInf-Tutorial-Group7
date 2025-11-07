#include <stdio.h>
#include <stdlib.h>
#include "ex1-sol.c"

void my_flush(void);


int main(int argc, char const *argv[])
{
    char input[10] = {0};
    int num = 0;

    // infinite loop
    while (1)
    {
        // get input
        printf("Please enter a number to check if prime or 'e' to exit:\n");
        fgets(input,10,stdin);
        fflush(stdin);     // my_flush(); if fflush doesn't work


        // check if input is break
        if(input[0] == 'e')
        {
            break;
        }

        num = atoi(input);

        // check for Prime
        if (isPrime(num))
        {
            printf("Your number %d is prime\n",num);
        }
        else
        {
            printf("Your number %d is not prime\n",num);
        }      
        
    }
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