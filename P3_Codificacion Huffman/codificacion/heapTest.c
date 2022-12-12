#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Heap.h"

void heapSort(HEAPNODE A[], int n){
    HEAP heap = buildHeap(n);
    for (int i = 0; i < n; ++i){
        printf("%c", A[i]->data);
        push(heap, A[i]);
    }
    for(int i=0; i < n; i++){
        A[i] = pop(heap);
    }
}

void printArray(HEAPNODE array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%c : %d ", (char)array[i]->data, array[i]->freq);
    }
    printf("\n");
}

int main(){
    int n=3;
    HEAPNODE A[3];
    A[0] = createNode('p', 100); 
    A[1] = createNode('b', 1);
    A[2] = createNode('z', 22);
    heapSort(A, n);
    printArray(A, n);
    return 0;
}