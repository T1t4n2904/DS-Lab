#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure to represent a stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push a character onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

// Function to pop a character from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Function to check if a string is a palindrome
bool isPalindrome(const char* str) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(str);

    // Push the first half of the characters onto the stack
    for (int i = 0; i < length / 2; i++) {
        push(&stack, str[i]);
    }

    // If the length of the string is odd, skip the middle character
    if (length % 2 != 0) {
        i++;
    }

    // Compare the remaining characters with the characters popped from the stack
    while (str[i] != '\0') {
        if (str[i] != pop(&stack)) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    gets(input);

    if (isPalindrome(input)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
