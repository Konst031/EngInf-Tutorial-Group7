#include <stdlib.h>
#include <stdio.h>



int main(int argc, char const *argv[])
{
    char arr[100] = {0};
    char *string = arr;
    char var = 'a';

    // äquivalent:
    arr[50] = 15;
    *(arr + 50) = 15;
    *(string + 50) = 15;

    // unterschiedlich:
    arr = &var;     // Fehler! arr ist const -> compile Error (zeigt IDE wahrscheinlich selbst an)
    string = &var;  // Möglich -> string zeigt jetzt auf var

    return 0;
}
