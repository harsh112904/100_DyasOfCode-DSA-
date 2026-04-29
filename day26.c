#include <stdio.h>
#include <stdlib.h>

// Define structure for Doubly Linked List node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *tail = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create doubly linked list
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Traverse forward
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}