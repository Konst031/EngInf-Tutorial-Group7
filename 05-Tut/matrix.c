#include <stdio.h>
#include <stdlib.h>

void printMatrix(int mat[10][10]);

int main(int argc, char const *argv[])
{
    int matrix[10][10] = {0};
    int counter = 1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = counter;
            counter++;
        }        
    }    

    printMatrix(matrix);

    return 0;
}


void printMatrix(int mat[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");        
    }    
}
