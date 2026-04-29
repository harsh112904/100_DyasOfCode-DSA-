#include <stdio.h>

// Simple sort (you can use any sort, here bubble sort for clarity)
void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Iterative Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // not found
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort array
    sort(arr, n);

    // Print sorted array (as per your example output)
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}