#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char arr[MAX];
} Stack;

// Stack operations
void push(Stack *s, char ch) {
    s->arr[++(s->top)] = ch;
}

char pop(Stack *s) {
    return s->arr[(s->top)--];
}

char peek(Stack *s) {
    return s->arr[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// Utility to check precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Utility to check if character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to reverse a string
void reverse(char *expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
}

// Convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    Stack s;
    s.top = -1;

    reverse(infix); // Reverse the infix expression

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // Handle operands
        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        // Handle '(' (after reversal, ')' becomes '(')
        else if (ch == '(') {
            push(&s, ch);
        }
        // Handle ')' (after reversal, '(' becomes ')')
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                prefix[j++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        // Handle operators
        else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)) {
                prefix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&s)) {
        prefix[j++] = pop(&s);
    }

    prefix[j] = '\0';
    reverse(prefix); // Reverse the result to get the prefix expression
}

// Main function
int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
