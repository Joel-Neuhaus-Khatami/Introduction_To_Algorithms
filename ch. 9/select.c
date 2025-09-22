#include <stdio.h>
#include <stdlib.h>

// Swap A[x] and A[y]
static void swap(int A[], int x, int y) {
    int tmp = A[x];
    A[x]    = A[y];
    A[y]    = tmp;
}

// Insertion‐sort A[from..to] inclusive
static void insertion_sort(int A[], int from, int to) {
    for (int j = from + 1; j <= to; j++) {
        int key = A[j];
        int i   = j - 1;
        while (i >= from && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
    }
}

// Partition A[p..r] around pivot = A[r], return final pivot index
static int partition(int A[], int p, int r) {
    int pivot = A[r];
    int store = p;
    for (int j = p; j < r; j++) {
        if (A[j] < pivot) {
            swap(A, store, j);
            store++;
        }
    }
    swap(A, store, r);
    return store;
}

// Deterministic linear‐time select: find the i-th smallest in A[p..r], 1‐based i
int select(int A[], int p, int r, int i) {
    // 1) Peel off up to 4 smallest so that (r-p+1) ≡ 0 mod 5
    while ((r - p + 1) % 5 != 0) {
        // bubble the minimum of A[p..r] into A[p]
        for (int j = p + 1; j <= r; j++) {
            if (A[p] > A[j]) {
                swap(A, p, j);
            }
        }
        // if we want the minimum, return it
        if (i == 1) {
            return A[p];
        }
        // discard A[p], adjust rank i
        p++;
        i--;
    }

    // 2) Group remaining elements into groups of 5 and sort each
    int n = r - p + 1;
    int g = n / 5;                // number of full 5‐element groups

    for (int group = 0; group < g; group++) {
        int start = p + 5 * group;
        int end   = start + 4;
        insertion_sort(A, start, end);
        // move each group’s median into A[p + group]
        swap(A, p + group, start + 2);
    }

    // 3) Recursively select the median of the g medians
    //    (the “median‐of‐medians” pivot)
    int med_of_med = select(A, p, p + g - 1, (g + 1) / 2);

    // 4) Partition around that pivot value
    //    First find the pivot’s index and swap it to A[r]
    int pi;
    for (pi = p; pi <= r; pi++) {
        if (A[pi] == med_of_med) {
            break;
        }
    }
    swap(A, pi, r);
    int q = partition(A, p, r);

    // 5) Recurse into the one side that contains the i-th smallest
    int k = q - p + 1;
    if (i == k) {
        return A[q];
    } else if (i < k) {
        return select(A, p, q - 1, i);
    } else {
        return select(A, q + 1, r, i - k);
    }
}

// Demo
int main(void) {
    int A[] = {12, 3, 5, 7, 4, 19, 26, 1, 17, 8, 15, 10, 2};
    int n   = sizeof(A) / sizeof(A[0]);

    int i = 6;  // find the 6th smallest element
    if (i < 1 || i > n) {
        fprintf(stderr, "i must be between 1 and %d\n", n);
        return EXIT_FAILURE;
    }

    int result = select(A, 0, n - 1, i);
    printf("The %d-th smallest element is %d\n", i, result);
    return EXIT_SUCCESS;
}
