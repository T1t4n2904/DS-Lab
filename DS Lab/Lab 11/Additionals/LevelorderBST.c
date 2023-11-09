#include <stdio.h>
#include <stdlib.h>

typedef struct Node* tree_pointer;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Structure for a queue node
struct QueueNode {
    tree_pointer data;
    struct QueueNode* next;
};

typedef struct QueueNode* Queue;

// Function to create a new node for the queue
struct QueueNode* createQueueNode(tree_pointer node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = node;
    newNode->next = NULL;
    return newNode;
}

// Functions for queue operations
int isEmpty(Queue q) {
    return q == NULL;
}

void enqueue(Queue* q, tree_pointer node) {
    struct QueueNode* newNode = createQueueNode(node);
    if (isEmpty(*q)) {
        *q = newNode;
    } else {
        struct QueueNode* temp = *q;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

tree_pointer dequeue(Queue* q) {
    if (isEmpty(*q)) {
        return NULL;
    } else {
        struct QueueNode* temp = *q;
        tree_pointer node = temp->data;
        *q = temp->next;
        free(temp);
        return node;
    }
}

// Implicit insertNode function
tree_pointer insertNode(tree_pointer root, int data) {
    if (root == NULL) {
        root = (tree_pointer)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Level order traversal function
void levelOrderTraversal(tree_pointer root) {
    if (root == NULL) {
        return;
    }

    Queue queue = NULL;
    enqueue(&queue, root);

    while (!isEmpty(queue)) {
        tree_pointer current = dequeue(&queue);
        printf("%d ", current->data);

        if (current->left) {
            enqueue(&queue, current->left);
        }
        if (current->right) {
            enqueue(&queue, current->right);
        }
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

        // Implicitly insert nodes into the BST
        root = insertNode(root, data);
    }

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);

    return 0;
}
