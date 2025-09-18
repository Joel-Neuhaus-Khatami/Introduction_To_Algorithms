#include <stdio.h>
#include <stdlib.h>

// Simple insertion sort for floats
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket sort for floats in [0, 1)
void bucketSort(float A[], int n) {
    int i, j, idx;

    // 1. Allocate bucket sizes array and count elements per bucket
    int *bucketSizes = calloc(n, sizeof(int));
    if (!bucketSizes) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        idx = (int)(A[i] * n);
        if (idx == n) idx = n - 1;       // edge case: A[i] == 1.0
        bucketSizes[idx]++;
    }

    // 2. Allocate each bucket with exact size
    float **buckets = malloc(n * sizeof(float *));
    if (!buckets) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++) {
        buckets[i] = malloc(bucketSizes[i] * sizeof(float));
        if (bucketSizes[i] > 0 && !buckets[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        bucketSizes[i] = 0;  // reset to use as insertion index
    }

    // 3. Distribute elements into buckets
    for (i = 0; i < n; i++) {
        idx = (int)(A[i] * n);
        if (idx == n) idx = n - 1;
        buckets[idx][ bucketSizes[idx]++ ] = A[i];
    }

    // 4. Sort each bucket and concatenate back into A[]
    int writeIndex = 0;
    for (i = 0; i < n; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (j = 0; j < bucketSizes[i]; j++) {
                A[writeIndex++] = buckets[i][j];
            }
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketSizes);
}

int main() {
    float A[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");

    bucketSort(A, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", A[i]);
    }
    printf("\n");

    return 0;
}
