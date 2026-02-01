#include <stdio.h>

int main() {
    int n, pos, x, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n + 1];

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter number to insert: ");
    scanf("%d", &x);

    for (i = n; i >= pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos - 1] = x;

    printf("After inserting %d at position %d:\n", x, pos);
    for (i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
