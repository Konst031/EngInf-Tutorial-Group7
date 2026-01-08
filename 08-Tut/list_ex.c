#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    float value;
};

// all functions that add a node to the list can be changed by taking a float value as an input and not a struct node *
// then you need to create the node directly in the function (you can do that by just using the createNode function)
// you can find this Ansatz in the solutions of Martina Nibbi on moodle (group 5 tutorial_08_1.c)
// conceptually they are however the same

struct node *createNode(float value);
struct node *addEnd(struct node *head, struct node *nodeToAdd);
struct node *addFront(struct node *head, struct node *nodeToAdd);
void printList(struct node *head);
struct node *addPos(struct node *head, struct node *nodeToAdd, int position);
struct node *delPos(struct node *head, int position);

void deleteList(struct node *head);
void deleteListRecursive(struct node *head);

// these functions are an example that use pointer to pointers in order to change the head pointer without returning it
// they are more complicated and can be seen as an additional resource for interested students
// using these functions in the main is just a bit more elegant
void addPosAlt(struct node **head, struct node *nodeToAdd, int position);
void delPosAlt(struct node **head, int position);
void addFrontAlt(struct node **head, struct node *nodeToAdd);
void addEndAlt(struct node **head, struct node *nodeToAdd);

int main(int argc, char const *argv[]) {
    // I initialize head as NULL to test the functionality of addEnd when receiving a NULL pointer as head
    struct node *head = NULL;
    head = addEnd(head, createNode(2));
    head = addEnd(head, createNode(5));
    // or use: addEndAlt(&head, createNode(x)) with x the value
    printList(head);

    head = addFront(head, createNode(1));
    // or use: addFrontAlt(&head,createNode(1));
    printList(head);

    head = addPos(head, createNode(17), 1);
    head = addPos(head, createNode(8), 0);
    head = addPos(head, createNode(12), 8);
    // or use: addPosAlt(&head,createNode(x),y); with x the value and y the position
    printList(head);

    head = delPos(head, 2);
    head = delPos(head, 0);
    // or use: delPosAlt(&head,x); with x the position
    printList(head);

    deleteList(head);
    return 0;
}

/**
 * @brief Create a Node object 
 * 
 * @param value float value stored in node
 * @return struct node* to created object
 */
struct node *createNode(float value) {
    struct node *temp = malloc(sizeof(struct node));
    temp->value = value;
    temp->next = 0;
    return temp;
}

/**
 * @brief adds Node to the end of the list
 * 
 * @param head pointer to head of list
 * @param nodeToAdd pointer to node that shall be added
 * @return struct node* returns head pointer (may be changed if list initially empty)
 */
struct node *addEnd(struct node *head, struct node *nodeToAdd) {
    if (head != 0) {
        struct node *temp = head; // we can't iterate using the head pointer, since we have to return it later and thus
                                  // aren't able to change it
        while (temp->next != 0) {
            temp = temp->next;
        }
        temp->next = nodeToAdd;
        return head;
    }
    return nodeToAdd; // returns the node as new head pointer, if the head pointer was a null-pointer
}

/**
 * @brief adds node to front of list
 * 
 * @param head pointer to head of list
 * @param nodeToAdd pointer to node to insert
 * @return struct node* new head pointer
 */
struct node *addFront(struct node *head, struct node *nodeToAdd) {
    if (nodeToAdd != 0) {
        nodeToAdd->next = head;
        return nodeToAdd;
    }
    else {
        printf("Error, nodeToAdd is NULL-Pointer; Returning unchanged head");
    }
    return head;
}

/**
 * @brief prints list
 * 
 * @param head pointer to head of list
 */
void printList(struct node *head) {
    if (head != 0) {
        printf("%f; ", head->value);
        while (head->next != 0) {
            head = head->next;
            printf("%f; ", head->value);
        }
        printf("\n");
    }
}

/**
 * @brief inserts node at given position
 * 
 * @param head pointer to head of list
 * @param nodeToAdd pointer to node that shall be inserted
 * @param position index of position where node shall be inserted
 * @return struct node* to head of list
 */
struct node *addPos(struct node *head, struct node *nodeToAdd, int position) {
    if (head == 0) {
        printf("Error: Head is NULL-Pointer");
        return head;
    }
    if (position == 0) {
        return addFront(head, nodeToAdd); // make use of already written code
    }
    struct node *temp = head; // we can't directly iterate over the head pointer, since we return it
    int i = 0;
    while (temp->next != 0 && i < position - 1) // we need the pointer in front of the position we want to add the node
    {
        i++;
        temp = temp->next;
    }
    nodeToAdd->next = temp->next; // to add node we have to change the pointers accordingly (see slides)
    temp->next = nodeToAdd;
    return head;
}

