#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

HEAP buildHeap(int size){
    HEAP h = (HEAP)malloc(sizeof(Heap));
    if(h == NULL) {
        printf("No hay suficiente memoria...");
        exit(0);
    }
    h->capacity = size;
    h->heaparray = (int*)malloc(sizeof(int)*(size+1));
    h->size = 0;
    return h;
}

void heapify(HEAP h, int i){
    int size = h->size;
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    //printf("%d %d\n", h->heaparray[0], h->heaparray[1]);
    if (l < size && h->heaparray[l] > h->heaparray[largest]){
        
        largest = l;
    }
    if (r < size && h->heaparray[r] > h->heaparray[largest]){
        largest = r;
    }
    if (largest != i){
        swap(&h->heaparray[i], &h->heaparray[largest]);
        heapify(h, largest);
    }
}

void push(HEAP h, int newElem){
    if (h->size == 0){
        h->heaparray[0] = newElem;
        h->size += 1;
    }else{
        h->heaparray[h->size] = newElem;
        h->size += 1;
        for (int i = h->size/2 - 1; i >= 0; i--){
            heapify(h, i);
        }
    }
}

int pop(HEAP h){
    int root = h->heaparray[0];
    swap(&h->heaparray[0], &h->heaparray[h->size - 1]);
    h->size -= 1;
    for (int i = h->size / 2 - 1; i >= 0; i--){
        heapify(h, i);
    }
    return root;
}

void freeHeap(HEAP h) {
    free(h->heaparray);     
    free(h);
}

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}
