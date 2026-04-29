#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element and keep array sorted
void insert(int x) {
    if (size == MAX) {
        return;
    }

    pq[size++] = x;

    // Sort the array (ascending)
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (pq[i] > pq[j]) {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

// Delete highest priority (smallest element)
int delete() {
    if (size == 0) {
        return -1;
    }

    int val = pq[0];

    // Shift elements left
    for (int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
    return val;
}

// Peek smallest element
int peek() {
    if (size == 0) {
        return -1;
    }
    return pq[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {   // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') {  // delete
            printf("%d\n", delete());
        }
        else if (op[0] == 'p') {  // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}