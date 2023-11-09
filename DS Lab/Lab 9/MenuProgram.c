#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked circular list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head;
    } else {
        Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    return head;
}

// Function to delete a node from the list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    Node* current = head;
    Node* prev = NULL;

    while (1) {
        if (current->data == data) {
            if (current->next == current) {
                free(current);
                return NULL; // The list becomes empty
            }

            if (current == head) {
                head = head->next;
            }

            prev->next = current->next;
            current->next->prev = prev;
            free(current);
            printf("%d deleted from the list.\n", data);
            return head;
        }

        prev = current;
        current = current->next;

        if (current == head)
            break;
    }

    printf("%d not found in the list.\n", data);
    return head;
}

// Function to display the elements in the list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf(" (circular)\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nDoubly Linked Circular List Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                // Free memory and exit
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
