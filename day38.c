#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Check full
int full() {
    return ((front == 0 && rear == MAX-1) || (front == rear + 1));
}

// push_front
void push_front(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (full()) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = x;
}

// pop_front
int pop_front() {
    if (empty()) return -1;

    int val = deque[front];

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }

    return val;
}

// pop_back
int pop_back() {
    if (empty()) return -1;

    int val = deque[rear];

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }

    return val;
}

// front element
int getFront() {
    if (empty()) return -1;
    return deque[front];
}

// rear element
int getBack() {
    if (empty()) return -1;
    return deque[rear];
}

// size
int size() {
    if (empty()) return 0;

    if (rear >= front)
        return rear - front + 1;
    else
        return MAX - front + rear + 1;
}

// clear
void clear() {
    front = rear = -1;
}

// display (for testing)
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();        // 2 5 10 20

    printf("%d\n", pop_front()); // 2
    printf("%d\n", pop_back());  // 20

    display();        // 5 10

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    return 0;
}