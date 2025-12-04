#include <stdio.h>
#include <stdlib.h>

struct id
{
    int num;
    char *name;
};
void setString(char *string, char *array, int length);
void printID(struct id id);

int main() {
    struct id id1;
    struct id id2;
    id1.name = malloc(sizeof(struct id) * 10);
    id2.name = calloc(10, sizeof(struct id));
    // initialize the structs
    setString("Tom", id1.name, 10);
    setString("Tina", id2.name, 10);
    id1.num = 10;
    id2.num = 20;

    // print structs
    printf("Print Structs:\n");
    printID(id1);
    printID(id2);

    printf("\nPrint Structs after id1 = id2:\n");
    id1 = id2;
    printID(id1);
    printID(id2);
    printf("\nChange first char of id1.name:\n");
    id1.name[0] = 'A';
    printID(id1);
    printID(id2);
    printf("\nChange id1.num:\n");
    id1.num = 100;
    printID(id1);
    printID(id2);
}

void setString(char *string, char *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        if (string[i] == 0) {
            array[i] = 0;
            return;
        }
        array[i] = string[i];
    }
    array[length - 1] = 0;
}
void printID(struct id id) {
    printf("age: %i, name: %s\n", id.num, id.name);
}
