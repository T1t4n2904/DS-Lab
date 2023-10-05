//C program for Singly linked list
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;



//Functions for insertion

void insertAtFront(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = new_data;
    new_node -> next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(Node** head, int new_data){

    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* ptr = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(ptr -> next != NULL){
        ptr = ptr->next;
    }

    ptr -> next = new_node;
}

void insertAtIndex(Node** head_ref, int new_data, int index){
    Node* ptr = *head_ref;
    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->data = new_data;

    if(*head_ref == NULL){
        *head_ref = new_node;
        new_node->next = NULL;
    }

    for(int i=0; i< index-2; i++)
    {
        ptr = ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}





void deleteAtFront(Node** head_ref, int new_data){

}

void deleteAtIndex(Node** head_ref, int new_data){

}

void deleteAtEnd(Node** head_ref, int new_data){

}

void traverse(Node* head){
    Node* ptr = head;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

// This function prints contents of
// linked list starting from head


// Driver code
int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    Node** ref = &head;
    head = NULL;

    insertAtEnd(ref,6);
    insertAtEnd(ref,7);
    insertAtEnd(ref,8);
    insertAtFront(ref,5);
    insertAtIndex(ref, 20, 4);

    traverse(head);
    return 0;
}
