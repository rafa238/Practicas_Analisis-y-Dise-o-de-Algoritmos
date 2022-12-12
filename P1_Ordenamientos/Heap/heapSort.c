#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tiempo.h"
#include "Heap.h"

void heapSort(int A[], int n){
    HEAP heap = buildHeap(n);
    for (int i = 0; i < n; ++i){
        push(heap, A[i]);
    }
    for(int i=0; i < n; i++){
        A[i] = pop(heap);
    }
}

void printArray(int array[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int n=11;
    int A[] = { 1000, 1 ,22 ,3, 44,5 ,6,7,8,9,10};
    heapSort(A, n);
    printArray(A, n);
    return 0;
}
/*
int main(int narg, char **varg){
    //gcc Heap.c Heap.h heapSort.c tiempo.c -o heap
    //Variables que ocupara por nuestro algoritmo
    int n, *numeros;

    //Declaracion de las variables para medir el tiempo
    double utime0, stime0, wtime0, utime1, stime1, wtime1;

    //Lectura del argumento de entrada para n
    if (narg != 2)
    {
        exit(1);
    }
    n = atoi(varg[1]);

    //Reserva de memoria dinamica
    numeros = malloc(sizeof(int) * (n));

    if (numeros == NULL)
    {
        exit(1);
    }

    //Leer numeros
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numeros[i]);
    }

    //Inicio de conteo
    uswtime(&utime0, &stime0, &wtime0);
    //Algoritmo de ordenamiento por Monticulo (Heap)
    heapSort(numeros, n);

    uswtime(&utime1, &stime1, &wtime1);
    //Evaluar los tiempos de ejecucion

    //Cálculo del tiempo de ejecución del programa
    printf("%d---------------------------------------------------------------------------------", n);
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    //Terminar programa normalmente
    
    exit(0);
}*/