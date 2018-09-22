#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int length, heapSize;

int left(int i){
    return 2*i;
}

int right(int i){
    return 2*i+1;
}

void input_array(int *arr){
    int i;

    printf("\n");

    for(i = 0; i < length; i++){
        printf("Enter Number[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void output_array(int *arr){
    int i;

    printf("\nSorted : \n");

    for(i = 0; i < length; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void maxHeapify(int *arr, int i){
    int l = left(i);
    int r = right(i), largest = i;

    if(l <= heapSize && arr[l] > arr[i]){
        largest = l;
    }

    if(r <= heapSize && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        arr[i] += arr[largest];
        arr[largest] = arr[i] - arr[largest];
        arr[i] -= arr[largest];

        maxHeapify(arr, largest);
    }
}

void buildMaxHeap(int *arr){
    int heapSize = length, i;

    for(i = length/2; i > 0; --i){
        maxHeapify(arr, i);
    }
}

void heapSort(int *arr){
    int i;
    
    buildMaxHeap(arr);

    for(i = length; i >= 1; --i){
        arr[0] += arr[i];
        arr[0] = arr[1] - arr[i];
        arr[0] -= arr[i];

        --heapSize;

        maxHeapify(arr, i);
    }
}

void main(){
    int *arr;

    printf("\nEnter Length Of Heap : ");
    scanf("%d", &length);

    arr = (int *) malloc(length * sizeof(int));

    input_array(arr);

    heapSort(arr);

    output_array(arr);

    free(arr);
}