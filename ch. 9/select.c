#include <stdio.h>

int select(int Array[], int p, int r, int i){
    while ((r - p + 1) % 5 != 0){
        for (int j = p+1; j<r; j++){
            if (Array[p] > Array[j]){
                int temporary = Array[p];
                Array[p] = Array[j];
                Array[j] = temporary;
            }
        }
        if (i == 1){
            return Array[p];
        }
        p++;
        i--;
    }
    int g = (r-p+1)/5;
    for (int j = p ; j < p + g -1){
        //Sort here
    }
    int x = select(Array, p + 2*g, p + 3*g -1, g/2);
    // q = partition around the pivot
    int k = q - p + 1;
    if (i == k){
        return Array[q];
    }else if (i < k){
        return select(Array, p, q-1, i);
    }else{
        return select(Array, q + 1, r, i -k);
    }
}