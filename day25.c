 #include <stdio.h>
#include <stdlib.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list dynamically
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Input key
    scanf("%d", &key);

    // Traverse and count occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Print result
    printf("%d", count);

    return 0;
}