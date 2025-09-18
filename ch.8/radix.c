#include <stdio.h>
#include <stdlib.h>

// Find the maximum value in A[0..n-1]
int getMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Do a counting sort of A[] according to the digit at exp (1, 10, 100, ...)
void countSort(int A[], int n, int exp) {
    int *output = malloc(n * sizeof(int));
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (A[i] / exp) % 10;
        count[digit]++;
    }

    // Convert count[] to cumulative counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array from right to left for stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = (A[i] / exp) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    // Copy sorted elements back into original array
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }

    free(output);
}

// Main radix sort routine using base-10 digits
void radixSort(int A[], int n) {
    int max = getMax(A, n);

    // Do counting sort for each digit exponent
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(A, n, exp);
    }
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    radixSort(A, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
