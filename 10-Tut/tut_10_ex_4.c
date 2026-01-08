#include<stdlib.h>
#include<stdio.h>


float* re_allocate(float* array, int n, int n_new);


int main(){
    int n, n_new;
    float* array=0;

    // ask the size to the user
    printf("Give me the size of the array:\n");
    scanf("%d", &n);
    fflush(stdin);

    // allocate and fill it however you want
    array = (float*) malloc(10*sizeof(float));
    for(int i=0; i<n; i++){
        array[i] = 3*i/2.;
    }

    // Print the array
    for(int i=0; i<n; i++){
        printf("%f\n",array[i]);
    }
    
    // ask the *new* size to the user
    printf("Give me the new size of the array:\n");
    scanf("%d", &n_new);
    fflush(stdin);

    // I save the pointer to the new resized vector in the same float*.
    // ACHTUNG: if I didn't free array in the function re_allocate I couldn't do it anymore here because the address value of array has changed!
    array = re_allocate(array, n, n_new);

    // Print the new array
    for(int i=0; i<n_new; i++){
        printf("%f\n",array[i]);
    }

    free(array);
    return 0;
}


float* re_allocate(float* array, int n, int n_new){
    // Allocate a new array of size n_new
    // I use calloc so that every element gets initialized to 0!
    float* array_new = (float*) calloc(n_new, sizeof(float));

    // If n<n_new, the last elements will simply stay 0
    // If n>n_new, I only copy until I get to n_new and the last terms will be lost
    for(int i=0; i<n && i<n_new; i++){
        array_new[i] = array[i];
    }

    // I decide to free array here, but different choices can be made
    // If you think you will need "array" again in the main function don't do it!
    free(array);

    // I return to main the pointer to the new vector
    return(array_new);
}