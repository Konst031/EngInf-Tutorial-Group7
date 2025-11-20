#include <stdlib.h>
#include <stdio.h>
#include "strLib.h"


int main(int argc, char const *argv[])
{
    char str1[128] = {"unicorn"};
    char str2[128] = {"university"};

    printf("\ncharInString-Test\n");
    int temp = charInString();
    printf("Output was: %d\n",temp);

    printf("\noverlap-Test\nThere are %d overlapping chars in \n%s\nand\n%s",overlap(str1,str2),str1,str2);

    return 0;
}

