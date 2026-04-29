#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node *head = NULL, *tail = NULL;

    // Create linked list using dynamic memory allocation
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int k;
    scanf("%d", &k);

    // If only one node or k = 0
    if (head->next == NULL || k == 0) {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Find length and last node
    struct Node* temp = head;
    int length = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make list circular
    temp->next = head;

    // Reduce k if greater than length
    k = k % length;

    int steps = length - k;
    struct Node* newTail = head;

    // Move to (length - k - 1)th node
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    // Print rotated list
    temp = newHead;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}