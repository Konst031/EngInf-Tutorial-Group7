#include <stdlib.h>
#include <stdio.h>

int main()
{
    for (int i = 1; i < 101; i++)
    {
        if (i%3 != 0 && i%5 != 0)
        {
            printf("%d\n",i);
            continue;
        }
        if (i%3 == 0)     // alternativ: !(i%3)
        {
            printf("Fizz");
        }
        if (i%5 == 0)     // alternativ: !(i%5)
        {
            printf("Buzz");
        }
        printf("\n");     
    }
    
    return 0;
}
