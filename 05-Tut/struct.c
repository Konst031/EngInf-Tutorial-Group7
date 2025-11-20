#include <stdlib.h>
#include <stdio.h>

struct student
{
    char name[50];
    int age;
    float grade;
}stu1;

void printStudent(struct student stu);

int main()
{

    stu1.age = 20;
    stu1.name[0] = 'L';
    stu1.name[1] = 'e';
    stu1.name[2] = 'o';
    stu1.name[3] = 0;
    stu1.grade = 2.43;

    struct student stu2 = {"Linda", 19, 1.76};
    printStudent(stu1);
    printStudent(stu2);
    

    return 0;
}

void printStudent(struct student stu)
{
    printf("Name: %s,\tage: %d,\tAverage Grade: %f\n",stu.name,stu.age,stu.grade);
}
