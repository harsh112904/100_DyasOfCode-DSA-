#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Queue implementation
int queue[100], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int visited[100];

// BFS function
void bfs(struct Node* adj[], int start) {
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Undirected graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    bfs(adj, start);

    return 0;
}