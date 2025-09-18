#include <stdio.h>
#include <stdlib.h>

// Perform counting sort on array A of size n.
// Assumes all values in A are in the range [0..k].
void countingSort(int A[], int n) {
    // 1. Find the maximum value (k)
    int i;
    int max = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    int range = max + 1;

    // 2. Allocate count array and output buffer
    int *count = calloc(range, sizeof(int));
    int *output = malloc(n * sizeof(int));
    if (count == NULL || output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // 3. Count occurrences of each value
    for (i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // 4. Compute cumulative counts
    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 5. Build the stable output array
    //    Traverse A from end to start to preserve stability
    for (i = n - 1; i >= 0; i--) {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    // 6. Copy sorted data back into A
    for (i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(count);
    free(output);
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    countingSort(A, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