/**
 * @brief delets node at position
 * 
 * @param head pointer to head of list
 * @param position index of node that shall be deleted
 * @return struct node* to head of list
 */
struct node *delPos(struct node *head, int position) {
    if (head == 0) {
        printf("Error: Head is NULL-Pointer");
        return head;
    }
    if (position == 0) {
        struct node *newHead = head->next;
        free(head);
        return newHead;
    }

    struct node *temp = head;              // we can't directly iterate over the head pointer, since we return it
    for (int i = 0; i < position - 1; i++) // we need the pointer right before the one we want to delete
    {
        if (temp->next == 0) // this time we do nothing if the position is not part of the list
        {
            printf("Error: position not part of the Array");
            return head;
        }
        temp = temp->next;
    }

    if (temp->next != 0) // temp->next is the node we want to delete, however we haven't checked if there is a node
    {
        struct node *toDelete = temp->next; // save pointer of node we want to delete
        temp->next = toDelete->next;        // reroute the pointer in front of the node we want to delete
        free(toDelete);                     // delete node
    }
    return head;
}

/**
 * @brief frees the memory of the whole list 
 * 
 * @param head pointer to head of list
 */
void deleteList(struct node *head) {
    if (head != 0) {
        while (head->next != NULL) {
            struct node *toDelete = head;
            head = head->next;
            free(toDelete);
        }
        free(head);
    }
}

/**
 * @brief frees the memory of the whole list in a recursive manner
 * 
 * @param head pointer to head of list
 */
void deleteListRecursive(struct node *head) {
    if (head->next == NULL) // base-case -> if Tail reached: free Tail
    {
        free(head);
        return;
    }
    deleteList(head->next); // recursion!
    free(head);             // reached only after Tail and all nodes after the current one are freed
}

/**
 * @brief adds node to end of list
 * 
 * @param head pointer to pointer to head of list (Head pointer may be changed during function)
 * @param nodeToAdd pointer to node to add
 */
void addEndAlt(struct node **head, struct node *nodeToAdd) {
    if (head == 0) {
        return;
    }
    if (*head == 0) // if head-pointer is NULL-pointer we set the nodeToAdd as new head
    {
        *head = nodeToAdd;
        return;
    }

    struct node *temp =
        *head; // we can't iterate using the head pointer, since it is passed by reference and we thus would change it
    while (temp->next != 0) {
        temp = temp->next;
    }
    temp->next = nodeToAdd;
}

/**
 * @brief adds node to front of list
 * 
 * @param head pointer to pointer to head of list (Head pointer may be changed during function)
 * @param nodeToAdd pointer to node to add
 */
void addFrontAlt(struct node **head,
                 struct node *nodeToAdd) // This function changes the head-Pointer, so we need a struct node**
{
    if (head == 0) {
        return;
    }
    nodeToAdd->next = *head;
    *head = nodeToAdd; // new head-pointer
}

/**
 * @brief adds node to position given to function
 * 
 * @param head pointer to pointer to head of list (Head pointer may be changed during function)
 * @param nodeToAdd pointer to node to add
 * @param position index of inserted node
 */
void addPosAlt(struct node **head, struct node *nodeToAdd,
               int position) // This function may change the head-Pointer, so we need a struct node**
{
    // these two if statements should not be put into one, since you first have to check,
    // if the head pointer pointer is no NULL-pointer before dereferencing it

    if (head == 0) {
        return;
    }
    if (*head == 0) {
        return;
    }

    if (position == 0) {
        addFrontAlt(head, nodeToAdd);
        return;
    }
    struct node *temp = *head;
    // it is important to not iterate over the head pointer directly,
    // since in this function it got passed by reference and not by value.
    // So changing the head pointer here actually changes the head pointer. We don't want to do that when iterating over
    // the list

    int i = 0;
    while (temp->next != 0 && i < position - 1) // we need the pointer in front of the position we want to add the node
    {
        i++;
        temp = temp->next;
    }
    nodeToAdd->next = temp->next;
    temp->next = nodeToAdd;
}

/**
 * @brief deletes node at given position
 * 
 * @param head pointer to pointer to head of list (Head pointer may be changed during function)
 * @param position index of node to delete
 */
void delPosAlt(struct node **head, int position) {
    if (head == 0) {
        return;
    }
    if (*head == 0) {
        return;
    }
    if (position == 0) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node *iterator = *head;
    for (int i = 0; i < position - 1; i++) // we need the pointer right before the one we want to delete
    {
        if (iterator->next == 0) {
            return;
        }
        iterator = iterator->next;
    }
    if (iterator->next != 0) {
        struct node *temp = iterator->next;
        iterator->next = temp->next;
        free(temp);
    }
}