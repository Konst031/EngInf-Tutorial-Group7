#include <stdlib.h>
#include <stdio.h>

void my_flush(void)
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
    
}

int main()
{
    char string[5] = {0};
    int num = 0;
    
    printf("Gib eine Zahl an:\n");
    fgets(string,5,stdin); // liest User-Input

    printf("Gib nocheine Zahl an:\n");
    fgets(string,5,stdin); // liest nochmal User Input in selbe Variable

    num = atoi(string);
    printf("\n%i",num);
    return 0;
}

