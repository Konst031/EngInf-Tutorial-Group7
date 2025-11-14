#include <stdio.h>
#include <stdlib.h>
int x = 5;

int main(int argc, char const *argv[])
{
    int lotsofints[10] = {0};
    // array wird beschrieben
    for (int i = 0; i < 10; i++)
    {
        lotsofints[i] = i+1;
    }
    // arrayinhalt wird ausgegeben
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",lotsofints[i]);
    }  

    // beides könnte auch ohne Probleme in einer for-Schleife gelöst werden

    return 0;
}
