#include <stdlib.h>
#include <stdio.h>

struct test
{
    int a;
    float b;
};

int main(int argc, char const *argv[])
{
    struct test var;
    struct test *ptr = &var;

    (*ptr).a = 5;   // nervig
    ptr->b = 3.4;   // schön, letztendlich aber exakt das selbe

    return 0;
}
