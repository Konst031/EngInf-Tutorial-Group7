#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int lotsofints[10] = {0};
    int copyArr[10] = {0};

    // array beschreieben
    for (int i = 0; i < 10; i++)
    {
        lotsofints[i] = i+1;
    }

    // array kopieren
    for (int i = 0; i < 10; i++)
    {
        copyArr[i] = lotsofints[i];
    }    

    // elemente des kopierten arrays ausgeben
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",copyArr[i]);
    }  

    return 0;
}
