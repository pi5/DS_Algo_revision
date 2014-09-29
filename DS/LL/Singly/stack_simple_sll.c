#include<stdio.h>
#include<stdlib.h>


typedef int bool;
#define true 1
#define false 0

typedef struct Node{
    // Assuming integer data
    int data;
    struct Node* next; 
} Node;

typedef struct Stack{
    Node* top;
} Stack;

void push (Stack **, int);
int pop (Stack**);
bool isEmpty (Stack**);

Node* getNode(int value){
    Node* temp = (Node*) malloc (sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void push (Stack **s , int value) {

    Node* temp = getNode(value);

    if((*s)->top == NULL) {
        (*s)->top = temp;
    }
    else {
        temp->next = (*s)->top;
        (*s)->top = temp;
    }
    return;
}

int pop (Stack **s) {
    if (isEmpty(s)) {
        return -1; // assuming that -1 is a value impossible on Stack
    }
    else {
        Node * temp = (*s)->top;	
        (*s)->top = temp->next;
        int retval = temp->data;
        free(temp);
        return retval;
    }
}

bool isEmpty (Stack** s) {
    if((*s)->top == NULL) 
        return true;
    else 
        return false;
}

Stack* getStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;   
}


int main() {
    
    Stack *s = getStack();
    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    push(&s, 0);
    
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    
    push(&s, 10);
    push(&s, 11);
    push(&s, 21);
    push(&s, 31);
    push(&s, 41);
    push(&s, 51);

    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
    printf("\n%d\n", pop(&s));
}
