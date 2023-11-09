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

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

Node* unionLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current = list1;

    while (current != NULL) {
        insertRear(&result, current->data);
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (!contains(result, current->data)) {
            insertRear(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

Node* intersectionLists(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* current = list1;

    while (current != NULL) {
        if (contains(list2, current->data)) {
            insertRear(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

int contains(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Insert elements into list1 and list2
    insertRear(&list1, 1);
    insertRear(&list1, 2);
    insertRear(&list1, 3);

    insertRear(&list2, 2);
    insertRear(&list2, 3);
    insertRear(&list2, 4);

    printf("List 1: ");
    printList(list1);
    printf("\nList 2: ");
    printList(list2);

    Node* unionResult = unionLists(list1, list2);
    printf("\nUnion: ");
    printList(unionResult);

    Node* intersectionResult = intersectionLists(list1, list2);
    printf("\nIntersection: ");
    printList(intersectionResult);

    return 0;
}
