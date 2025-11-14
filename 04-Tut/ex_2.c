#include <stdlib.h>
#include <stdio.h>

int xor(int bool1, int bool2);
float mean(float numbers[10]);
int charInString();
int overlap(char string1[128], char string2[128]);
void my_flush(void);

int main(int argc, char const *argv[])
{
    int bool1 = 0;
    int bool2 = 1;
    float floatArr[10] = {23.34,432.1,4.2,1.0,5.8,6.6,7.3,8.234,1.5,-17};
    char str1[128] = {"unicorn"};
    char str2[128] = {"university"};

    printf("XOR-Test\n %d XOR %d is %d\n",bool1,bool2,xor(bool1,bool2));

    printf("\nmean-Test\n");
    printf("The computed mean value is: %f",mean(floatArr));

    printf("\ncharInString-Test\n");
    int temp = charInString();
    printf("Output was: %d\n",temp);

    printf("\noverlap-Test\nThere are %d overlapping chars in \n%s\nand\n%s",overlap(str1,str2),str1,str2);

    return 0;
}


/**
 * @brief returns xor of two boolean values
 * 
 * @param bool1 first boolean
 * @param bool2 second boolean
 * @return 1 if xor is true else 0
 */
int xor(int bool1, int bool2)
{
    return (bool1 || bool2) && !(bool1 && bool2); // auch andere Varianten möglich xor zu beschreiben
}

/**
 * @brief computes mean value of array
 * 
 * @param numbers array of 10 floats where mean value is computed
 * @return mean value of array
 */
float mean(float numbers[10])
{
    float sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += numbers[i];
    }

    return sum/10;
}

/**
 * @brief asks user for string and char and checks if char is in given string
 * 
 * @return 1 if char is in string, else 0
 */
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

/**
 * @brief counts the number of overlapping characters between two strings
 * 
 * @param string1 string with max 127 character
 * @param string2 string with max 127 character
 * @return int: count of overlapping characters
 */
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