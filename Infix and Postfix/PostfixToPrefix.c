#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack data structure
char stack[MAX][MAX];
int top = -1;

// Function to push a string onto the stack
void push(char* str) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], str);
    }
}

// Function to pop a string from the stack
char* pop() {
    if (top > -1) {
        return stack[top--];
    }
    return NULL;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to convert postfix to prefix
void postfixToPrefix(char* postfix) {
    int length = strlen(postfix);

    // Traverse the postfix expression from left to right
    for (int i = 0; i < length; i++) {
        char currentChar = postfix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(currentChar)) {
            char operand[2] = {currentChar, '\0'};
            push(operand);
        }
        // If the character is an operator
        else if (isOperator(currentChar)) {
            // Pop two operands from the stack
            char* operand2 = pop();
            char* operand1 = pop();

            // Form the prefix expression and push it back to the stack
            char prefix[MAX];
            snprintf(prefix, MAX, "%c%s%s", currentChar, operand1, operand2);
            push(prefix);
        }
    }

    // The result will be the only element left in the stack
    printf("Prefix Expression: %s\n", pop());
}

int main() {
    char postfix[MAX];

    // Input the postfix expression
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Convert and print the prefix expression
    postfixToPrefix(postfix);

    return 0;
}
