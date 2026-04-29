#include <stdio.h>

int main() {
    int n, k;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    scanf("%d", &k);

    // Handle cases where k > n
    k = k % n;

    // Rotate array k times
    for(int i = 0; i < k; i++) {
        int last = arr[n - 1];

        for(int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }

        arr[0] = last;
    }

    // Print rotated array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}