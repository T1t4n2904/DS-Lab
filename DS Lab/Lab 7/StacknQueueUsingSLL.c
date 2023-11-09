#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

// Stack Implementation

Node* push(Node* top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top) {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return NULL;
    }

    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void displayStack(Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack: ");
    Node* current = top;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Queue Implementation

Node* enqueue(Node* rear, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        return newNode;
    }

    rear->next = newNode;
    return newNode;
}

Node* dequeue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    Node* temp = front;
    front = front->next;
    free(temp);
    return front;
}

void displayQueue(Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    Node* current = front;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* stackTop = NULL;
    Node* queueFront = NULL;
    Node* queueRear = NULL;

    // Stack operations
    stackTop = push(stackTop, 1);
    stackTop = push(stackTop, 2);
    stackTop = push(stackTop, 3);

    displayStack(stackTop);

    stackTop = pop(stackTop);
    displayStack(stackTop);

    // Queue operations
    queueRear = enqueue(queueRear, 1);
    queueRear = enqueue(queueRear, 2);
    queueRear = enqueue(queueRear, 3);
    queueFront = queueRear; // Set front initially

    displayQueue(queueFront);

    queueFront = dequeue(queueFront);
    displayQueue(queueFront);

    return 0;
}
