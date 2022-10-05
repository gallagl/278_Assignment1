#include <stdlib.h>
#include <stdio.h>

// node structure definition with typedef shortcut

typedef struct node
{
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
    append(&e, 26);

    node *a_iter = a.head;
    node *e_iter = e.head;

    node *sort = sorted_list.head;

    // Set front of output
/*
    if (a_iter->data <= e_iter->data){
        sorted_list.front = a_iter;

        a_iter = a_iter->next;
    } else{
        sorted_list.front = e_iter;
        e_iter = e_iter->next;
    }
    // Loop through to both to sort
    while ((a_iter != NULL) && (e_iter != NULL)){
        if (a_iter->data <= e_iter->data){
            sort->next = a_iter;
        } else{
            sort->next = e_iter;
        }

    }
*/


    display(&sorted_list);


}

int main(){

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
