#include <stdio.h>

//Reversed insertion sort

void insertion_sort(int arr[], int n){
    int i, key, j;
    for (i = n-1; i > 0 ; i--){
        key = arr[i-1];
        j = i;
        while (j<=n-1 && arr[j] > key){
            arr[j-1] = arr[j];
            j = j+1;
        }
        arr[j-1] = key;
    }
}

void print_array(int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void){
    int arr1[] = {5, 6, 11, 12, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    print_array(arr1, n);
    insertion_sort(arr1, n);
    print_array(arr1, n);

    int arr2[20] = {
    42, 87, 13, 65, 99,
    24, 56, 71, 8, 33,
    77, 4, 90, 18, 61,
    29, 53, 12, 84, 6
    };

    n = sizeof(arr2) / sizeof(arr2[0]);
    print_array(arr2, n);
    insertion_sort(arr2, n);
    print_array(arr2, n);
}