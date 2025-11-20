#include <stdlib.h>
#include <stdio.h>
#include "strLib.h"



int charInString()
{
    char testChar = 0;
    char string[100] = {0};
    int counter = 0;

    printf("Please enter a string:\n");
    fgets(string,100,stdin);
    my_flush();

    printf("Please enter a char to check if it is part of the String:\n");
    testChar = getchar();

    while (string[counter] != 0) // iterate over the string -> stop at NULL-Terminator
    {
        if (string[counter] == testChar) //return true (1) if char is found in string
        {
            return 1;
        }
        counter++;
    }

    return 0;    
}

int overlap(char string1[128], char string2[128])
{
    int overlap = 0;
    int counter = 0;

    while (string1[counter] != 0 && string2[counter] != 0) // iterate through strings until first NULL-Terminator
    {
        if (string1[counter] == string2[counter])
        {
            overlap++;
        }
        counter++;

        if (counter == 128) // If there is no NULL-Terminator in both strings -> return 0
        {
            return 0;
        }
        
    }

    return overlap; 
}

void my_flush(void)
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    
}