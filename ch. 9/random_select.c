#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two elements in the array
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Partition A[p..r] around pivot A[r], return pivot index
int partition(int A[], int p, int r) {
    int pivot = A[r];
    int store = p;
    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            swap(&A[store], &A[j]);
            store++;
        }
    }
    swap(&A[store], &A[r]);
    return store;
}

// Return a random index between p and r (inclusive)
int randomized_index(int p, int r) {
    return p + rand() % (r - p + 1);
}

// Quickselect: find the i-th smallest element in A[p..r]
int randomized_select(int A[], int p, int r, int i) {
    if (p == r) {
        return A[p];
    }
    int rand_idx = randomized_index(p, r);
    swap(&A[rand_idx], &A[r]);
    int pivotIndex = partition(A, p, r);
    int k = pivotIndex - p + 1; // rank of pivot within A[p..r]
    if (i == k) {
        return A[pivotIndex];
    } else if (i < k) {
        return randomized_select(A, p, pivotIndex - 1, i);
    } else {
        return randomized_select(A, pivotIndex + 1, r, i - k);
    }
}

int main() {
    // Example array
    int A[] = {7, 2, 9, 4, 3, 1, 8, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);
    
    // Seed the random number generator
    srand((unsigned)time(NULL));
    
    // Choose the order statistic
    int i = 3; // We want the 3rd smallest element
    if (i < 1 || i > n) {
        printf("Order statistic i must be between 1 and %d\n", n);
        return 1;
    }
    
    // Copy the array if you want to preserve the original
    int B[n];
    for (int idx = 0; idx < n; ++idx) {
        B[idx] = A[idx];
    }

    int result = randomized_select(B, 0, n - 1, i);
    printf("The %d-th smallest element is %d\n", i, result);
    return 0;
}
