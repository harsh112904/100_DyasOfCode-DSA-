#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node for stack
struct Node {
    int data;
    struct Node* next;
};

// Push function
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop function
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = *top;
    int popped = temp->data;
    *top = temp->next;
    free(temp);

    return popped;
}

int main() {

    struct Node* stack = NULL;
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit push to stack
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            push(&stack, num);
        }

        // If operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (exp[i]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }

            push(&stack, result);
        }

        i++;
    }

    printf("Result = %d\n", pop(&stack));

    return 0;
}