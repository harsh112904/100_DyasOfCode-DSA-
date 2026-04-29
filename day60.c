#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Build Tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n) {
            curr->left = newNode(arr[i++]);
            queue[rear++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            queue[rear++] = curr->right;
        }
    }

    return root;
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isComplete(struct Node* root, int index, int totalNodes) {
    if (!root) return 1;

    if (index >= totalNodes) return 0;

    return isComplete(root->left, 2 * index + 1, totalNodes) &&
           isComplete(root->right, 2 * index + 2, totalNodes);
}

// Check Heap Property
int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right) {
        return (root->data <= root->left->data);
    } else {
        if (root->data <= root->left->data &&
            root->data <= root->right->data)
            return isHeap(root->left) && isHeap(root->right);
        else
            return 0;
    }
}

// Main Check Function
int isMinHeap(struct Node* root) {
    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isHeap(root))
        return 1;
    else
        return 0;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}