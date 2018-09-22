/*
    ? Sort for N no. of numbers
*/

#include <stdio.h>
#include <stdlib.h>

void ?_sort(int *arr, int num){
    
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

    printf("\nEnter Length Of Nos. To be Sorted : ");
    scanf("%d", &num);

    arr = (int *) malloc(num * sizeof(int));

    input_array(arr, num);

    ?_sort(arr, num);

    output_array(arr, num);

    free(arr);
}