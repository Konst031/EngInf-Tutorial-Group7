#include<stdlib.h>
#include<stdio.h>




// different strategies, all valid (the first one is the easiest)
float* allocate_1(int* n);
int allocate_2(float** array);
void allocate_3(float** array, int* n);

int main(){

    // *********** STRATEGY 1 ***********
    int n_1 = 0;
    float* array_1=0;

    // this strategy takes an int* as input and gives a float* as output
    array_1 = allocate_1(&n_1);
    
    // print it
    for(int i=0; i<n_1; i++){
        printf("Element %d: \t%f\n", i, array_1[i]);
    }



    // *********** STRATEGY 2 ***********
    int n_2 = 0;
    float* array_2=0;

    // this strategy takes a float** in input and gives an int as output
    n_2 = allocate_2(&array_2);
    
    // print it
    for(int i=0; i<n_2; i++){
        printf("Element %d: \t%f\n", i, array_2[i]);
    }



    // *********** STRATEGY 3 ***********
    int n_3 = 0;
    float* array_3=0;

    // this strategy takes a float** and int* in input and gives nothing as output
    allocate_3(&array_3, &n_3);
    
    // print it
    for(int i=0; i<n_3; i++){
        printf("Element %d: \t%f\n", i, array_3[i]);
    }

    // Free
    free(array_1);
    free(array_2);
    free(array_3);
    return 0;
}



// In the main I need to define an int and then pass its address here
float* allocate_1(int* n){
    // Note that, with this strategy, one has to declare the array pointer but not the size n (function input)
    float* array;
    
    // Ask the user for an integer, save it directly in n. 
    // Since we are working with a pointer this value will be available in the main as well!
    printf("\n*********** STRATEGY 1 ***********\n");
    printf("Give me an  integer:\n");
    scanf("%d", n);
    fflush(stdin);

    // allocate the array
    // note that I have to write (*n) instead of just (n) to dereference pointer
    array = (float*) calloc(*n, sizeof(float));

    // Fill the array
    for(int i=0; i<*n; i++){
        printf("Element %d:\n", i);
        scanf("%f", &array[i]);
        fflush(stdin);
    }

    // I return the pointer to the array
    return array;
}



// In the main I need to define an float pointer and pass ITS ADDRESS here
int allocate_2(float** array){
    // Note that, with this strategy, one has to declare the size n but not the array pointer (passed as input)
    int n;

    // Ask the user for an integer, save it in n. 
    printf("\n*********** STRATEGY 2 ***********\n");
    printf("Give me an  integer:\n");
    scanf("%d", &n);
    fflush(stdin);

    // allocate the array
    // Note that I have to dereference it!
    // Since we are working with a pointer to a pointer, the allocated vector will be available in the main as well!
    *array = (float*) calloc(n, sizeof(float));

    // Fill the array
    for(int i=0; i<n; i++){
        printf("Element %d:\n", i);
        float a;
        scanf("%f", &a);
        // first I dereference array, then I take it's i-th element
        (*array)[i] = a;
        fflush(stdin);
    }

    // I return the size
    return n;
}


// In the main I need to define an float pointer and an int and pass BOTH THEIR ADDRESSES here
void allocate_3(float** array, int* n){
    // Note that, with this strategy, one has to declare nothing here.

    // Ask the user for an integer, save it in n. 
    // Since we are working with a pointer this value will be available in the main as well!
    printf("\n*********** STRATEGY 3 ***********\n");
    printf("Give me an  integer:\n");
    scanf("%d", n);
    fflush(stdin);

    // allocate the array
    // Note that I have to dereference both the array and n!
    // Since we are working with a pointer to a pointer, the allocated vector will be available in the main as well!
    *array = (float*) calloc(*n, sizeof(float));

    // Fill the array
    for(int i=0; i<*n; i++){
        printf("Element %d:\n", i);
        float a;
        scanf("%f", &a);
        // first I dereference array, then I take it's i-th element
        (*array)[i] = a;
        fflush(stdin);
    }

    // I return nothing
    return;
}