#include <stdio.h>

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int arr[n];

    // Read the array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min with the first element
    int max = arr[0];
    int min = arr[0];

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Print the results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}