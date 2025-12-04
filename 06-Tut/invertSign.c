#include <stdio.h>
void invertSign (float*);
int main() {
    float num = 5.0;
    invertSign(&num); 
    printf("Float after inverting: %f", num);
    return 0;
}

void invertSign(float *num) {
    *num *= -1;
}
