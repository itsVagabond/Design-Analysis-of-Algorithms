/*
    Selection Sort for N no. of numbers
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    *a += *b;
    *b = *a - *b;
    *a -= *b; 
}

void selection_sort(int *arr, int num){
    int i, j;

    for(i = 0; i < num-1; i++){
        for(j = i + 1; j < num; j++){
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
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
    int *arr, num;

    printf("\nEnter No. Of Nos. To be Sorted : ");
    scanf("%d", &num);

    arr = (int *) malloc(num * sizeof(int));

    input_array(arr, num);

    selection_sort(arr, num);

    output_array(arr, num);

    free(arr);
}