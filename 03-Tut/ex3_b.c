#include <stdio.h>
#include <stdlib.h>
#include "ex1-sol.c"

void my_flush(void);


int main(int argc, char const *argv[])
{
    char input1[10] = {0};
    char input2[10] = {0};
    int num1 = 0;
    int num2 = 0;

    // get input
    printf("Please enter the first number\n");
    fgets(input1,10,stdin);
    fflush(stdin);     // my_flush(); if fflush doesn't work
    
    printf("Please enter the second number\n");
    fgets(input2,10,stdin);
    fflush(stdin);     // my_flush(); if fflush doesn't work

    //convert input to int
    num1 = atoi(input1);
    num2 = atoi(input2);
    
    printPrimeBetween(num1,num2);

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