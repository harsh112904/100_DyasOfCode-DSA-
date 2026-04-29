#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Stack Node
struct Stack {
    struct Node* data[100];
    int top;
};

// Stack operations
void push(struct Stack* s, struct Node* node) {
    s->data[++(s->top)] = node;
}

struct Node* pop(struct Stack* s) {
    return s->data[(s->top)--];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Create new node
struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if(root == NULL) return;

    struct Stack currentLevel, nextLevel;
    currentLevel.top = -1;
    nextLevel.top = -1;

    int leftToRight = 1;

    push(&currentLevel, root);

    while(!isEmpty(&currentLevel)) {
        struct Node* temp = pop(&currentLevel);

        printf("%d ", temp->data);

        // Left to Right
        if(leftToRight) {
            if(temp->left)
                push(&nextLevel, temp->left);
            if(temp->right)
                push(&nextLevel, temp->right);
        }
        // Right to Left
        else {
            if(temp->right)
                push(&nextLevel, temp->right);
            if(temp->left)
                push(&nextLevel, temp->left);
        }

        // If current level finished
        if(isEmpty(&currentLevel)) {
            leftToRight = !leftToRight;

            // Swap stacks
            struct Stack tempStack = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempStack;
        }
    }
}

// Main
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);

    return 0;
}