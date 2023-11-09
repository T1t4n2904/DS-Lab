#include <stdio.h>
#include <stdlib.h>

typedef struct Node* tree_pointer;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

tree_pointer createNode(int data) {
    tree_pointer newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

tree_pointer insertNode(tree_pointer root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

tree_pointer findMinValueNode(tree_pointer node) {
    tree_pointer current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

tree_pointer deleteNode(tree_pointer root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            tree_pointer temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree_pointer temp = root->left;
            free(root);
            return temp;
        }

        tree_pointer temp = findMinValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(tree_pointer root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    tree_pointer root = NULL;
    int numNodes, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Inorder Traversal (Before Deletion): ");
    inorderTraversal(root);
    printf("\n");

    int keyToDelete;
    printf("Enter the element to delete: ");
    scanf("%d", &keyToDelete);

    root = deleteNode(root, keyToDelete);

    printf("Inorder Traversal (After Deletion): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
