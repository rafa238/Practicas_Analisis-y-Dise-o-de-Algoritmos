#include<stdio.h>
#include<stdlib.h>
typedef int* Heap;

int size = 0;

void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(Heap h, int size, int i){
    if (size != 1){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && h[l] > h[largest]){
            largest = l;
        }
        if (r < size && h[r] > h[largest]){
            largest = r;
        }
        if (largest != i){
            swap(&h[i], &h[largest]);
            heapify(h, size, largest);
        }
    }
}

void insert(Heap h, int nuevo){
    if (size == 0){
        h[0] = nuevo;
        size += 1;
    }else{
        h[size] = nuevo;
        size += 1;
        for (int i = size/2 - 1; i >= 0; i--){
            heapify(h, size, i);
        }
    }
}

int delete(Heap h){
    int root = h[0];
    swap(&h[0], &h[size - 1]);
    size -= 1;
    for (int i = size / 2 - 1; i >= 0; i--){
        heapify(h, size, i);
    }
    return root;
}

Heap buildHeap(int size){
    Heap h = malloc(sizeof(int)*size);
    if(h == NULL) {
        printf("No hay suficiente memoria...");
        exit(0);
    }
    return h;
}

void heapSort(int A[], int n){
    Heap h = buildHeap(n);
    for (int i = 0; i < n; ++i){
        insert(h, A[i]);
    }
    for(int i=0; i < n-1; i++){
        A[i] = delete(h);
    }
}


void printArray(int array[], int size){
    for (int i = 0; i < size; ++i) printf("%d ", array[i]);
    printf("\n");
}


int main(){
    int n=6;
    int A[] = { 6, 4, 7, 1, 9, -2, 6, 4, 7, 1, 9, -2,6, 4, 7, 1, 9, -2 };
    heapSort(A, 18);
    printArray(A, 18);
    return 0;
}