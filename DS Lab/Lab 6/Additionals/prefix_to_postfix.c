#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if (!isFull(stack)) {
        stack->data[++stack->top] = item;
    }
}

char pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0'; // Return null character if the stack is empty
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void prefixToPostfix(char prefix[], char postfix[]) {
    Stack stack;
    initialize(&stack);
    int len = strlen(prefix);
    int postfixIndex = 0;

    for (int i = len - 1; i >= 0; i--) {
        if ((prefix[i] >= '0' && prefix[i] <= '9') || (prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= 'a' && prefix[i] <= 'z')) {
            postfix[postfixIndex++] = prefix[i];
        } else if (isOperator(prefix[i])) {
            char op1 = pop(&stack);
            char op2 = pop(&stack);
            postfix[postfixIndex++] = op1;
            postfix[postfixIndex++] = op2;
            postfix[postfixIndex++] = prefix[i];
        }
    }

    while (!isEmpty(&stack)) {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';
    strrev(postfix); // Reverse the postfix expression
}

int main() {
    char prefixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("Enter a prefix expression: ");
    gets(prefixExpression);

    prefixToPostfix(prefixExpression, postfixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
