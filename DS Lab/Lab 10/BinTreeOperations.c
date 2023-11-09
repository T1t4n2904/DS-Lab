#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct TNode *Tptr;
typedef struct TNode {
    int data;
    Tptr leftchild;
    Tptr rightchild;
} TNode;

Tptr root;

int top = -1;
Tptr stack[MAX];

//Create nodes in the tree
Tptr createNode(int val) {
    Tptr temp = (Tptr)malloc(sizeof(TNode));
    if (temp) {
        temp->data = val;
        temp->leftchild = temp->rightchild = NULL;
    }
    return temp;
}

//create the binary tree
void createTree(int N) {
    int cData, dIndex;
    char dir[50];
    Tptr previous = NULL, current;

    for (int i = 0; i < N; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &cData);
        Tptr temp = createNode(cData);

        // Assign root node
        if (!root) {
            root = temp;
        } else {
            printf("Enter direction: ");
            scanf("%s", dir);
            current = root;
            previous = NULL;

            for (dIndex = 0; dir[dIndex] != '\0' && current != NULL; dIndex++) {
                previous = current;
                if (dir[dIndex] == 'L' || dir[dIndex] == 'l') {
                    current = current->leftchild;
                } else {
                    current = current->rightchild;
                }
            }

            if (current != NULL || dir[dIndex] != '\0') {
                printf("Invalid\n");
                free(temp);
                return;
            }

            if (dir[dIndex - 1] == 'L' || dir[dIndex - 1] == 'l') {
                previous->leftchild = temp;
            } else {
                previous->rightchild = temp;
            }
        }
    }
}

bool isFull() {
    return top == MAX;
}

bool isEmpty() {
    return top == -1;
}

void Push(Tptr node) {
    if (!isFull()) {
        stack[++top] = node;
    }
}

Tptr Pop() {
    Tptr ret = NULL;
    if (!isEmpty()) {
        ret = stack[top--];
    }
    return ret;
}

Tptr peek() {
    return stack[top];
}

void IterativeInorder(Tptr node) {
    while (node || !isEmpty()) {
        while (node) {
            Push(node);
            node = node->leftchild;
        }
        node = Pop();
        printf("%d ", node->data);
        node = node->rightchild;
    }
}

void IterativePreorder(Tptr node) {
    while (node || !isEmpty()) {
        while (node) {
            printf("%d ", node->data);
            Push(node);
            node = node->leftchild;
        }
        node = Pop();
        node = node->rightchild;
    }
}

void IterativePostorder(Tptr node) {
    Tptr prev = NULL;
    do {
        while (node) {
            Push(node);
            node = node->leftchild;
        }
        while (node == NULL && !isEmpty()) {
            node = peek();
            if (node->rightchild == NULL || node->rightchild == prev) {
                printf("%d ", node->data);
                Pop();
                prev = node;
                node = NULL;
            } else {
                node = node->rightchild;
            }
        }
    } while (!isEmpty());
}

Tptr ParentNode(Tptr node, int target) {
    if (!node) {
        return NULL;
    }

    if ((node->leftchild && node->leftchild->data == target) || (node->rightchild && node->rightchild->data == target)) {
        return node;
    }

    Tptr left = ParentNode(node->leftchild, target);
    if (left != NULL) {
        return left;
    }

    return ParentNode(node->rightchild, target);
}

int Depth(Tptr node) {
    if (!node) {
        return 0;
    } else {
        int leftDepth = Depth(node->leftchild);
        int rightDepth = Depth(node->rightchild);

        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}

void Ancestors(Tptr root, int targetNode) {
    if (root == NULL) {
        return;
    }

    if (root->data == targetNode) {
        return; 
    }

    // If the target node is in the left subtree
    if ((root->leftchild && root->leftchild->data == targetNode) ||
        (root->rightchild && root->rightchild->data == targetNode)) {
        printf("%d ", root->data);
        return;
    }

    // Recursively search for the target node
    if (targetNode < root->data) {
        printf("%d ", root->data);
        Ancestors(root->leftchild, targetNode);
    } else {
        printf("%d ", root->data);
        Ancestors(root->rightchild, targetNode);
    }
}


int leafNodes(Tptr node) {
    if (!node) {
        return 0;
    }
    if (node->leftchild == NULL && node->rightchild == NULL) {
        return 1;
    }
    return leafNodes(node->leftchild) + leafNodes(node->rightchild);
}

int main()
{
    int N;
    root = NULL;
    int choice, target;

    do {
        printf("\nBinary Tree Operations\n");
        printf("1. Create Tree\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find Parent of a Node\n");
        printf("6. Find Depth of the Tree\n");
        printf("7. Print Ancestors of a Node\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create the binary tree
                printf("Enter the number of nodes: ");
                scanf("%d", &N);
                createTree(N);
                break;

            case 2:
                // Inorder Traversal
                printf("Inorder Traversal: ");
                IterativeInorder(root);
                break;

            case 3:
                // Preorder Traversal
                printf("Preorder Traversal: ");
                IterativePreorder(root);
                break;

            case 4:
                // Postorder Traversal
                printf("Postorder Traversal: ");
                IterativePostorder(root);
                break;

            case 5:
                // Find Parent of a Node
                printf("Enter the value of the target node: ");
                scanf("%d", &target);
                Tptr parent = ParentNode(root, target);
                if (parent) {
                    printf("Parent of %d is %d\n", target, parent->data);
                } else {
                    printf("Node not found\n");
                }
                break;

            case 6:
                // Find Depth of the Tree
                printf("Depth of the tree is: %d\n", Depth(root));
                break;

            case 7:
                // Print Ancestors of a Node
                printf("Enter the value of the target node: ");
                scanf("%d", &target);
                printf("Ancestors of %d: ", target);
                Ancestors(root,target);
                break;

            case 8:
                // Count Leaf Node
                printf("Number of leaf nodes: %d\n", leafNodes(root));
                break;

            case 9:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}