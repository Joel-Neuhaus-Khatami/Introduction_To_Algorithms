#include <stdio.h>
#include <stdlib.h>

void merge_sort(int A[], int p, int r);


int find_num(int arr[], int n, int x){
    merge_sort(arr, 0, n-1);
    
    int low = 0;
    int high = n-1;
    int i = 0;

    while (low < high){
        i += 1;
        int sum = arr[low] + arr[high];
        if (sum == x){
            printf("%d at index %d + %d at index %d = %d\n", arr[low], low, arr[high], high, x);
            printf("Number of iterations: %d\n", i);
            return 1;
        }else if(sum < x){
            low ++;
        }else{
            high --;
        }
    }
    printf("Number of iterations: %d\n", i);
    return -1;
}


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
    // Test Case 1: Basic Match
    int arr1[] = {7, 1, 5, 3, 9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 10;
    printf("Test Case 1:\n");
    if (find_num(arr1, n1, x1) == -1) {
        printf("No pair found.\n");
    }
    printf("\n");

    // Test Case 2: Single Element
    int arr2[] = {42};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int x2 = 84;
    printf("Test Case 2:\n");
    if (find_num(arr2, n2, x2) == -1) {
        printf("No pair found.\n");
    }
    printf("\n");

    // Test Case 3: Zero Sum
    int arr3[] = {-5, -3, 0, 3, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int x3 = 0;
    printf("Test Case 3:\n");
    if (find_num(arr3, n3, x3) == -1) {
        printf("No pair found.\n");
    }
    printf("\n");

    // Test Case 4: Large Array
    int arr4[1001];
    for (int i = 0; i <= 1000; i++) arr4[i] = i;
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int x4 = 1999;
    printf("Test Case 4:\n");
    if (find_num(arr4, n4, x4) == -1) {
        printf("No pair found.\n");
    }
    printf("\n");

    return 0;
}
