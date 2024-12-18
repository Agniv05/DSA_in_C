#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack //stack structure
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){   //initialize stack top
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){       //checks operator
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){ //checks if expression is an operator or operand
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));    
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));    //size of postfix expression
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')     //until infix expression is zero
    {
        if(!isOperator(infix[i])){     //if it is not operator
            postfix[j] = infix[i];     // we put it as it is in postfix
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){     //if infix char is greater than precedence
                push(sp, infix[i]);                                 // push charechter in postfix
                i++;
            }
            else{                                                    //otherwise
                postfix[j] = pop(sp);                                // pop it from sp and add in postfix expression
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char * infix = "x-y/z-k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
