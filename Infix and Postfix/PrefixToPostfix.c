#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
typedef struct {
    char data[MAX][MAX]; // Stack to store strings
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char* str) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    strcpy(stack->data[++stack->top], str);
}

// Function to pop an element from the stack
void pop(Stack* stack, char* str) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        str[0] = '\0';
        return;
    }
    strcpy(str, stack->data[stack->top--]);
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert prefix to postfix
void prefixToPostfix(char* prefix, char* postfix) {
    Stack stack;
    initStack(&stack);

    int n = strlen(prefix);
    
    // Traverse the prefix expression from right to left
    for (int i = n - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            // If operand, push it as a string onto the stack
            char operand[2] = {c, '\0'};
            push(&stack, operand);
        } else if (isOperator(c)) {
            // If operator, pop two operands from the stack
            char operand1[MAX], operand2[MAX];
            pop(&stack, operand1);
            pop(&stack, operand2);

            // Combine operands and operator into a new postfix expression
            char combined[MAX];
            snprintf(combined, MAX, "%s%s%c", operand1, operand2, c);

            // Push the combined expression back onto the stack
            push(&stack, combined);
        }
    }

    // The final postfix expression is at the top of the stack
    pop(&stack, postfix);
}

int main() {
    char prefix[MAX], postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
