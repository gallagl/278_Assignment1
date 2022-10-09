// Q1.c – Assignment 1 – Liam Gallagher

#include <stdlib.h>
#include <stdio.h>

// node structure definition with typedef shortcut

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct{
    node *head;
    node *tail;
} linked_list;

// Creating front and tail pointers for lists a-e

node *newNode(int d){

    node *pnode = (node*)malloc(sizeof(node));

    pnode->data = d;
    pnode->next = NULL;
    pnode->prev = NULL;

    return pnode;
}

// Prepend function
void prepend(linked_list *ll, int d){

    node *pnode = newNode(d);

    // First node case
    if (ll->head == NULL){
        ll->head = pnode;
        ll->tail = pnode;
    } else{
        ll->head->prev = pnode;
        pnode->next = ll->head;
        ll->head = pnode;
    }
}

// Append function
void append(linked_list *ll, int d){

    node *pnode = newNode(d);

    // Check if linked list is empty
    if (ll->head == NULL){
        ll->head = pnode;
        ll->tail = pnode;
    }else{
        ll->tail->next = pnode;
        ll->tail = pnode;
    }
}

// Pop/deque function
void deleteFromFront(linked_list *ll){

    node *temp = ll->head;

    if (ll->head == NULL){
        printf("There are no nodes to delete");
        return;
    } else{
        ll->head = ll->head->next;
        ll->head->prev = NULL;
        free(temp);
    }
}

// Insert function
void insert(linked_list *ll, int d, int pos) {

    node *pnode = newNode(d);
    node *iter = ll->head;

    if (pos == 0){
        prepend(ll,d);
        return;
    }

    int i = 0;

    while(i < (pos - 1)){
        iter = iter->next;
        i += 1;
    }

    pnode->next = iter->next;
    pnode->prev = iter;
    pnode->next->prev = pnode;
    iter->next = pnode;
}

// Global linked list variables
linked_list a;
linked_list e;
linked_list sorted_list;

// Display funciton
void display(linked_list *ll){

    node *iter = ll->head;

    while (iter != NULL){
        printf("%d\n",iter->data);
        iter = iter->next;
    }
}

// Q1 A:
void create(){

    a.head = NULL;
    a.tail = NULL;

    append(&a, 10);
    append(&a, 20);
    append(&a, 50);

    display(&a);
}

// Q1 B:
void insertfirst(){

    prepend(&a, 5);

    display(&a);
}

// Q1 C:
void deletefirst(){

    deleteFromFront(&a);
    display(&a);
}

// Q1 D:
void insertpos(){

    insert(&a,30,2); // Insert uses 0-based indexing
    display(&a);
}

// Q1 E:

void merge(){

    e.head = NULL;
    e.tail = NULL;

    // Creating list
    sorted_list.head = NULL;
    sorted_list.tail = NULL;

    // Creating list e
    append(&e, 24);
    append(&e, 25);
    append(&e, 36);

    node *dptr = a.head;
    node *eptr = e.head;
    node *sorted_head = NULL;
    node *sorted_tail = NULL;

    // Set head of the merged list
    if (dptr->data <= eptr->data){
        sorted_list.head = dptr;
        sorted_list.tail = dptr;
        dptr = dptr->next;
    }else{
        sorted_list.head = eptr;
        sorted_list.tail = eptr;
        eptr = eptr->next;
    }

    while (1) {

        // Checking case where one list has been fully traversed (meaning all larger values exist in the other list).

        if (dptr == NULL){
            while (eptr != NULL){
                sorted_list.tail->next = eptr;
                eptr->prev = sorted_list.tail;
                sorted_list.tail = eptr;
                eptr = eptr->next;
            }
            display(&sorted_list);
            return;
        }
        if (eptr == NULL){

            while (dptr != NULL){

                sorted_list.tail->next = dptr;
                dptr->prev = sorted_list.tail;
                sorted_list.tail = dptr;
                dptr = dptr->next;
            }

            display(&sorted_list);
            return;
        }

        // General merging case
        if (dptr->data <= eptr->data) {
            sorted_list.tail->next = dptr;
            dptr->prev = sorted_list.tail;
            sorted_list.tail = dptr;
            dptr = dptr->next;
        } else {
            sorted_list.tail->next = eptr;
            eptr->prev = sorted_list.tail;
            sorted_list.tail = eptr;
            eptr = eptr->next;
        }
    }
}

int main(){

    // Output
    printf("\nStart of A:\n");
    create(); // 1. a) output
    printf("End of A:\n\n");

    printf("Start of B:\n");
    insertfirst(); // 1. b) output
    printf("End of B:\n\n");

    printf("Start of C:\n");
    deletefirst(); // 1. c) output
    printf("End of C:\n\n");

    printf("Start of D:\n");
    insertpos(); // 1. d) output
    printf("End of D:\n\n");

    printf("Start of E:\n");
    merge(); // 1. d) output
    printf("End of E:\n\n");

}
