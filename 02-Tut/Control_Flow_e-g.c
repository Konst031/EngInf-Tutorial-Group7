#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));      // Timer initialisieren -> außerhalb der While-Schleife, sonst entsteht immer die selbe Zahl

    int count = 0;
    int number = 0;
    int countHigher = 0;
      
    while (count < 100)
    {
        number = rand()%42;
        printf("%d\t",number);  
        
        if (number >= 21)
        {
            countHigher++;
            printf("Higher\n");
        }
        else{
            printf("Lower\n");
        }        
        count++;
    }
    printf("%d numbers were >=21", countHigher);

    return 0;

}
