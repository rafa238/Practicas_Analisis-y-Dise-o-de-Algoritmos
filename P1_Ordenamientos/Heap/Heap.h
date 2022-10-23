typedef struct{
    int size;
    int capacity;
    int* heaparray;
} Heap;

typedef Heap* HEAP;

HEAP buildHeap(int);
void swap(int *, int *);
void heapify(HEAP, int);
void push(HEAP, int);
int pop(HEAP);
void freeHeap(HEAP);