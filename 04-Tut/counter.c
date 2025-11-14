#include <stdio.h>

// need to compile without -Werror as the variable in the next line is never used
// and thus leads to a warning (warning will still be printed to console, but compilation is done anyways)
static int counter = 0;

void testStatic(int counter2){
    static int counter = 10;
    printf("Counter is: %i\n", counter--);
    printf("The argument is: %i\n", counter2);
}

int main(int argc, char const *argv[])
{
    int counter = 0;

    for (counter = 0; counter < 10; ++counter)
    {
        static int counter = 10;
        testStatic(counter);
        ++counter;
    }
    
    return 0;
}
