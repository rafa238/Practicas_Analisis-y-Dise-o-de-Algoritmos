#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tiempo.h"
#include <math.h>
#define min
  
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

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    int n, target, *A;                                //Variables auxiliares
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
    A = malloc(sizeof(int) * n);

    //Ciclo para leer las entradas
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    //******************************************************************
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************
    //Algoritmo de Busqueda Exponencial
    int exp = exponentialSearch(A, n, target);
    printf("El numero %d esta en el indice %d\n", target, exp);
    //******************************************************************
    //Evaluar los tiempos de ejecucion
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);
    //(buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);

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