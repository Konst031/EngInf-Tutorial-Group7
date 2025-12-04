#include <stdio.h>
#include <stdlib.h>

void readPosIntSafe(int *);
int *indexToCoords(int rows, int cols, int index);
int coordsToIndex(int rows, int cols, int* coords);

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

    // allocate memory
    int *matrix = calloc(r*c, sizeof(int));

    // let user specify every element
    for (int i = 0; i < c * r; i++) {
        printf("Please enter the element at index %i:\t", i);
        scanf("%d", matrix+i);
        fflush(stdin);
    }

    // print matrix:
    printf("Matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i * c + j]);
        }
        printf("\n");
    }

    // free memory:
    free(matrix);

    // Test additional functions
    int cTest = 4;
    int rTest = 2;
    int coords[2] = {1,3};
    printf("CoordsToIndex for (%d, %d) with r = %d, c = %d returns: %d\n", coords[0],coords[1], rTest,cTest,coordsToIndex(rTest,cTest,coords));
    int index = 10;
    int * testCoords = indexToCoords(rTest, cTest, index);
    printf("IndexToCoords for %d with c = %d, r = %d returns: (%d, %d)\n", index, cTest,rTest,testCoords[0], testCoords[1]);
    free(testCoords);
    return 0;
}

int *indexToCoords(int rows, int cols, int index) {
    int * coords = malloc(2*sizeof(int));
    if (rows * cols < index + 1) {
        printf("Index out of bounds\n");
        coords[0] = -1;
        coords[1] = -1;
        return coords;
    }
    coords[0] = index / cols;
    coords[1] = index % cols;
    return coords;
}

int coordsToIndex(int rows, int cols, int *coords) {
    int index = coords[0] * cols + coords[1];
    if (rows * cols < index + 1) {
        printf("Index out of bounds\n");
        return -1;
    }
    return index;
}
