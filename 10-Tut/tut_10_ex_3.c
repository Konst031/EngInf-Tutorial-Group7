#include<stdlib.h>
#include<stdio.h>

// One possible strategy
// Alternatively, you can return a float** pointer to the new matrix and assign it in the main 
void transpose(float*** matrix, int r, int c);


int main(){
    int r = 3;
    int c = 10;
    float **matrix;

    // Allocate
    matrix = (float**) malloc(r*sizeof(float*));
    for(int i=0; i<r; i++){
        matrix[i] = (float*) malloc(c*sizeof(float));
    }

    // Fill and print (just a random formula, you can choose what you want or ask the user)
    printf("\nOriginal matrix:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            matrix[i][j] = (float) (i*c + j)/(r*c-1);
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // transpose, no copies made
    transpose(&matrix, r, c);

    // Print (now r and c have to be exchanged)
    printf("\nTransposed matrix:\n");
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    // Free
    for(int i=0; i<r; i++){
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}


void transpose(float*** point_matrix, int r, int c){
    // I create a new matrix that will transpose *matrix
    // note that the roles of c and r are inverted here
    float ** aux_matrix = (float**) calloc(c, sizeof(float*));
    for(int i=0; i<c; i++){
        aux_matrix[i] = (float*) calloc(r, sizeof(float));
    }

    // Fill aux_matrix as transpose of *matrix
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            // First, I dereference point_matrix
            // Then, I take the element (i,j) and invert the coordinates in aux_matrix
            aux_matrix[j][i] = (*point_matrix)[i][j];
        }
    }

    // now I have the transpose of *point_matrix in aux_matrix but I want to change the original matrix!
    // I free the old matrix and make the pointer "pointing" to the new transposed matrix
    for(int i=0; i<r; i++){
        free((*point_matrix)[i]);
    }
    free((*point_matrix));

    // Now point_matrix and aux_matrix point to the same portion of area!
    // the variable aux_matrix will be deleted at the end of the function, but *point_matrix will survive in the main!
    *point_matrix = aux_matrix;
    return;
}