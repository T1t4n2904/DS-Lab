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

void prefixToInfix(char prefix[], char infix[]) {
    Stack stack;
    initialize(&stack);
    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        if ((prefix[i] >= '0' && prefix[i] <= '9') || (prefix[i] >= 'A' && prefix[i] <= 'Z') || (prefix[i] >= 'a' && prefix[i] <= 'z')) {
            char operand[2] = {prefix[i], '\0'};
            push(&stack, operand[0]);
        } else if (isOperator(prefix[i])) {
            char op1 = pop(&stack);
            char op2 = pop(&stack);
            char temp[10];
            snprintf(temp, sizeof(temp), "(%c%c%c)", op1, prefix[i], op2);
            for (int j = 0; temp[j] != '\0'; j++) {
                push(&stack, temp[j]);
            }
        }
    }
    strcpy(infix, stack.data);
}

int main() {
    char prefixExpression[MAX_SIZE];
    char infixExpression[MAX_SIZE];

    printf("Enter a prefix expression: ");
    gets(prefixExpression);

    prefixToInfix(prefixExpression, infixExpression);

    printf("Infix expression: %s\n", infixExpression);

    return 0;
}
