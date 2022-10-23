// Quick (Ordenamiento Rapido)
/*
Compilación del programa: "gcc QuickSort.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " n(numeros a ordenar)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos a ordenar"
*/
//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*Función intercambiar
Recibe un arreglo de enteros donde se van a intercambiar las dos posiciones y dos enteros que son los indices para 
intercambiar en el arreglo recibido
*/
void intercambiar(int *A, int i, int j)
{
    int temp;
    temp = A[j];
    A[j] = A[i];
    A[i] = temp;
}

/*Función Pivot
Recibe un arreglo de enteros, un entero p (indice del inicio del arreglo) y un entero r (indice del final del arreglo)
Esta función propone el pivote el primer valor del arreglo y se van comparando los valores del arreglo para regresar el pivote.
*/
int Pivot(int *A, int p, int r)
{
    int i = p + 1;
    int j = r;
    int piv = A[p];

    while (1)
    {
        while (A[i] < piv && i < r)
            i++;

        while (A[j] > piv)
            j--;

        if (i < j)
            intercambiar(A, i, j);

        else
        {
            intercambiar(A, p, j);
            return j;
        }
    }
}

/*Función quickSort
Recibe un arreglo de enteros, un entero p (indice del inicio del arreglo) y un entero r(indice del final del arreglo)
Esta función realiza los intercambios por todo el arreglo hasta llegar a 2 elementos 
*/
void quickSort(int *A, int p, int r)
{
    if (p < r)
    {
        int j = Pivot(A, p, r); //Se obtiene el pivote
        quickSort(A, p, j - 1); //Se ordena de 0 al (pivote-1)
        quickSort(A, j + 1, r); //Se ordena del pivote +1 hasta el final
    }
}

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)
{
    //******************************************************************
    //Variables del main
    //******************************************************************
    double utime0, stime0, wtime0, utime1, stime1, wtime1; 
    //Variables para medición de tiempos
    
    int n, *numeros;                                       
    //n determina el tamaño del algorito dado por argumento al ejecutar
    
    int i;                                                 
    //Variables para los ciclos

    //******************************************************************
    //Recepción y decodificación de argumentos
    //******************************************************************
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
    for (i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
    }
    //******************************************************************
    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    //******************************************************************
    uswtime(&utime0, &stime0, &wtime0);
    //******************************************************************

    //******************************************************************
    //Algoritmo de ordenamiento QuickSort ( Ordenamiento Rapido)
    //******************************************************************
    quickSort(numeros, 0, n - 1);
    //******************************************************************

    //******************************************************************
    //Evaluar los tiempos de ejecución
    //******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

    
    //for (i = 0; i < n; i++){
        //printf("%d\n", numeros[i]);
    //}
    
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
    //******************************************************************
	
    //Terminar programa normalmente
    exit(0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

