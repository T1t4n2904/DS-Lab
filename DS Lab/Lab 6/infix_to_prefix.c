#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the stack
typedef struct {
    char data;
    struct StackNode* next;
} StackNode;

// Initialize the stack
StackNode* initStack() {
    return NULL;
}

// Check if the stack is empty
int isEmpty(StackNode* top) {
    return (top == NULL);
}

// Push an element onto the stack
StackNode* push(StackNode* top, char data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

// Pop an element from the stack
StackNode* pop(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack underflow\n");
        exit(1);
    }
    StackNode* temp = top;
    top = top->next;
    free(temp);
    return top;
}

// Get the top element of the stack
char peek(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

// Get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

// Convert infix expression to prefix expression
void infixToPrefix(char infix[]) {
    StackNode* stack = initStack();
    char prefix[100];
    int prefixIndex = 0;

    int len = strlen(infix);

    for (int i = len - 1; i >= 0; i--) {
        char token = infix[i];

        if (isalnum(token)) {
            prefix[prefixIndex++] = token;
        } else if (token == ')') {
            stack = push(stack, token);
        } else if (token == '(') {
            while (!isEmpty(stack) && peek(stack) != ')') {
                prefix[prefixIndex++] = peek(stack);
                stack = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != ')') {
                printf("Invalid expression\n");
                exit(1);
            } else {
                stack = pop(stack);
            }
        } else {
            while (!isEmpty(stack) && getPrecedence(peek(stack)) >= getPrecedence(token)) {
                prefix[prefixIndex++] = peek(stack);
                stack = pop(stack);
            }
            stack = push(stack, token);
        }
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
            printf("Invalid expression\n");
            exit(1);
        }
        prefix[prefixIndex++] = peek(stack);
        stack = pop(stack);
    }

    prefix[prefixIndex] = '\0';

    // Reverse the prefix expression to get the correct order
    strrev(prefix);

    printf("Prefix Expression: %s\n", prefix);
}

int main() {
    char infix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);

    return 0;
}
