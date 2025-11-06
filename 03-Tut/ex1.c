#include <stdio.h>
#include <stdlib.h>


void switchTest(char letter);
int isPrime(int val);
void printPrimeBetween(int a, int b);


int main()
{
    // change values used for tests here
    char letterToTest = 'a';
    int numCheckPrime = 17;
    int num1PrimeBetween = 17;
    int num2PrimeBetween = 1;

    // test functions
    switchTest(letterToTest);
    printf("Output of isPrime(%d): %d\n", numCheckPrime, isPrime(numCheckPrime));
    printPrimeBetween(num1PrimeBetween,num2PrimeBetween);

    return 0;
}

void switchTest(char letter) {
    /* code */
}

/**
 * @brief function that checks if number is prime
 * 
 * @param val integer that is checked for being prime
 * @return 1 when prime, 0 else
 */
int isPrime(int val){
    /* code */
}

/**
 * @brief prints all prime numbers between given numbers (excluding them)
 * 
 * @param a number 1
 * @param b number 2
 */
void printPrimeBetween(int a, int b){
    /* code */
}