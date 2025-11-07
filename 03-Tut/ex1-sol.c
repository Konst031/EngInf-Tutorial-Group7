#include <stdio.h>
#include <stdlib.h>


void switchTest(char letter);
int isPrime(int val);
void printPrimeBetween(int a, int b);


int main()
{
    // values used for tests
    char letterToTest = 'a';
    int numCheckPrime = 12;
    int num1PrimeBetween = 17;
    int num2PrimeBetween = 1;

    // test functions
    switchTest(letterToTest);
    printf("Output of check Prime with %d: %d\n", numCheckPrime, isPrime(numCheckPrime));
    printPrimeBetween(num1PrimeBetween,num2PrimeBetween);

    return 0;
}

void switchTest(char letter) {
    switch (letter)
    {
    case 'a':
    case 'A':
        printf("A for apple\n");
        break;
    case 'b':
    case 'B':
        printf("B for bear\n");
        break;
    case 'c':
    case 'C':
        printf("C for cat\n");
        break;
    default:
        printf("Now I know my alphabet\n");
        break;
    }
}

/**
 * @brief function that checks if number is prime
 * 
 * @param val integer that is checked for being prime
 * @return 1 when prime, 0 else
 */
int isPrime(int val){
    for (int j = 2; j < val; j++)
    {
        if (val%j == 0)
        {
            // divisor found -> number not prime
            return 0;
        }        
    }
    // number prime
    return 1;
}

/**
 * @brief prints all prime numbers between given numbers (excluding them)
 * 
 * @param a number 1
 * @param b number 2
 */
void printPrimeBetween(int a, int b){
    // make sure a is smaller than b
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    // print primes
    printf("All primes between %d and %d are: \n",a, b);
    for(int i = a+1; i < b; i++)
    {
        if (isPrime(i))
        {
            printf("%d ",i);
        }         
    }
}
