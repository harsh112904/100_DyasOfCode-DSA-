#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
    
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newNode;
    return head;
}

// Function to merge two sorted lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    
    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    
    return result;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    
    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }
    
    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }
    
    // Merge lists
    struct Node* mergedList = mergeLists(list1, list2);
    
    // Print merged list
    printList(mergedList);
    
    return 0;
}