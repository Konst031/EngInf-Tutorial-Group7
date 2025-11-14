#include<stdio.h>
#include<stdlib.h>

void my_flush();
int is_palindrome(char string[128]);

int main()
{
    char buffer[128] = {0};
    printf("Please enter a string:\n");
    fgets(buffer,128,stdin);
    my_flush();

    if(is_palindrome(buffer))
        printf("\'%s\' is palindrome!\n", buffer);
    else
        printf("\'%s\' is NOT palindrome!\n", buffer);

    return 0;
}

void my_flush()
{
    char c;
    do{
        c = getchar();
    }while(c!= '\n' && c != EOF);
}

/**
 * @brief checks if string is a palindrome
 * 
 * @param string the string to check (max 127 characters)
 * @return 1 if string is palindrome else 0
 */
int is_palindrome(char string[128])
{
    int sizeOfString = 0;

    while(string[sizeOfString]!='\0') // determine size of String without NULL-Character
    {
        sizeOfString++;
        if(sizeOfString==128)
        {
            return 0; //missing NULL-Terminator -> no string, return false
        }
    }

    // Then, I check if the string is palindrome
    for(int i=0; i<sizeOfString/2; i++)
    {
        if(string[i]!=string[sizeOfString-1-i]) // as soon as 2 characters differ, I simply return false
        {
            return 0;   
        }                
    }
    return 1;
}