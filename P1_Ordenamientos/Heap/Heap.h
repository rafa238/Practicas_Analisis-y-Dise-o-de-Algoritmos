typedef struct{
    int size; //tamaño actual de nuestro arreglo
    int capacity; //numero de elementos
    int* heaparray; //arreglo
} Heap;

typedef Heap* HEAP;

HEAP buildHeap(int); //construye la heap
void freeHeap(HEAP);
void swap(int *, int *);
void heapify(HEAP, int);
void push(HEAP, int);
int pop(HEAP);
