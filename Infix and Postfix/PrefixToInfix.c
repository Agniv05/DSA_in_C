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

// Function to convert prefix to infix
void prefixToInfix(char* prefix) {
    int length = strlen(prefix);

    // Traverse the prefix expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char currentChar = prefix[i];

        // If the character is an operand, push it to the stack
        if (isalnum(currentChar)) {
            char operand[2] = {currentChar, '\0'};
            push(operand);
        }
        // If the character is an operator
        else if (isOperator(currentChar)) {
            // Pop two operands from the stack
            char* operand1 = pop();
            char* operand2 = pop();

            // Form the infix expression and push it back to the stack
            char infix[MAX];
            snprintf(infix, MAX, "(%s%c%s)", operand1, currentChar, operand2);
            push(infix);
        }
    }

    // The result will be the only element left in the stack
    printf("Infix Expression: %s\n", pop());
}

int main() {
    char prefix[MAX];

    // Input the prefix expression
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    // Convert and print the infix expression
    prefixToInfix(prefix);

    return 0;
}
