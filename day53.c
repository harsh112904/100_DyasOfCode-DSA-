#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue Node (for level order)
struct QNode {
    struct Node* treeNode;
    int hd;
    struct QNode* next;
};

struct QNode *front = NULL, *rear = NULL;

// Enqueue
void enqueue(struct Node* node, int hd) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->hd = hd;
    temp->next = NULL;

    if(rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

// Dequeue
struct QNode* dequeue() {
    if(front == NULL) return NULL;

    struct QNode* temp = front;
    front = front->next;
    if(front == NULL) rear = NULL;

    return temp;
}

// Create node
struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->left = node->right = NULL;
    return node;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if(root == NULL) return;

    // Simple array for storing results (HD range -50 to +50)
    int result[100][100]; 
    int count[100] = {0};

    enqueue(root, 50); // shift index to avoid negative

    while(front != NULL) {
        struct QNode* temp = dequeue();
        struct Node* node = temp->treeNode;
        int hd = temp->hd;

        result[hd][count[hd]++] = node->data;

        if(node->left)
            enqueue(node->left, hd - 1);
        if(node->right)
            enqueue(node->right, hd + 1);

        free(temp);
    }

    // Print vertical order
    for(int i = 0; i < 100; i++) {
        if(count[i] > 0) {
            for(int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
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

    printf("Vertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}