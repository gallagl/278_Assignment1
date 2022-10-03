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

node *head = NULL;

void push (char n)
{
    node *p = malloc(sizeof(node));
    p->data = n;
    p->next = head;
    head = p;
}

char pop(void)
{
    node *p = head;
    char rslt = p->data;
    head = p->next;
    free (p); //discard node
    return rslt;
}

char *tos (void)
{
    return &(head->data);
}

int main(){

    char s[20] = "[()]";

    for (int i = 0; i < 4; i++){
        push(s[i]);
    }





    char e = '{';
    printf("%d",e);


}