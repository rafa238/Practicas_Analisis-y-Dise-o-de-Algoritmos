#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

//incializa los elementos y reservamos la memoria que va a ocupar la heap
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
    int l = 2 * i + 1; //hijo izquierdo
    int r = 2 * i + 2; //hijo derecho
    //comparamos si el hijo izquierdo o derecho es mas grande
    if (l < size && h->heaparray[l] > h->heaparray[largest]){
        
        largest = l;
    }
    if (r < size && h->heaparray[r] > h->heaparray[largest]){
        largest = r;
    }
    //si el hijo izquierdo o derecho es mas grande, hacemos un swap
    if (largest != i){
        swap(&h->heaparray[i], &h->heaparray[largest]);
        heapify(h, largest); // reacomodamos
    }
}

void push(HEAP h, int newElem){
    //si nuestra heap no tiene elementos, ponemos el nuevo elemento al principio
    if (h->size == 0){
        h->heaparray[0] = newElem;
        h->size += 1;
    }else{
        h->heaparray[h->size] = newElem; // ponemos el nuevo elemento al final
        h->size += 1; //aumentamos el tamaño de ñla heap
        for (int i = h->size/2 - 1; i >= 0; i--){ //reacomodamos de nuevo para que el maximo este al principio
            heapify(h, i);
        }
    }
}

int pop(HEAP h){
    int root = h->heaparray[0]; //obtenemos el primero de la lista (mas grande)
    swap(&h->heaparray[0], &h->heaparray[h->size - 1]); //hacemos un swap del ultimo con el primero
    h->size -= 1; //disminuimos el tamaño de la heap para quitar el elemento anterior
    for (int i = h->size / 2 - 1; i >= 0; i--){ //volvemos a ordenar la heap
        heapify(h, i);
    }
    return root;
}

//liberamos la memoria de la heap
void freeHeap(HEAP h) {
    free(h->heaparray);     
    free(h);
}

//cambiamos dos elementos de posicion
void swap(int *a, int *b){
  int temp = *b;
  *b = *a;
  *a = temp;
}
