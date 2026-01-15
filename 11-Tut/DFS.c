#include <stdlib.h>
#include <stdio.h>

struct treeNode
{
    struct treeNode* left;
    struct treeNode* right;
    int number;
};

void printPreorder(struct treeNode* root);
void printInorder(struct treeNode* root);
void printPostorder(struct treeNode* root);
int depthFirstSearch(struct treeNode* root, int value);
struct treeNode* newNode(int value);
void deleteTree(struct treeNode* root);


int main(int argc, char const *argv[])
{
    struct treeNode* root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right = newNode(8);
    root->right->right = newNode(10);
    root->right->left = newNode(7);
    
    printPreorder(root);

    deleteTree(root);

    return 0;
}

void printPreorder(struct treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->number);
    printPreorder(root->left);
    printPreorder(root->right);    
}

void printInorder(struct treeNode* root)
{
    /**Your Code**/
}

void printPostorder(struct treeNode* root)
{
    /**Your Code**/
}

int depthFirstSearch(struct treeNode* root, int value)
{
    /**Your Code**/
}

struct treeNode* newNode(int value)
{
    struct treeNode* newNode = calloc(1, sizeof(struct treeNode));
    newNode->number = value;
    return newNode;
}

void deleteTree(struct treeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);    
}