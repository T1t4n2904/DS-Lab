#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for the stack
typedef struct {
    int data;
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
StackNode* push(StackNode* top, int data) {
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
int peek(StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return top->data;
}

// Evaluate a prefix expression
int evaluatePrefixExpression(char prefix[]) {
    StackNode* stack = initStack();

    int len = strlen(prefix);

    for (int i = len - 1; i >= 0; i--) {
        char token = prefix[i];

        if (isdigit(token)) {
            stack = push(stack, token - '0');
        } else if (token == ' ' || token == '\t') {
            // Ignore spaces and tabs
        } else {
            int operand1 = peek(stack);
            stack = pop(stack);
            int operand2 = peek(stack);
            stack = pop(stack);

            switch (token) {
                case '+':
                    stack = push(stack, operand1 + operand2);
                    break;
                case '-':
                    stack = push(stack, operand1 - operand2);
                    break;
                case '*':
                    stack = push(stack, operand1 * operand2);
                    break;
                case '/':
                    stack = push(stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid character in the expression\n");
                    exit(1);
            }
        }
    }

    if (!isEmpty(stack)) {
        return peek(stack);
    } else {
        printf("Invalid expression\n");
        exit(1);
    }
}

int main() {
    char prefix[100];

    printf("Enter a prefix expression: ");
    gets(prefix);

    int result = evaluatePrefixExpression(prefix);

    printf("Result: %d\n", result);

    return 0;
}
