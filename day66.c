#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int visited[100], recStack[100];

// DFS function to detect cycle
int dfs(struct Node* adj[], int v) {
    visited[v] = 1;
    recStack[v] = 1;

    struct Node* temp = adj[v];
    while (temp != NULL) {
        int neighbor = temp->vertex;

        // If not visited → recurse
        if (!visited[neighbor]) {
            if (dfs(adj, neighbor))
                return 1;
        }
        // If already in recursion stack → cycle
        else if (recStack[neighbor]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from recursion stack
    return 0;
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
        recStack[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Directed graph: only u → v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int hasCycle = 0;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(adj, i)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}