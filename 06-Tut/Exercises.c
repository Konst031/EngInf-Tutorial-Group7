#include <stdio.h>
#include <stdlib.h>

struct student
{
    char name[50];
    int age;
    float grade;
};

void initializeStudent(struct student *stu, char name[50], int age, float grade);
int strLength(char str[]);
char *iterateString(char *string, void (*func)(char *element));
void shiftBy3(char *character);
void space2Underscore(char *character);

int main(int argc, char const *argv[]) {
    // a)
    int arr[10] = {0};
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(arr + i)); // use equivalence of arr[i] and *(arr+i)
    }
    printf("\n");

    // a) alternative
    int brr[10] = {0};
    int *p = brr;
    for (int i = 0; i < 10; i++, p++) {
        printf("%d ", *p); // use that usual pointer variable can be iterated through
    }
    printf("\n");

    // b)
    struct student stu1;
    initializeStudent(&stu1, "Lena", 20, 1.60);
    printf("Student: %s, age: %i, grade: %f\n", stu1.name, stu1.age, stu1.grade);

    // c)
    char string[] = {"Hello World!"};
    printf("The String: %s has %d characters\n", string, strLength(string));

    // d)
    char strChange1[] = {"This is a nice string!"};
    char strChange2[] = {"This is another string."};
    printf("Apply shiftBy3 to %s: ", strChange1);
    printf("%s\n", iterateString(strChange1, shiftBy3));
    printf("Apply space2Underscore to %s: ", strChange2);
    printf("%s\n", iterateString(strChange2, space2Underscore));

    return 0;
}
/**
 * @brief initializes a student with given values
 *
 * @param stu pointer to student to initialize
 * @param name name of student; String with max 49 characters
 * @param age age of student
 * @param grade average grade of student
 */
void initializeStudent(struct student *stu, char name[50], int age, float grade) {
    stu->age = age;     // using a struct student pointer, we can access the
    stu->grade = grade; // data of the struct directly in our function
    for (int i = 0; i < 49; i++) {
        if (name[i] == 0) {
            stu->name[i] = name[i];
            break;
        }

        stu->name[i] = name[i]; // remember the equivalence of *(stu).name and stu->name
    }
    stu->name[49] = 0;  // make sure that string is really null terminated
}

/**
 * @brief function that calculates the length of a NULL-terminated string
 * 
 * @param str string to calculate length for
 * @return int length of string
 */
int strLength(char str[]) {
    int counter = 0;
    while (*(str + counter) != 0) // check for NULL-Terminator in String
    {
        counter++;
    }

    return counter;
}

char *iterateString(char *string, void (*func)(char *element)) {
    int i = 0;
    while (string[i] != 0) {
        func(string + i);
        i++;
    }
    return string;
}

/**
 * @brief shift letters forward by three (ceasar cypher)
 * 
 * @param character one character to shift
 */
void shiftBy3(char *character) {
    if ((*character >= 'A' && *character < 'X') || (*character >= 'a' && *character < 'x')) {
        *character += 3;
    }
    else if ((*character >= 'X' && *character <= 'Z') || (*character >= 'x' && *character <= 'z')) {
        *character -= 23;
    }
}

/**
 * @brief change a space to an underscore 
 * 
 * @param character char to alter if it is a space
 */
void space2Underscore(char *character) {
    if (*character == ' ') {
        *character = '_';
    }
}