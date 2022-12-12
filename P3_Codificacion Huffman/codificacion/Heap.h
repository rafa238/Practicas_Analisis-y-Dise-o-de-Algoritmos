typedef long long ll;

typedef struct HeapNode {
    char data; //byte que contiene el nodo
    ll freq; //frecuencia con la que se repite el nodo
    struct HeapNode *left;
    struct HeapNode *right;
} HeapNode;
typedef HeapNode* HEAPNODE;

typedef struct{
    int size; //tamaño actual de nuestro arreglo
    int capacity; //numero de elementos
    HeapNode** heaparray; //arreglo
} Heap;
typedef Heap* HEAP;

HEAP buildHeap(int); //construye la heap
void freeHeap(HEAP);
void swap(HEAPNODE*, HEAPNODE*);
void heapify(HEAP, int);
void push(HEAP, HEAPNODE);
HEAPNODE pop(HEAP);
HEAPNODE createEmptyNode();
HEAPNODE createNode(char data, ll freq);
