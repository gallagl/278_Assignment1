#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node* newNode(int d){
    node *pnode;
    pnode = (node*)malloc(sizeof(node));
    pnode->data = d;
    pnode->next = NULL;
    return pnode;
}
/*void enque(int d){ // Same as append

    node *pnode = newNode(d);
    node *temp;

    if (head == NULL){
        head = pnode;
    } else{
        temp = head;
        head = pnode;
        pnode->next = temp;
    }
}*/

void deque(){ // Delete first node

    if (head == NULL){
        printf("The queue is empty");
        return;
    } else {
        node *temp;
        temp = head;
        head = head->next;
        free(head);
    }
}

void enque(int d){ // Insert at end
    node *iter = head;
}

int main(){
    node *first = newNode(5);
    printf("%d",first->data);
}
