#include <stdio.h>
#include <stdlib.h>

// Node structure
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

int visited[100];
int stack[100], top = -1;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void dfs(struct Node* adj[], int v) {
    visited[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(adj, temp->vertex);
        }
        temp = temp->next;
    }

    push(v); // push after visiting all neighbors
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

        // Directed graph
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    // Perform DFS for all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(adj, i);
        }
    }

    // Print topological order (reverse of stack)
    printf("\nTopological Order:\n");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}