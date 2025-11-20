#include <stdio.h>

int main()
{
    char a = 56;
    unsigned char b = 119;
    unsigned char c = 4;
    char d = -80;

    a = (11 * c) + 13;
    b += d + 10;
    c -= 2* (a + 15);
    d *= 2;

    printf("a: %c, b: %c, c: %c, d: %d \n", a,b,c,d);
    
    return 0;
}
