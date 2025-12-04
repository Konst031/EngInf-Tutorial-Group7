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

    // get type from user
    char type;
    size_t typeSize;
    while (1) {
        printf("Please enter the type of the array, 'i' for integer and 'c' for char:\t");
        type = getchar();
        fflush(stdin);
        if (type == 'c') {
            typeSize = sizeof(char);
            break;
        }
        if (type == 'i') {
            typeSize = sizeof(int);
            break;
        }

        printf("Invalid input\n");
    }

    // allocate memory
    void *dynArray = calloc(n, typeSize);
    // no new memory is allocated in the following. They are the same pointer just interpreted differently
    char *charArray = (char *)dynArray;
    int *intArray = (int *)dynArray;
    // See: the addresses are the same
    printf("Address charArray is pointing to: %p \t\nAddress intArray is pointing to: %p\n", charArray,intArray);

    // let user specify every element
    int temp = 0;
    int countReadValues = 1;
    for (int i = 0; i < n; i++) {
        printf("Please enter the element at position %i:\t", i);

        // read correct type from console
        if (type == 'i') {
            countReadValues = scanf("%d", &temp);
        }
        else {
            temp = getchar(); // getchar returns EOF if it didn't work
        }

        fflush(stdin);
        if (countReadValues == 0 || temp == EOF) {
            // Try same iteration again
            i--;
            printf("Invalid input\n");
            continue;
        }

        // write according to type
        if (type == 'i') {
            intArray[i] = temp;
        }
        else {
            charArray[i] = temp;
        }
    }

    // print array:
    printf("Array is:\n");
    for (int i = 0; i < n; i++) {
        if (type == 'c') {
            printf("%c ", *((char *)dynArray + i)); // could also just use charArray[i]
        }
        else {
            printf("%d ", *((int *)dynArray + i)); // could also just use intArray[i]
        }
    }

    // free memory:
    free(dynArray);
    return 0;
}
