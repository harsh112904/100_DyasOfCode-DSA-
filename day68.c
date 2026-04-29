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

// Queue
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

int main() {
    int n, m;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Node* adj[n];
    int indegree[100] = {0};

    // Initialize adjacency list
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Directed edge u → v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++; // increase indegree
    }

    // Add all vertices with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("\nTopological Order:\n");

    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        count++;

        struct Node* temp = adj[v];
        while (temp != NULL) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0) {
                enqueue(temp->vertex);
            }

            temp = temp->next;
        }
    }

    // Check for cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }

    return 0;
}