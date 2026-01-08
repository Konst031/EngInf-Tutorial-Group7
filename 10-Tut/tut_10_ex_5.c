#include<stdlib.h>
#include<stdio.h>

struct date{
    int day;
    int month;
    int year;
};

struct node{
    struct date d;
    struct node* next;
};

// create a new list
struct node* new_list_node();
// set the date of a given node
void set_date(struct node *n, int day, int month, int year);
// takes the pointer to the head, a pointer to a new node and appends it at the end of the list
void append_to_list(struct node* head, struct node* new);
// prints the entire list
void print_list(struct node* head); // exercise f
void print_list2(struct node* head); // exercise k
// extra methods for printing
void print_element(struct node* element);
void foreach(struct node* head, void (*f)(struct node* element));
// deletes the whole list
void free_list(struct node* head);
// adds two weeks to a date pointer
void add_two_weeks(struct node* element);



int main(){
    // Initialize. Head element is only 0.0.0
    struct node* head = new_list_node();
    struct node* new;

    // Add some nodes
    new = new_list_node();
    set_date(new, 18,12,2014);
    append_to_list(head,new);

    new = new_list_node();
    set_date(new, 15,2,2012);
    append_to_list(head,new);

    new = new_list_node();
    set_date(new, 15,2,2013);
    append_to_list(head,new);

    new = new_list_node();
    set_date(new, 16,2,2012);
    append_to_list(head,new);

    new = new_list_node();
    set_date(new, 10,9,2014);
    append_to_list(head,new);

    new = new_list_node();
    set_date(new, 20,9,2014);
    append_to_list(head,new);

    // print original list
    printf("\nOriginal list:\n");
    print_list(head);

    // add 2 weeks to all the elements
    foreach(head, add_two_weeks);

    // print modified list
    printf("\nModified list:\n");
    print_list(head);

    // delete list
    free_list(head);

    // print after freeing (expected no output)
    printf("\nFreed list:\n");
    print_list(head);

    free(head);
    return 0;
}


struct node* new_list_node(){
    struct node* head = malloc(sizeof(struct node));
    head->d.day = 0;
    head->d.month = 0;
    head->d.year = 0;
    head->next = NULL;
    return head;
}

void set_date(struct node *n, int day, int month, int year){
    if(n==NULL){
        return;
    }
    n->d.day = day;
    n->d.month = month;
    n->d.year = year;
}

void append_to_list(struct node* head, struct node* new){
    if(head == NULL || new == NULL){
        return;
    }
    while(head->next != NULL){
        head = head->next;
    }
    head->next = new;
    new->next = NULL;
}

void free_list(struct node* head){
    struct node* element = head->next;
    struct node* element_next;
    while(element != 0){
        element_next = element->next;
        free(element);
        element = element_next;
    }
    head->next = NULL;
}

// exercise f
void print_list(struct node* head){
    // skip the first element
    head = head->next;
    // print all the other elements (if there's only the head, it prints nothing)
    while(head != 0){
        printf("%d.%d.%d\n", head->d.day, head->d.month, head->d.year);
        head = head->next;
    }
}


void print_element(struct node* element){
    printf("%d.%d.%d\n", element->d.day, element->d.month, element->d.year);
}

// general function that given a function and the head of a list iterates over the list performing f(element) for every element
void foreach(struct node* head, void (*f)(struct node* element)){
    // skip the first element
    head = head->next;
    while(head){
        f(head);
        head = head->next;
    }
}
// exercise k)
void print_list2(struct node* head){
    foreach(head, print_element);
}

void add_two_weeks(struct node* element){
    // maximum number of days of the current month
    int limit = 31;
    int new_day;
    if(element->d.month == 2){
        if(element->d.year%4==0){
            limit = 29;
        }
        else{
            limit = 28;
        }
    }
    else if(element->d.month == 4 || element->d.month == 6 || element->d.month == 9 || element->d.month == 11){
        limit = 30;
    }

    // careful: we count days starting with 1, not 0
    new_day = (element->d.day + 14)%limit;
    if(new_day == 0){
        new_day = limit;
    }
    if(new_day < element->d.day){
        (element->d.month)++;
        if(element->d.month == 13){
            element->d.month = 1;
            (element->d.year)++;
        }
    }
    element->d.day = new_day;
}