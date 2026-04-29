#include <stdio.h>

int main() {
    int n;
    
    // Get the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; // To keep track of elements already counted

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize visited array with 0
    }

    // Counting logic
    for (int i = 0; i < n; i++) {
        // If element is already visited, skip it
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark as visited
                count++;
            }
        }
        
        // Print the result for this distinct element
        printf("%d:%d ", arr[i], count);
    }

    return 0;
}