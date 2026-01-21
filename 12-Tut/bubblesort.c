#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int length);
void printArr(int arr[], int length);

int main(int argc, char const *argv[]) {
    int arr[] = {1, 5, 0, -1, 13};
    int lengthArr = 5;
    printArr(arr, lengthArr);
    bubblesort(arr, lengthArr);
    printArr(arr, lengthArr);
    return 0;
}

void bubblesort(int arr[], int length) {
    /* Your code */
}

void printArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}