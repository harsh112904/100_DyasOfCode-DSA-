#include <stdio.h>

#define MAX 1000

int arr[MAX];

// Merge two sorted halves
void merge(int left, int mid, int right) {
    int temp[MAX];
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Recursive merge sort
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(0, n - 1);

    // Output sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}