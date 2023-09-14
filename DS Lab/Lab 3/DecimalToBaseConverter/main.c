#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define a structure to represent a stack
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to convert a decimal number to another base using a stack
void decimalToBase(int decimalNumber, int base) {
    struct Stack stack;
    initialize(&stack);

    if (decimalNumber == 0) {
        push(&stack, 0);
    } else {
        while (decimalNumber > 0) {
            int remainder = decimalNumber % base;
            push(&stack, remainder);
            decimalNumber /= base;
        }
    }

    printf("The number in base %d is: ", base);
    while (!isEmpty(&stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

int main() {
    int decimalNumber, base;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    printf("Enter the base (e.g., 2 for binary, 8 for octal, 16 for hexadecimal): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base. Please enter a base between 2 and 16.\n");
        return 1;
    }

    decimalToBase(decimalNumber, base);

    return 0;
}
