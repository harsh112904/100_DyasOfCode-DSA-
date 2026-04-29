#include <stdio.h>
#include <stdlib.h>

// Structure for Linked List Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at end
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to get length of list
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    int diff = abs(len1 - len2);
    
    // Move pointer of longer list ahead
    if (len1 > len2) {
        while (diff--) head1 = head1->next;
    } else {
        while (diff--) head2 = head2->next;
    }
    
    // Traverse both lists together
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            return head1->data;  // Intersection found
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return -1; // No intersection
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }

    int result = findIntersection(head1, head2);

    if (result != -1)
        printf("%d", result);
    else
        printf("No Intersection");

    return 0;
}