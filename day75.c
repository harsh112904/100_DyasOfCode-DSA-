#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays (for prefix sums)
int main() {
    int arr[MAX], n;
    
    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix_sum = 0;
    int max_len = 0;

    // Hash map arrays
    int hash[2 * MAX];
    for (int i = 0; i < 2 * MAX; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    int offset = MAX; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        // Case 1: sum is 0 from start
        if (prefix_sum == 0) {
            max_len = i + 1;
        }

        // Case 2: prefix sum seen before
        if (hash[prefix_sum + offset] != -2) {
            int prev_index = hash[prefix_sum + offset];
            int length = i - prev_index;
            if (length > max_len) {
                max_len = length;
            }
        } else {
            // Store first occurrence
            hash[prefix_sum + offset] = i;
        }
    }

    printf("%d\n", max_len);
    return 0;
}