/*
    Quick Sort for N no. of numbers
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

int randomizedPartition(int *arr, int p, int r){
    int x = arr[r], i , j;

    for(j = p; j < r; j++){
        if(arr[j] <= x){
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);

    return i+1;
}

void randomizedQuickSort(int *arr, int p, int r){
    if(p < r){
        int q = randomizedPartition(arr, p, r);
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