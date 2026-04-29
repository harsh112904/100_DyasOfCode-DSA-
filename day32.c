#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

// Display remaining stack (top to bottom)
void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, value;

    // Number of elements to push
    scanf("%d", &n);

    // Push n elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}