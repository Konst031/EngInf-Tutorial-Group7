#include <stdio.h>
#include <stdlib.h>

struct treeNode
{
    struct treeNode *left;
    struct treeNode *right;
    int number;
};

void printPreorder(struct treeNode *root);
void printInorder(struct treeNode *root);
void printPostorder(struct treeNode *root);
int depthFirstSearch(struct treeNode *root, int value);
struct treeNode *newNode(int value);
void deleteTree(struct treeNode *root);
void addNode(struct treeNode *root, int value);

int main(int argc, char const *argv[]) {
    struct treeNode *root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right = newNode(8);
    root->right->right = newNode(10);
    root->right->left = newNode(7);

    printf("Preorder: ");
    printPreorder(root);
    printf("\nInorder: ");
    printInorder(root);
    printf("\nPostorder: ");
    printPostorder(root);
    int numToCheck = 11;
    int numToCheck2 = 2;
    printf("\nDepth First Search for %d returned: %d", numToCheck, depthFirstSearch(root, numToCheck));
    printf("\nDepth First Search for %d returned: %d", numToCheck2, depthFirstSearch(root, numToCheck2));

    int toAdd[5] = {13, 17, 2, -17, 87435};
    for (int i = 0; i < 5; i++)
    {
        addNode(root,toAdd[i]);
        printf("\nafter adding %d: ",toAdd[i]);
        printInorder(root);
    }

    deleteTree(root);

    return 0;
}

void printPreorder(struct treeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->number);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(struct treeNode *root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->number);
    printInorder(root->right);
}

void printPostorder(struct treeNode *root) {
    if (root == NULL) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->number);
}

int depthFirstSearch(struct treeNode *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (value == root->number) {
        return 1;
    }
    if (value < root->number) {
        return depthFirstSearch(root->left, value);
    }
    else {
        return depthFirstSearch(root->right, value);
    }
}

void addNode(struct treeNode *root, int value) {
    if (root == NULL) {
        return;
    }
    if (root->number == value) {
        printf("\nValue: %d already in tree", value);
        return;
    }
    if (value < root->number) {
        if (root->left == NULL) {
            root->left = newNode(value);
            return;
        }
        addNode(root->left, value);
    }
    else {
        if (root->right == NULL) {
            root->right = newNode(value);
            return;
        }
        addNode(root->right, value);
    }
}

struct treeNode *newNode(int value) {
    struct treeNode *newNode = calloc(1, sizeof(struct treeNode));
    newNode->number = value;
    return newNode;
}

void deleteTree(struct treeNode *root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}