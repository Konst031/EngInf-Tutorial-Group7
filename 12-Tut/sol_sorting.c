#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int length);
void printArr(int arr[], int length);
void printArrC(char arr[], int length);
void merge(char *target, char *sourceA, int lengthA, char *sourceB, int lengthB);
void mergesort(char arr[], int length);

int main(int argc, char const *argv[]) {
    int arr[] = {1, 5, 0, -1, 13};
    int lengthArr = 5;
    printf("Array before bubblesort: \t");
    printArr(arr, lengthArr);
    bubblesort(arr, lengthArr);
    printf("Array after bubblesort:  \t");
    printArr(arr, lengthArr);

    char arr2[] = {'a', 'x', 'z', 'l', 'm', 'o', 'i', 'r'};
    int lengthArr2 = 8;
    printf("Array before mergesort: \t");
    printArrC(arr2, lengthArr2);
    mergesort(arr2, lengthArr2);
    printf("Array after mergesort:  \t");
    printArrC(arr2, lengthArr2);

    return 0;
}

void bubblesort(int arr[], int length) {
    int swaps;
    do {
        swaps = 0;
        for (int i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swaps++;
            }
        }
        length--;
    } while (swaps > 0);
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
    if (lengthA == 0 && lengthB == 0) {
        return;
    }
    int idxA = 0;
    int idxB = 0;
    while (idxA + idxB < lengthA + lengthB) {
        // source B is empty
        if (idxB == lengthB) {
            target[idxA + idxB] = sourceA[idxA];
            idxA++;
        }
        // source A is empty
        else if (idxA == lengthA) {
            target[idxA + idxB] = sourceB[idxB];
            idxB++;
        }
        // current element in sourceA smaller/equal than current element in sourceB
        else if (sourceA[idxA] <= sourceB[idxB]) {
            target[idxA + idxB] = sourceA[idxA];
            idxA++;
        }
        // current element in source A largen than current element in sourceB
        else {
            target[idxA + idxB] = sourceB[idxB];
            idxB++;
        }
    }
}

void printArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printArrC(char arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}