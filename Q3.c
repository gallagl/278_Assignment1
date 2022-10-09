// Q3.c – Assignment 1 – Liam Gallagher

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

typedef struct{
    node *head;
    node *tail;
} queue;

typedef struct{
    node *head;
    node *tail;
} stack;

int counter = 0;

queue q = {NULL,NULL};
queue output = {NULL,NULL};

stack s = {NULL,NULL};

node* newNode(int d){
    node *pnode;
    pnode = (node*)malloc(sizeof(node));
    pnode->data = d;
    pnode->next = NULL;
    return pnode;
}

void deque(queue *qu){ // Delete first node

    if (qu->head == NULL){
        printf("The queue is empty\n");
        return;
    } else {
        counter -= 1;
        node *temp = qu->head;
        qu->head = qu->head->next;
        free(temp);
    }
}

// Push function
void push (int n,stack *stk)
{
    node *p = malloc(sizeof(node));
    p->data = n;
    p->next = stk->head;
    stk->head = p;
}
// Pop function
int pop(stack *stk)
{
    node *p = stk->head;
    int rslt = p->data;

    stk->head = p->next;
    free (p); //discard node

    return rslt;
}
// Enqueue function
void enque(int d,queue *qu){ // Insert at end

    node *pn = newNode(d);
    node *iter = qu->tail;

    if (qu->head == NULL){
        qu->head = pn;
        qu->tail = pn;
        counter += 1;
        return;
    }

    counter += 1;
    iter->next = pn;
    qu->tail = pn;

}

// Print queue function
void print_queue(queue *qu){

    if(qu->head == NULL){
        printf("The queue is empty\n");
        return;
    }

    node *curr = qu->head;
    while (curr != NULL){
        printf("%d ->",curr->data);
        curr = curr->next;
    }
}

// Swap function
void swap_first_k(int k,int input[]){

    // Push the k values to be reversed into a stack
    for (int i = 0;i < k;i++){
        push(input[i],&s);
        deque(&q);
    }

    for (int i = 0;i < k;i++){
        enque(pop(&s),&output);
    }

    while (q.head != NULL){
        enque(q.head->data,&output);
        deque(&q);
    }
}

int main() {

    int input[1000];
    int n = 0;
    int k;

    // Output
    printf("Enter the values in the queue\n");

    while (1) {

        int x;
        scanf("%d", &x);
        if (x == -1) {
            break;
        } else{
            input[n] = x;
            n++;
        }
    }

    printf("Enter the k value:");
    scanf("%d",&k);

    if (k > n){
        printf("k cannot be larger than the length of the queue. Please try again.\n");
    }
    // Enter values into a queue
    for (int i = 0;i < n;i++){
        enque(input[i],&q);
    }

    printf("Input:  ");
    print_queue(&q);
    printf("\n");

    swap_first_k(k,input);

    printf("Output: ");
    print_queue(&output);
    printf("\n");
}
