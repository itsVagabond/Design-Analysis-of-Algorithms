#include <stdio.h>
#include <stdlib.h>

#define left(i) 2*i
#define right(i) 2*i+1


void input_array(int *arr, int num){
    int i;

    printf("\n");

    for(i = 0; i < num; i++){
        printf("Enter Number[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void maxHeapify(int *arr, int i, int num){
    int l = left(i);
    int r = right(i), largest;

    if(l <= num && arr[l] > arr[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= num && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = arr[i];
        maxHeapify(arr, largest, num);
    }
}

void buildMaxHeap(int *arr, int num){
    int heapSize = num, i;

    for(i = num/2; i > 0; --i){
        maxHeapify(arr, i, heapSize);
    }
}

void output_array(int *arr, int num){
    int i;

    printf("\nHeapified : \n");

    for(i = 0; i < num; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void main(){
    int *arr, num;

    printf("\nEnter Length Of Heap : ");
    scanf("%d", &num);

    arr = (int *) malloc(num * sizeof(int));

    input_array(arr, num);

    buildMaxHeap(arr, num);

    output_array(arr, num);

    free(arr);
}