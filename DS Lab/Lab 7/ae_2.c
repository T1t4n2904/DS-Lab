#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* mergeLists(Node* list1, Node* list2) {
    Node* list3 = NULL;
    Node* current1 = list1;
    Node* current2 = list2;
    Node* tail = NULL;

    while (current1 != NULL || current2 != NULL) {
        if (current1 != NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = current1->data;
            newNode->next = NULL;

            if (list3 == NULL) {
                list3 = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            current1 = current1->next;
        }

        if (current2 != NULL) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->data = current2->data;
            newNode->next = NULL;

            if (list3 == NULL) {
                list3 = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            current2 = current2->next;
        }
    }

    return list3;
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
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Populate the linked lists list1 and list2
    for (int i = 1; i <= 7; i += 2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (list1 == NULL) {
            list1 = newNode;
        } else {
            Node* current = list1;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    for (int i = 2; i <= 6; i += 2) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;

        if (list2 == NULL) {
            list2 = newNode;
        } else {
            Node* current = list2;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    printf("List1: ");
    displayList(list1);
    printf("List2: ");
    displayList(list2);

    Node* list3 = mergeLists(list1, list2);

    printf("Merged List3: ");
    displayList(list3);

    return 0;
}
