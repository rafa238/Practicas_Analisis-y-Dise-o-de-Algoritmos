#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "tiempo.h"

//Estructura que va a llevar la informacion a los hilos
typedef struct{
    int target;
    int tam;
    int *arr;
    int noThread;
} Data;
// Helper que devuelve el minimo de 2 elementos
int min(int x, int y) { return (x <= y) ? x : y; }
 
/*
* 1- Realiza la busqueda del menor numero de fibonacci que es mayor o igual a nuestro arreglo
* 2-  
* un numero mayor a nuestro target y posteriormente hace una busqueda binaria en dicho rango
* ya delimitado
*/
int fibonacciSearch(int arr[], int x, int n){
    /* Inicializamos los numero de fibonacci */
    int fibMMm2 = 0; // (m-2)'simo 
    int fibMMm1 = 1; // (m-1)'simo 
    int fibM = fibMMm2 + fibMMm1; // m'simo Fibonacci
 
    // Aqui encontraremos el menor numero de fibonacci  menor o igual a n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marca que delimita nuestros elentos descartados
    int offset = -1;
 
    /* Inpeccionamos los elementos, fibM debe ser 1 ya que cuando fibM vale 1, entonces fib2 = 0 */
    while (fibM > 1) {
        // checar que el fib(m-2) es valido
        int i = min(offset + fibMMm2, n - 1);
 
        /*Si el target es mayor, cortamos nuestro arreglo y buscamos en el lado derecho */
        //printf(" elem %d ", arr[i]);
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        /* Si target es menor cortamos nuestro arreglo y buscamos en el lado izquieroo  */
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        /* Retornamos el indice del elemento encontrado */
        else {
            printf("encontrado %d", i);
            return i;
        }
    }
 
    /* Esta condicion entra cuando hay 3 elementos en el arreglo */
    if (fibMMm1 && arr[offset + 1] == x) {
        return offset + 1;
    }
 
    /*Si el elemento no se encontro entonces retornamos -1 */
    return -1;
}

void* FSthread(void* tdata){
    Data *elems = (Data*)tdata;
    
    int res = fibonacciSearch(elems->arr, elems->target, elems->tam);
    printf("\nThread no %d has found %d at the index: %d \n",elems->noThread, elems->target,res);
}


//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg){
    int n, target, itarget, *A, *B, *C;                                //Varibles auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para la mediciÃ³n del tiempo

    //Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3){
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }
    
    n = atoi(varg[1]); //ELEMENTO A BUSCAR
    target = atoi(varg[2]);   //TAMAÑO DEL PROBLEMA
    
    
    //Reservar Memoria
    
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
    //Ciclo para leer las entradas
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
    pthread_create(&proceso1, NULL, &FSthread, dt1);
    pthread_create(&proceso2, NULL, &FSthread, dt2);
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    //Algoritmo de Busqueda Fibonacci
    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);

    uswtime(&utime1, &stime1, &wtime1);
    //Finaliza el conteo de tiempo
    printf("--------------------------------------------------------------------------------\n" );
    printf("---------------------------------------------------------------------------------" );

    //Calculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("\n\n");
    // //******************************************************************

    //Terminar programa normalmente
    
    exit(0);
}