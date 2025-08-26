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

    int arr3[50]= {
        83, 12, 47, 91, 3, 68, 
        29, 76, 55, 34, 7, 96, 
        18, 41, 62, 25, 88, 10, 
        39, 74, 1, 99, 21, 60, 45, 
        6, 80, 14, 36, 93, 27, 52, 
        19, 70, 31, 85, 9, 66, 23,
        58, 43, 98, 16, 64, 37, 5, 
        50, 86, 32, 72
    };
    n = sizeof(arr3) / sizeof(arr3[0]);
    print_array(arr3, n);
    insertion_sort(arr3, n);
    print_array(arr3, n);
}