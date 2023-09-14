#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure for strings (for holding infix expressions)
struct Stack {
    int top;
    char items[MAX_SIZE][MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a string onto the stack
void push(struct Stack* stack, const char* item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    strcpy(stack->items[++stack->top], item);
}

// Function to pop a string from the stack
void pop(struct Stack* stack, char* item) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    strcpy(item, stack->items[stack->top--]);
}

// Function to convert a postfix expression to a fully parenthesized infix expression
void postfixToInfix(const char postfix[], char infix[]) {
    struct Stack stack;
    initialize(&stack);

    char operand1[MAX_SIZE];
    char operand2[MAX_SIZE];
    char result[MAX_SIZE];
    char expression[MAX_SIZE];

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        if (isalnum(token)) {
            sprintf(result, "%c", token);
            push(&stack, result);
        } else {
            pop(&stack, operand2);
            pop(&stack, operand1);

            sprintf(expression, "(%s%c%s)", operand1, token, operand2);
            push(&stack, expression);
        }
    }

    if (!isEmpty(&stack)) {
        pop(&stack, infix);
    } else {
        printf("Invalid postfix expression\n");
        exit(1);
    }
}

int main() {
    char postfix[MAX_SIZE];
    char infix[MAX_SIZE];

    printf("Enter a postfix expression: ");
    gets(postfix);

    postfixToInfix(postfix, infix);

    printf("Infix expression: %s\n", infix);

    return 0;
}

