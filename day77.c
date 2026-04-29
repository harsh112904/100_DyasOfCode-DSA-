#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int degree[MAX];
int visited[MAX];

// DFS function
void dfs(int node) {
    visited[node] = 1;

    for (int i = 0; i < degree[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        degree[i] = 0;
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u; // undirected graph
    }

    // Start DFS from node 1
    dfs(1);

    // Check if all nodes are visited
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");
    return 0;
}