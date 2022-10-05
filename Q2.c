// Need to create a stack

// Given input: {[{}{}]} this is considered balanced and therefore a 1 should be returned.
// Given: {(}), this is not balanced

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    struct node *next;
    char data;
} node;

node *front = NULL;

void push (char n)
{
    node *p = malloc(sizeof(node));
    p->data = n;
    p->next = front;
    front = p;
    //printf("+%c\n",n);
}

char pop(void)
{
    node *p = front;
    char rslt = p->data;
    //printf("-%c\n",p->data);
    front = p->next;
    free (p); //discard node

    return rslt;
}

char *tos (void)
{
    return &(front->data);
}

void check_top_and_prev(void) {

    char t = pop();
    char t_minus1 = pop();

    if ((int) t - (int) t_minus1 == 2 || (int) t - (int) t_minus1 == 1) {
        return;
    } else {
        push(t_minus1);
        push(t);
    }
}

int main(){

    char s[20] = "[][]{}[]{";
    unsigned long long n =  strlen(s);

    for (int i = 0; i < n; i++) {
        push(s[i]);
        if (front->next != NULL) {
            check_top_and_prev();
        }
    }


// figure out how to check if the stack is empty at this stage. figure out where front ends up, why it's not working

   if (front == NULL){
        printf("1");
    } else{
        printf("0");
    }








}




