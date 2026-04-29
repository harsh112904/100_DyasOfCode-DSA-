#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;

    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        // If operand → add to postfix
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }

        // If '(' → push
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If ')' → pop until '('
        else if (infix[i] == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); 
        }

        // Operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i])) {
                postfix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}