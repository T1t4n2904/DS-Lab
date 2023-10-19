#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

int isEmpty(Node* head) {
    return (head == NULL);
}

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    return newNode;
}

void insertElement(Node** head, int element) {
    Node* newNode = createNode();
    newNode->data = element;

    if (isEmpty(*head)) {
        *head = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        return;
    }

    Node* ptr = *head;

    do {
        ptr = ptr->next;
    } while (ptr->next != *head);

    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = ptr;
    ptr->next = newNode;
}

void deleteElement(Node** head, int element) {
    if (*head == NULL) {
        return;
    }

    Node* ptr = *head;

    do {
        if (ptr->data == element) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            if (ptr == *head) {
                *head = ptr->next; // Update head if the first element is deleted
            }
            free(ptr);
            return;
        }
        ptr = ptr->next;
    } while (ptr != *head);
}

void traverse(Node* head) {
    if (isEmpty(head)) {
        printf("head -> NULL");
        return;
    }

    Node* ptr = head;

    do {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("%d\n", head->data);
}

int main() {
    Node* head = NULL;

    printf("    D O U B L Y     L I N K E D     L I S T\n");
    int choice;
    int element;

    do {
        printf("\n\nWhat would you like to do?\n");
        printf("1. Insert element\n2. Delete element\n3. Display list\n4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element : ");
                scanf("%d", &element);
                insertElement(&head, element);
                printf("Your List :\n");
                traverse(head);
                break;
            case 2:
                printf("Element to delete : ");
                scanf("%d", &element);
                deleteElement(&head, element);
                printf("Your list :\n");
                traverse(head);
                break;
            case 3:
                printf("Thank you for using DLL!");
                break;
            default:
                printf("Please enter a valid option\n");
        }
    } while (choice != 3);

    // Free the memory allocated for the nodes
    Node* current = head;
    while (!isEmpty(head)) {
        Node* next = head->next;
        free(head);
        head = next;
        if (head == current) {
            break;
        }
    }

    return 0;
}
