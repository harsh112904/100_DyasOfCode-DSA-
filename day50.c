#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Search in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int N;
    scanf("%d", &N);

    int value;
    struct Node* root = NULL;

    // Insert nodes
    for (int i = 0; i < N; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    int key;
    scanf("%d", &key);

    if (search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}