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

void deleteRear(Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
    }
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        Node* current = *head;
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (position == 1) {
        Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    } else {
        Node* current = *head;
        int count = 1;
        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }
}

void insertAfter(Node** head, int data, int element) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("The list is empty.\n");
        free(newNode);
        return;
    }
    Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != NULL) {
                current->next->prev = newNode;
            }
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element not found in the list.\n");
    free(newNode);
}

void insertBefore(Node** head, int data, int element) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("The list is empty.\n");
        free(newNode);
        return;
    }
    Node* current = *head;
    while (current != NULL) {
        if (current->data == element) {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                *head = newNode;
            }
            current->prev = newNode;
            return;
        }
        current = current->next;
    }
    printf("Element not found in the list.\n");
    free(newNode);
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

void reverse(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    Node* list = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nDoubly Linked List Operations\n");
        printf("1. Insert at the rear\n");
        printf("2. Delete from the rear\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from a position\n");
        printf("5. Insert after an element\n");
        printf("6. Insert before an element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the rear: ");
                scanf("%d", &data);
                insertRear(&list, data);
                break;
            case 2:
                deleteRear(&list);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&list, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&list, position);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                insertAfter(&list, data, element);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                insertBefore(&list, data, element);
                break;
            case 7:
                traverse(list);
                break;
            case 8:
                reverse(&list);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
