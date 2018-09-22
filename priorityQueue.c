#include<stdio.h>
#include<stdlib.h>

int *arr, heapsize;

int PARENT(int i){
    if(i % 2 == 0){
        return i/2;
    }

    return (i-1)/2;
}

void EXCHANGE(int *a, int *b){
    int temp;
 
    temp = *b;
    *b = *a;
    *a = temp;
}

int HEAP_MAXIMUM(){
    return arr[0];
}

void MAX_HEAPIFY(int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    if(left < heapsize && arr[left] > arr[i]){
        largest = left;
    }
         
    if(right < heapsize && arr[right] > arr[largest]){
        largest = right;
    }
        
    if(largest != i ){
        EXCHANGE(&arr[i] , &arr[largest]);
        MAX_HEAPIFY(largest);
    }
}

void OUTPUT_ARRAY(){
    int i;

    printf("\nSorted : \n");

    for(i = 0; i < heapsize; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\n");
}

void HEAP_EXTRACT_MAX(){
    int max;

    if(heapsize < 0){
        printf("\nError : Heap Intraflow");
    }

    max = arr[0];

    arr[0] = arr[heapsize-1];

    --heapsize;

    MAX_HEAPIFY(0);

    OUTPUT_ARRAY();
}

void HEAP_INCREASE_KEY(int i, int key){
    if(key < arr[i]){
        printf("\nError : New Key is Smaller than Current Key");
    }

    arr[i] = key;

    while(i < 0 && arr[PARENT(i)] < arr[i]){
        EXCHANGE(&arr[i], &arr[PARENT(i)]);
        i = PARENT(i);
    }
}

void INPUT_ARRAY(){
    int i;

    printf("\n");
    for(i = 0; i < heapsize; i++){
        printf("Enter Number[%d] : ", i+1);
        scanf("%d", &arr[i]);
    }
}

void main(){
    printf("\nEnter Length of Heap : ");
    scanf("%d", &heapsize);

    arr = (int *)malloc(heapsize * sizeof(int));

    INPUT_ARRAY();

    printf("\n HEAP_MAXIMUM : %d",HEAP_MAXIMUM());
    printf("\n HEAP_EXTRACT_MAX : "); HEAP_EXTRACT_MAX();
    //HEAP_INCREASE_KEY();

    printf("\n\n");
}