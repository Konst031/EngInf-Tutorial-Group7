#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// exercise 6
int sumOfDigits(int number);
// exercise 7
unsigned int countDigits(unsigned int num);
// exercise 8
unsigned int pow_10(unsigned int exponent);
unsigned int reverseNum(unsigned int num, unsigned int numDigits);
// exercise 9
int isPalindrome(char str[], int start, int end);

int main(int argc, char const *argv[]) {
    // testing exercise 6
    int testNum = 13573;
    printf("The sum of digits of: %d is %d\n", testNum, sumOfDigits(testNum));

    // testing exercise 7
    unsigned int getDigits = 98763245;
    printf("%u has %u digits\n", getDigits, countDigits(getDigits));

    // testing exercise 8
    unsigned int revNum = 579302;
    unsigned int digits = countDigits(revNum);
    printf("%u has %u digits; reversed we get: %u\n", revNum, digits, reverseNum(revNum, digits));

    // testing exercise 9
    char testString[] = {"abdaba"};
    printf("%s is ", testString);

    // using strlen from library string.h simplifies functioncall (returns the length of a string without
    // NULL-Terminator)
    if (isPalindrome(testString, 0, strlen(testString) - 1)) {
        printf("a palindrome\n");
    }
    else {
        printf("not a palindrome\n");
    }

    // alternatively in one line using ternary operator (last tutorial)
    // printf("%s is %s", testString, isPalindrome(testString, 0, strlen(testString) - 1) ? "a palindrome\n" : "not a palindrome\n");

    return 0;
}

int sumOfDigits(int number) {
    if (number < 10) // for 1 digit numbers their sum of digits is equal to the number
    {
        return number;
    }
    return number % 10 + sumOfDigits(number / 10); // here we use the fact, that integer division cuts the remainder
}

unsigned int countDigits(unsigned int num) {
    if (num < 10) {
        return 1;
    }
    return 1 + countDigits(num / 10);
}

unsigned int pow_10(unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return 10 * pow_10(exponent - 1);
}

unsigned int reverseNum(unsigned int num, unsigned int numDigits) {
    if (numDigits <= 1) { // number has one digit
        return num;
    }
    unsigned int lastDigit = num % 10;
    return reverseNum(num / 10, numDigits - 1) + pow_10(numDigits-1) * lastDigit;
}

int isPalindrome(char str[], int start, int end) {
    if (str[start] == str[end]) {
        // finished checking if str is a palindrome, if start and end are either the same index (for string with odd
        // number of characters) or one apart (for strings with even number of characters)
        if (start == end || start + 1 == end) {
            return 1;
        }

        // further check, if the substring with one character stripped from each side is a Palindrome
        return isPalindrome(str, start + 1, end - 1);
    }

    return 0;
}