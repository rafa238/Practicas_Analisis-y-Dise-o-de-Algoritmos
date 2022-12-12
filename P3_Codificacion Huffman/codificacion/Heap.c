#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

//Crea el nodo de la heap
HEAPNODE createNode(char data, ll freq){
    HEAPNODE node = (HEAPNODE)malloc(sizeof(HeapNode));
    if(node == NULL) {
        printf("No hay suficiente memoria...");
        exit(0);
    }
    node->data = data;
    node->freq = freq;
    return node;
}

HEAPNODE createEmptyNode(){
    HEAPNODE node = (HEAPNODE)malloc(sizeof(HeapNode));
    if(node == NULL) {
        printf("No hay suficiente memoria...");
        exit(0);
    }
    node->freq = 0;
    return node;
}

//incializa los elementos y reservamos la memoria que va a ocupar la heap
HEAP buildHeap(int size){
    HEAP h = (HEAP)malloc(sizeof(Heap));
    if(h == NULL) {
        printf("No hay suficiente memoria...");
        exit(0);
    }
    h->capacity = size;
    h->heaparray = (HeapNode**)malloc(sizeof(HeapNode)*(size));
    h->size = 0;
    return h;
}


/*
    Funcion heapify que se encarga de comparar un nodo padre con sus hijo izquierdos y derechos
    para poder hacer el swap en caso de asi lo requiera
*/
void heapify(HEAP h, int i){
    int size = h->size;
    int largest = i;
    int l = 2 * i + 1; //hijo izquierdo
    int r = 2 * i + 2; //hijo derecho
    //comparamos si el hijo izquierdo o derecho es mas grande
    if (l < size && h->heaparray[l]->freq < h->heaparray[largest]->freq){

        largest = l;
    }
    if (r < size && h->heaparray[r]->freq < h->heaparray[largest]->freq){
        largest = r;
    }
    //si el hijo izquierdo o derecho es mas grande, hacemos un swap
    if (largest != i){
        swap(&h->heaparray[i], &h->heaparray[largest]);
        heapify(h, largest); // reacomodamos
    }
}

/*
Se encarga de agregar elementos a nuestra estructura de datos y hacer los cambio que se requieran
*/
void push(HEAP h, HEAPNODE newElem){
    //si nuestra heap no tiene elementos, ponemos el nuevo elemento al principio
    if (h->size == 0){
        h->heaparray[0] = newElem;
        h->size += 1;
    }else{
        //printf("%c",(char) newElem->data);
        h->heaparray[h->size] = newElem; // ponemos el nuevo elemento al final
        h->size += 1; //aumentamos el tamaño de la heap
        for (int i = h->size/2 - 1; i >= 0; i--){ //reacomodamos de nuevo para que el maximo este al principio
            heapify(h, i);
        }
    }
}

/*
Se encarga de eliminar el elemento raiz de nuestro heap para obtener el minimo/maximo elemento
de nuestro Arreglo
*/
HEAPNODE pop(HEAP h){
    HEAPNODE root = h->heaparray[0]; //obtenemos el primero de la lista (mas grande)
    swap(&h->heaparray[0], &h->heaparray[h->size - 1]); //hacemos un swap del ultimo con el primero
    h->size -= 1; //disminuimos el tamaño de la heap para quitar el elemento anterior
    /*for (int i = h->size / 2 - 1; i >= 0; i--){ //volvemos a ordenar la heap
        heapify(h, i);
    }*/
    heapify(h, 0);
    return root;
}

//liberamos la memoria de la heap
void freeHeap(HEAP h) {
    free(h->heaparray);     
    free(h);
}

//cambiamos dos elementos de posicion
void swap(HEAPNODE *a, HEAPNODE *b){
  HEAPNODE temp = *a;
  *a = *b;
  *b = temp;
}
