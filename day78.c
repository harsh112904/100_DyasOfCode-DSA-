#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int minKey(int key[], int visited[], int n) {
    int min = INT_MAX, min_index;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
        visited[i] = 0;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int key[MAX];
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
    }

    key[1] = 0; // start from node 1
    int total_weight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, visited, n);
        visited[u] = 1;

        total_weight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total_weight);
    return 0;
}