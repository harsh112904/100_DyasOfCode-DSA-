#include <stdio.h>
#define MAX 100

int main() {
    int N;
    scanf("%d", &N);

    int queue[MAX], stack[MAX];
    int front = 0, rear = -1, top = -1;

    // Input queue elements
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[++rear]);
    }

    // Step 1: Push all queue elements into stack
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Step 2: Pop from stack back to queue (reverses order)
    rear = -1;
    for (int i = 0; i <= top; i++) {
        queue[++rear] = stack[top--];
    }

    // Output reversed queue
    for (int i = 0; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}