#include <stdio.h>
#include <stdlib.h>

void printArrC(char arr[], int length);
void merge(char *target, char *sourceA, int lengthA, char *sourceB, int lengthB);
void mergesort(char arr[], int length);

int main(int argc, char const *argv[]) {
    char arr2[] = {'a', 'x', 'z', 'l', 'm', 'o', 'i', 'r'};
    int lengthArr2 = 8;
    printArrC(arr2, lengthArr2);
    mergesort(arr2, lengthArr2);
    printArrC(arr2, lengthArr2);

    return 0;
}

void mergesort(char arr[], int length) {
    if (length <= 1) {
        return;
    }
    char *temp_list = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        temp_list[i] = arr[i];
    }
    int length1 = length / 2;
    int length2 = length - length1;

    mergesort(temp_list, length1);
    mergesort(temp_list + length1, length2);
    merge(arr, temp_list, length1, temp_list + length1, length2);

    free(temp_list);
}

void merge(char *target, char *sourceA, int lengthA, char *sourceB, int lengthB) {
    /* Your code */
}

void printArrC(char arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}