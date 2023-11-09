#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* mergeSortedLists(Node* X, Node* Y) {
    Node* Z = NULL;
    Node* tail = NULL;

    while (X != NULL && Y != NULL) {
        if (X->data <= Y->data) {
            if (Z == NULL) {
                Z = X;
                tail = X;
            } else {
                tail->next = X;
                tail = X;
            }
            X = X->next;
        } else {
            if (Z == NULL) {
                Z = Y;
                tail = Y;
            } else {
                tail->next = Y;
                tail = Y;
            }
            Y = Y->next;
        }
    }

    if (X != NULL) {
        if (Z == NULL) {
            Z = X;
        } else {
            tail->next = X;
        }
    }

    if (Y != NULL) {
        if (Z == NULL) {
            Z = Y;
        } else {
            tail->next = Y;
        }
    }

    return Z;
}

void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* X = NULL;
    Node* Y = NULL;

    // Populate the linked lists X and Y (assumed to be sorted)
    for (int i = 1; i <= 10; i += 2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (X == NULL) {
            X = newNode;
        } else {
            Node* current = X;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    for (int i = 2; i <= 10; i += 2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        if (Y == NULL) {
            Y = newNode;
        } else {
            Node* current = Y;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    printf("List X: ");
    displayList(X);
    printf("List Y: ");
    displayList(Y);

    Node* Z = mergeSortedLists(X, Y);

    printf("Merged List Z: ");
    displayList(Z);

    return 0;
}
