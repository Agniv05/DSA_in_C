#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure for operators
typedef struct {
    char data[MAX];
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
void push(Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->data[++stack->top] = c;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Function to peek the top element of the stack
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

// Function to determine operator precedence
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to reverse a string
void reverseString(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Function to replace '(' with ')' and vice versa
void replaceParentheses(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Step 1: Reverse the infix expression
    reverseString(infix);

    // Step 2: Replace '(' with ')' and vice versa
    replaceParentheses(infix);

    // Step 3: Convert the modified infix expression to postfix
    char postfix[MAX];
    Stack stack;
    initStack(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else if (isOperator(c)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(c)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, c);
        }

        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

    // Step 4: Reverse the postfix expression to get the prefix expression
    strcpy(prefix, postfix);
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
