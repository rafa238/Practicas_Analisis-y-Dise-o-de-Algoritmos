#include <stdio.h>
#include <stdlib.h>

void readBFile(){
    FILE *file;
    file = fopen("test.txt", "rb");
    if(file == NULL){
        perror("No se pudo abrir el archivo :(\n");
        exit(0);
    }
    printf("%d", file->_bufsiz);
}

void writeBFile(){
    FILE *file;
    file = fopen("test2.dat", "wb");
    if(file == NULL){
        perror("No se pudo crear el archivo :(\n");
        exit(0);
    }
}

int main(){
    readBFile();
    return 0;
}