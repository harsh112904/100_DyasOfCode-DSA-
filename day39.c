#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (for insert)
void heapifyUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] > heap[i]) {
            swap(&heap[parent], &heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// Heapify Down (for extractMin)
void heapifyDown(int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

// Insert
void insert(int x) {
    if (size == SIZE) return;

    heap[size] = x;
    size++;
    heapifyUp(size - 1);
}

// Extract Min
int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return min;
}

// Peek
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { // insert
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'e') { // extractMin
            printf("%d\n", extractMin());
        }
        else if (op[0] == 'p') { // peek
            printf("%d\n", peek());
        }
    }

    return 0;
}