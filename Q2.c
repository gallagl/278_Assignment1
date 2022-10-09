// Q2.c – Assignment 1 – Liam Gallagher

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

// Push function
void push (char n)
{
    node *p = malloc(sizeof(node));
    p->data = n;
    p->next = front;
    front = p;
    //printf("+%c\n",n);
}

// Pop function
char pop(void)
{
    node *p = front;
    char rslt = p->data;
    //printf("-%c\n",p->data);
    front = p->next;
    free (p); //discard node

    return rslt;
}

// tos function
char *tos (void)
{
    return &(front->data);
}

// Casts values to int. I found that the integer differences in [], {}, and () are either 1 or 2. Using this the problem can be solved.
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
// Reads in values from an array, uses check top and prev function, and if balanced prints 1, else 0.
void solve(char s[], unsigned long long n){

    for (int i = 0; i < n; i++) {
        push(s[i]);
        if (front->next != NULL) {
            check_top_and_prev();
        }
    }

    printf("Input: %s\n",s);
    printf("Output: ");

    if (front == NULL){
        printf("1");
    } else{
        printf("0");
    }

}

int main(){

    // Test cases
    char s[20] = "{[{}{}]}[()]";
    unsigned long long n =  strlen(s);

    char s1[20] = "{{}{}}";
    unsigned long long n1 =  strlen(s1);

    char s2[20] = "[]{}()";
    unsigned long long n2 =  strlen(s2);

    char s3[20] = "{()}[)";
    unsigned long long n3 =  strlen(s3);

    char s4[20] = "{(})";
    unsigned long long n4 =  strlen(s4);

    // Output
    printf("Test 1:\n");
    solve(s,n);
    printf("\nTest 2:\n");
    solve(s1,n1);
    printf("\nTest 3:\n");
    solve(s2,n2);
    printf("\nTest 4:\n");
    solve(s3,n3);
    printf("\nTest 5:\n");
    solve(s4,n4);
}




