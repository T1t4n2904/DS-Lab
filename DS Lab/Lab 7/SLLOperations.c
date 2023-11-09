#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element before another element in the list
void insertBefore(Node **head, int data, int target) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty. Cannot insert before.\n");
        return;
    }

    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data != target) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Target element not found in the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert an element after another element in the list
void insertAfter(Node *head, int data, int target) {
    Node *newNode = createNode(data);
    Node *current = head;
    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target element not found in the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete a given element from the list
void deleteElement(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->data == data) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to traverse the list
void traverseList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to reverse the list
void reverseList(Node **head) {
    Node *prev = NULL;
    Node *current = *head;
    Node *nextNode;
    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    *head = prev;
}

// Function to sort the list (ascending order)
void sortList(Node **head) {
    Node *sortedList = NULL;
    Node *current = *head;
    while (current != NULL) {
        Node *nextNode = current->next;
        insertInSortedOrder(&sortedList, current);
        current = nextNode;
    }
    *head = sortedList;
}

// Helper function to insert a node into a sorted list
void insertInSortedOrder(Node **head, Node *newNode) {
    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *current = *head;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete every alternate node in the list
void deleteAlternateNodes(Node *head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete alternate nodes.\n");
        return;
    }

    Node *current = head;
    while (current != NULL && current->next != NULL) {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("Linked List Operations:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete an element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &target);
                insertBefore(&head, data, target);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &target);
                insertAfter(head, data, target);
                break;
            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                break;
            case 4:
                printf("Linked List: ");
                traverseList(head);
                break;
            case 5:
                reverseList(&head);
                printf("List reversed.\n");
                break;
            case 6:
                sortList(&head);
                printf("List sorted.\n");
                break;
            case 7:
                deleteAlternateNodes(head);
                printf("Every alternate node deleted.\n");
                break;
            case 8:
                printf("Enter the element to insert in a sorted list: ");
                scanf("%d", &data);
                insertInSortedOrder(&head, createNode(data));
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
