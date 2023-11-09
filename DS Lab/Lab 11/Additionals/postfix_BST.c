#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct StackNode {
    TreeNode *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack {
    StackNode *top;
} Stack;

// Function to create a new TreeNode
TreeNode *createTreeNode(char data) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to create an empty stack
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push a TreeNode onto the stack
void push(Stack *stack, TreeNode *node) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = node;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a TreeNode from the stack
TreeNode *pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return NULL;
    }

    StackNode *temp = stack->top;
    TreeNode *node = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return node;
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to build a binary expression tree from a postfix expression
TreeNode *buildExpressionTree(char postfix[]) {
    Stack *stack = createStack();
    for (int i = 0; postfix[i]; i++) {
        TreeNode *node = createTreeNode(postfix[i]);
        if (isOperator(postfix[i])) {
            node->right = pop(stack);
            node->left = pop(stack);
        }
        push(stack, node);
    }
    return pop(stack);
}

// Function to evaluate the binary expression tree
int evaluateExpressionTree(TreeNode *root) {
    if (!root) {
        return 0;
    }

    if (!root->left && !root->right) {
        return root->data - '0';
    }

    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

int main() {
    char postfixExpression[100];

    printf("Enter a postfix expression: ");
    scanf("%s", postfixExpression);

    TreeNode *root = buildExpressionTree(postfixExpression);
    printf("The postfix expression tree has been created.\n");

    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}
