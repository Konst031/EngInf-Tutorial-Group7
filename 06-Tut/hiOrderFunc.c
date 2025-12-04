#include <stdlib.h>
#include <stdio.h>

void iterateArray(int arr[50], void (*f)(int *num));
void add5(int *num);
void print(int *num);

int main(int argc, char const *argv[])
{
    int arr[50] = {0};
    iterateArray(arr,add5);
    iterateArray(arr,print);
    return 0;
}

void iterateArray(int arr[50], void (*f)(int *num))
{
    for (int i = 0; i < 50; i++)
    {
        f(arr+i);   // Pointer übergeben! nicht dereferentialisieren!
    }
    
}

void add5(int *num)
{
    *num += 5;
}

void print(int *num)
{
    printf("%d ",*num);
}