#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "Heap.h"
typedef long long ll;


//struct que guarda la informacion que necesitamos para escribir el archivo
struct File{
    char* buffer;
    ll size;
};

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
        printf("%d", f.buffer[i]);
    }*/

    fclose(file);
    return f;
}
/*
char* decode_file(HEAPNODE root, ){
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

struct File readFile(){
    struct File codificado = readBFile("fichero_copy.dat");
    for(int i=0; i<codificado.size; i++){
        printf("%d", codificado.buffer[i]);
    }
    return codificado;
    //return 0;
}
//010111101110100100000011100101011110111011000