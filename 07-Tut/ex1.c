#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n = 0;
    // get size n from user
    while (1) {
        printf("Please enter the size of the array:\t");
        int countReadValues = scanf("%d", &n); // scanf returns how many values were read, so for failure of scanf 0 is
                                               // returned (optional check, but even safer)
        fflush(stdin);
        if (n > 0 && countReadValues > 0) {
            break;
        }
        printf("\nInvalid number\n");
    }

    // allocate memory
    int *dynArray = calloc(n, sizeof(int));

    // let user specify every element
    int temp = 0;
    for (int i = 0; i < n; i++) {
        printf("Please enter the element at position %i:\t", i);
        int countReadValues = scanf("%d", &temp);
        fflush(stdin);
        if (countReadValues == 0) {
            // Try same iteration again
            i--;
            printf("Invalid input\n");
            continue;
        }
        dynArray[i] = temp;
    }

    // print array:
    printf("Array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynArray[i]);
    }

    // free memory:
    free(dynArray);
    return 0;
}
