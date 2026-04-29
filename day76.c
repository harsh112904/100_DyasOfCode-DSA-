#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Adjacency list
int adj[MAX][MAX];
int visited[MAX];
int degree[MAX];

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

    int components = 0;

    // Count components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);
    return 0;
}