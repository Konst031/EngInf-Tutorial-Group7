#include <stdlib.h>
#include <stdio.h>

void add5arr(int numbers[5]);
void add5int(int number);

int main()
{
    int arr[5] = {1,4,2345,45,987};
    int num = 324;
    printf("Vorher:\nArray:\t");

    for (int i = 0; i < 5; i++)
    {
        printf("%d, ",arr[i]);
    }

    printf("\nint:\t%d\n",num);
    
    add5arr(arr);
    add5int(num);

    printf("Nachher:\nArray:\t");

    for (int i = 0; i < 5; i++)
    {
        printf("%d, ",arr[i]);
    }

    printf("\nint:\t%d\n",num);
    
    return 0;
}

void add5arr(int numbers[5])
{
    for (int i = 0; i < 5; i++)
    {
        numbers[i] += 5;
    }    
}

void add5int(int number)
{
    number += 5;
}