#include <stdio.h>
#include <stdlib.h>


void merge(int A[], int p, int q, int r){
    int n_l = q - p + 1;
    int n_r = r - q;

    int* L = (int*)malloc(n_l * sizeof(int));
    int* R = (int*)malloc(n_r * sizeof(int));

    if (L == NULL || R == NULL) {
        // Handle allocation failure
        return;
    }

    for (int i = 0; i <= n_l -1; i ++){
        L[i] = A[p + i];
    }
    for (int j = 0; j <= n_r-1; j++){
        R[j] = A[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < n_l && j < n_r){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i += 1;
        }else{
            A[k] = R[j];
            j += 1;
        }
        k +=1;
    }

    while (i < n_l){
        A[k] = L[i];
        i += 1;
        k += 1;
    }

    while (j < n_r){
        A[k] = R[j];
        j += 1;
        k += 1;
    }

    
    free(L);
    free(R);
}

void merge_sort(int A[], int p, int r){
    if (p >= r){
        return;
    }
    int q = (p+r)/2;
    merge_sort(A, p , q);
    merge_sort(A, q + 1, r);

    merge(A, p, q, r);

}

int main() {
    int A[] = {5, 2, 4, 7, 1, 3, 2, 6};
    int n = sizeof(A) / sizeof(A[0]);

    merge_sort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}
