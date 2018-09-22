/*
    Quick Sort for N no. of numbers
*/

#include <stdio.h>
#include <stdlib.h>

// void swap(int *a, int *b){
//     *a += *b;
//     *b = *a - *b;
//     *a -= *b;
// }

int partition(int *arr, int p, int r){
    int x = arr[r], i = p - 1, j;

    for(j = p; j < r; j++){
        if(arr[j] <= x){
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;

    return i+1;
}

void quick_sort(int *arr, int p, int r){
    if(p < r){
        int q = partition(arr, p, r);
        quick_sort(arr, p, q-1);
        quick_sort(arr, q+1, r);
    }
}

void input_array(int *arr, int num){
    int i;

    for(i = 0; i < num; i++){
        printf("\nEnter Number[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void output_array(int *arr, int num){
    int i;

    printf("\nSorted : \n");

    for(i = 0; i < num; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void main(){
    int arr[20], num;

    printf("\nEnter Length Of Nos. To be Sorted : ");
    scanf("%d", &num);

    input_array(arr, num);

    quick_sort(arr, 0, num-1);

    output_array(arr,num);
}