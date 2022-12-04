#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/resource.h>
#include "tiempo.h"
#include <math.h>
#define min

//declaramos la estructura que va a llevar la informacion a los hilos
typedef struct{
    int target; //el numero a buscar
    int tam;    //tamaño del arreglo partido
    int *arr;   // arreglo
    int noThread;//numero de hilo
} Data;

int binarySearch(int arr[], int, int, int);
  
/*
* Esta funcion se encarga de delimitar el rango de manera exponencial, hasta que encuentra 
* un numero mayor a nuestro target y posteriormente hace una busqueda binaria en dicho rango
* ya delimitado
*/
int exponentialSearch(int arr[], int n, int x){
    // primero tomamos en cuenta el caso especial en el que nuestro target 
    // este en el primer elemento
    if (arr[0] == x)
        return 0;
  
    // Encontramos un rango de manera exponencial
    // en base 2 => 2 a la x
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
  
    //  Hacemos una busqueda binaria una vez que encontramos el rango
    return binarySearch(arr, i/2, min(i, n-1), x);
}
  
/*
* Esta funcion se encarga de hacer una busqueda binaria recursiva
*/
int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l)/2;
  
        // Condicional que verifica si nuestro target esta en la mitad
        if (arr[mid] == x)
            return mid;

        // Si el elemento de enmedio es menor, entonces buscamos en la izquierda
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
  
        // De otra manera bucamos en la derecha del rango
        return binarySearch(arr, mid+1, r, x);
    }
  
    // Si el elemento no se encuentra en el arreglo entonces retornamos -1
    return -1;
}

void* ESthread(void* tdata){
    Data *elems = (Data*)tdata;
    
    int res = exponentialSearch(elems->arr,  elems->tam, elems->target);
    printf("\nThread no %d has found %d at the index: %d \n",elems->noThread, elems->target,res);
}

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    int n, target, *A, *B;                                //Variables auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medicion de tiempos.

    //Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3)
    {
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }

    target = atoi(varg[1]); //ELEMENTO A BUSCAR
    n = atoi(varg[2]);   //TAMAÃ‘O DEL PROBLEMA

    //Reservar memoria
    int middle = n/2;
    A = malloc(sizeof(int) * middle);
    B = malloc(sizeof(int) * n-middle);
    Data *dt1 = (Data*) malloc(sizeof(Data));
    Data *dt2 = (Data*) malloc(sizeof(Data));
    if(dt1 == NULL || dt2 == NULL){
        printf("NO hay memoria");
    }
    
    dt1->target = dt2->target = target;
    dt1->noThread = 1;
    dt2->noThread = 2;
    dt1->tam = middle; 
    dt2->tam = n-middle;

    //ciclo para asignar las entradas
    for (int i = 0, j=0; i < n; i++){
        if(middle!=0){
            scanf("%d", &A[i]);
            //printf("%d ", A[i]);
            middle--;
        } else {
            scanf("%d", &B[j]);
            //printf("%d ", B[j]);
            j++;
        }
    }
    dt1->arr = A;
    dt2->arr = B;

    //inicializamos los hilos a ejecutar
    pthread_t proceso1, proceso2;
    pthread_create(&proceso1, NULL, &ESthread, dt1);
    pthread_create(&proceso2, NULL, &ESthread, dt2);

    //******************************************************************
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    //******************************************************************
    //Evaluar los tiempos de ejecucion
    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    printf("---------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------------------------------");

    //CÃ¡lculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("\n");
    //******************************************************************
    //Terminar programa normalmente
    exit(0);
}