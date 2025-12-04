#include <stdio.h>

struct id
{
    int num;
    char name[10];
};

void printID(struct id id) {
    printf("age: %i, name: %s\n", id.num, id.name);
}

int main() {
    // initialize structs
    struct id id1 = {10, "Tom"};
    struct id id2 = {11, "Gabi"};

    printf("Print Structs:\n");
    printID(id1);
    printID(id2);

    printf("\nPrint Structs after id1 = id2:\n");
    id1 = id2;
    printID(id1);

    printf("\nChange first char of id1.name:\n");
    id1.name[0] = 'A';
    printID(id1);
    printID(id2);
}