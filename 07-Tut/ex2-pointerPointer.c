#include <stdio.h>
#include <stdlib.h>

void readPosIntSafe(int *);

int main(int argc, char const *argv[]) {
    int c = 0;
    int r = 0;
    // get size c and r from user; assume only positive input
    printf("Please enter the amount of columns:\t");
    scanf("%d", &c);
    fflush(stdin);
    printf("Please enter the amount of rows:\t");
    scanf("%d", &r);
    fflush(stdin);

    // allocate memory -> here as pointer to pointer (we are then able to use matrix[i][j]); no need to switch between
    // index and coordinates; coordinates directly applicable
    int **matrix = calloc(r, sizeof(int *)); // allocate memory for "outer array"
    for (int i = 0; i < c; i++) {
        matrix[i] = calloc(c, sizeof(int)); // allocate memory for each "subarray"
    }

    // let user specify every element; assume valid input
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Please enter the element at row %i and collumn %i:\t", i, j);
            scanf("%d", matrix[i]+j);
            fflush(stdin);
        }
    }

    // print matrix:
    printf("Matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free memory:
    for (int i = 0; i < c; i++) {
        free(matrix[i]);    // free subarrays
    }
    free(matrix);           // free outer array (not sufficient on its own)
}

void readPosIntSafe(int *num) {
    while (1) {
        int countReadValues = scanf("%d", num);
        fflush(stdin);
        if (*num > 0 && countReadValues > 0) {
            break;
        }
        printf("Invalid number, please try again:\t");
    }
}
