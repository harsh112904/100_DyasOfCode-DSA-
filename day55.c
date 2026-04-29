#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Queue
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Build Tree
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Right View
void rightView(struct Node* root) {
    if (!root) return;

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;

        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue(&q);

            // Last node of level
            if (i == size - 1) {
                printf("%d ", node->data);
            }

            if (node->left) enqueue(&q, node->left);
            if (node->right) enqueue(&q, node->right);
        }
    }
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    rightView(root);

    return 0;
}