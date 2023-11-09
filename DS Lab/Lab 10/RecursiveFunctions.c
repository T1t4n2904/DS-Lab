#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Tptr;
typedef struct Node {
    int data;
    Tptr left;
    Tptr right;
} Node;

Tptr createNode(int data) {
    Tptr newNode = (Tptr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// recurs function to insert elements 
Tptr insert(Tptr root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void printInorder(Tptr root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

void printPreorder(Tptr root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(Tptr root) {
    if (root != NULL) {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Tptr root = NULL;
    int nodes, data;

    printf("Enter the number of nodes: "); // 5
    scanf("%d", &nodes);

    for (int i = 0; i < nodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data); // 10 5 15 12 17
        root = insert(root, data);
    }

    printf("Inorder Traversal: ");
    printInorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    printPreorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    printPostorder(root);
    printf("\n");

    return 0;
}