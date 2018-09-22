/*
    Insertion Sort for N no. of numbers
*/

#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int num){
    int i, j, k, key, pos;

    for(i = 1; i < num; ++i){
        key = arr[i];           //Pick

        for(j = i-1; j > -1 && arr[i] < arr[j]; --j);
        pos = j+1;              //Search Position

        for(k = i; k > pos; --k){
            arr[k] = arr[k-1];   //Shift
        }

        arr[pos] = key;         //Insert
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

    insertion_sort(arr, num);

    output_array(arr, num);

    free(arr);
}