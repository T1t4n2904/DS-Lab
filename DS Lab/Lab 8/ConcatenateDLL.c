#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertRear(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void concatenate(Node** X1, Node* X2) {
    if (*X1 == NULL) {
        *X1 = X2;
    } else {
        Node* current = *X1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = X2;
        X2->prev = current;
    }
}

void traverse(Node* head) {
    printf("Doubly Linked List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;

    // Insert elements into X1 and X2
    insertRear(&X1, 1);
    insertRear(&X1, 2);
    insertRear(&X1, 3);

    insertRear(&X2, 4);
    insertRear(&X2, 5);
    insertRear(&X2, 6);

    // Concatenate X2 to X1
    concatenate(&X1, X2);

    // X1 now contains the concatenated list

    traverse(X1);

    return 0;
}
