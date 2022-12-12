// gcc Heap.c main.c -o  main.exe
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include "HuffmanTree.c"
#include "Heap.h"

typedef long long ll;

//struct que guarda la informacion que necesitamos para escribir el archivo
struct File{
    char* buffer;
    ll size;
};

//this struct store pairs (key, value) for frequency
struct map{
    char key;
    ll value;
};
typedef struct map* MAP;

ll tam;
ll **letters;
ll *lettersSize;

struct File readBFile(char *fileName){
    struct File f;
    struct stat sb;
    FILE *file;
    char *buffer;

    //obtenemos el tamaño del archivo a leer
    if (stat(fileName, &sb) == -1) {
        perror("Fallo al recibir el status del archivo \n");
        exit(EXIT_FAILURE);
    }
    printf("Tamano total del archivo: %lu bytes\n", sb.st_size);

    //reservamos la memoria para el buffer
    buffer = malloc(sizeof(char)*sb.st_size);

    // abrimos los archivos
    file = fopen(fileName, "rb");
    if( file == NULL){
        perror("No se pudo abrir el archivo :(\n");
        exit(EXIT_FAILURE);
    }

    //leemos los bytes del archivo 1 y escribhimos en el archivo 2 el contenido del buffer
    ll read = fread (buffer, 1, sb.st_size, file);
    f.buffer = buffer;
    f.size = read;
    /*for(int i=0; i<read; i++){
        printf("%d ", f.buffer[i]);
    }*/
    fclose(file);
    return f;
}

void writeBFile(struct File f){
    //abrimos el archivo que vamos a escribir
    FILE *file2;
    file2 = fopen ("fichero_copy.dat", "wb");
    if (file2==NULL){
        perror("No se puede abrir fichero2.dat");
        exit(EXIT_FAILURE);
    }
    //escribimos el buffer
    fwrite (f.buffer, 1, f.size, file2);
    fclose(file2);
}

/*
*   Get each node from heap and assign their children
*/
HEAPNODE createTree(HEAP heap){
    while(heap->size != 1){
        HEAPNODE left = pop(heap);
        HEAPNODE right = pop(heap);
        HEAPNODE top = createEmptyNode();
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        push(heap, top);
    }
    HEAPNODE ans = pop(heap);
    return ans;
}

void printArr(ll *arr, int n){
    for (int i = 0; i < n; ++i)
        printf("%lld", arr[i]);
 
    printf("\n");
}

/*
* Assign the code to each node of the tree
*/
void getCode(HEAPNODE root, ll *arr, int top){
    if (root->left) {
        //assign a zero value to left child
        arr[top] = 0;
        getCode(root->left, arr, top + 1);
    }
    if (root->right) {
        //assign a one value to right child
        arr[top] = 1;
        getCode(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        ll *narr = malloc(sizeof(ll)*256);
        memcpy(narr, arr, sizeof(ll)*256);
        letters[(int)root->data] = narr;
        lettersSize[(int)root->data] = top;
        printArr(letters[root->data], lettersSize[root->data]);
    }
}

/*
* Return a map array with all the file frequency
*/
MAP getFreq(struct File file){
    //build frequency
    char *text = file.buffer;
    //initialize frequency vector
    ll *freq; 
    freq = (ll*)malloc(sizeof(ll)*256);
    ll num = -1; 
    memset(freq, num, 256*sizeof(ll));

    // store frequency in a vector
    for(ll i=0; i < file.size; i++){
        ll character = text[i];
        if(freq[character] == -1) {
            freq[character] = 0;
            tam++;
        }
        freq[character]++;
    }
    /*for(int i=0; i<256; i++){
        printf("%c : %d\n", (char)i, freq[i]);
    }
    printf("\n");*/
    // make an map structs array and 
    MAP frequecyMap = (MAP) malloc(sizeof(struct map) * tam);
    for(ll i=0, j=0; i < 256; i++){
        if(freq[i] != -1){
            struct map elem;
            elem.key = (char)i;
            elem.value = freq[i];
            frequecyMap[j++] = elem; 
        }
    }
    
    free(freq);
    return frequecyMap;
}

HEAP fillHeap(MAP freq){
    HEAP heap = buildHeap(tam);
    for(int i=0; i<tam; i++){
        struct map current = freq[i];
        //printf("%c : %lld\n", (char)current.key, current.value);
        HEAPNODE node = createNode(current.key, current.value);
        push(heap, node);
    }
    return heap;
}

/*char* decode_file(HEAPNODE root, struct File f){
    char* ans = "";
    HEAPNODE curr = root;
    for (int i = 0; i < tam; i++) {
        if (s[i] == '0')
            curr = curr->left;
        else
            curr = curr->right;
 
        if (!(root->left) && !(root->right)) {
            ans += curr->data;
            curr = root;
        }
    }
    // cout<<ans<<endl;
    return ans + '\0';
}*/


int main(int argc, char *argv[]){
    struct File f = readBFile("test.txt");
    //writeBFile(f);
    letters = (ll**)malloc(sizeof(ll)*256);
    lettersSize = (ll*)malloc(sizeof(ll)*256);
    MAP freq = getFreq(f);
    //printf("%lld ", tam);
    /*for(int i=0; i<tam; i++){
        printf("%nBuffer += 
        mc : %lld\n", (char)freq[i].key, freq[i].value);
    }*/
    HEAP heap = fillHeap(freq);
    HEAPNODE root = createTree(heap);
    ll *arr = (ll*)malloc(sizeof(ll)*256);
    char *nBuffer = (char*)malloc(sizeof(char)*f.size);
    ll nBufferSize = 0;

    getCode(root, arr, 0);
    printf("\n");
    struct File file2;
    for(ll i=0; i<f.size; i++){
        char letter = f.buffer[i];
        ll tam = lettersSize[(int)letter];
        ll *arr = letters[(int)letter];
        for (int j = 0; j < tam; j++){
            nBuffer[nBufferSize++] = arr[j];
            printf("%lld", nBuffer[nBufferSize-1]);
        }
    }
    file2.buffer = nBuffer;
    file2.size = nBufferSize;
    writeBFile(file2);
    /*
    * decodificacion
    */
    
    //printf("\n --------Archivo codificado----------\n");
    //struct File codificado = readBFile("fichero_copy.dat");
    /*for(ll i=0; i<codificado.size; i++){
        printf("%d" , codificado.buffer[i]);
    }*/
    /*for(int i=0; i < tam; i++){
        HEAPNODE node = pop(heap);
        printf("%c : %lld \n", (char)node->data, node->freq);
    }*/
    return EXIT_SUCCESS;
}


//escritura por bloques
/*while (leidos!=0){
    // ... meterlo en el fichero destino
    fwrite (buffer, 1, leidos, file2);
    // y leer siguiente bloque
    printf("leidos %d\n", leidos);
    leidos = fread (buffer, 1,  sb.st_size, file);
    printf("leidos %d\n", leidos);
}*/