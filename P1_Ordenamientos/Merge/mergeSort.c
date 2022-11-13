// Merge (Mezcla)
/*
Compilación del programa: "gcc mergeSort.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " n(numeros a ordenar)  >"nombre del archivo en donde se desee ver el resultado" < "nombre
del archivo que se obtendrán los datos a ordenar"
*/
//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tiempo.h"

/*Función merge
Recibe el arreglo A donde se almacenarán los numeros ordenados, un entero p (indice del inicio del arreglo), un entero q(indice de la mitad del arreglo) y un entero r(indice del final del arreglo)
*/
void merge(int *A, int p, int q, int r)
{
    int *C; //Arreglo auxiliar

    //Variables para los ciclos
    int l, i, j;
    l = r - p + 1;
    i = p;
    j = q + 1;
    C = malloc(sizeof(int) * (l + 2));

    for (int k = 0; k <= l; k++)
    {
        if (i <= q && j <= r)
        {
            if (A[i] < A[j])
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = A[j];
                j++;
            }
        }
        else
        {
            if (i <= q)
            {
                C[k] = A[i];
                i++;
            }
            else
            {
                C[k] = A[j];
                j++;
            }
        }
    }

    //Terminando de ordenar los numeros, se pasan los numeros del arreglo temporal al arreglo donde se van almacenar todos los numeros a ordenar
    int o = 0;
    for (int m = p; m <= r; m++)
    {
        A[m] = C[o];
        o++;
    }
}

/*Función mergeSort
Recibe el arreglo de enteros donde se almacenarán los numeros, un entero p (indice del inicio del arreglo) y un entero r (indice del final del arreglo)
*/
void mergeSort(int *A, int p, int r){
    int q;
    if (p < r)
    {
        q = trunc((p + r) / 2); //Se obtiene la mitad (parte entera) del arreglo

        //Recursividad hasta llegar a 2 elementos
        mergeSort(A, p, q);     //Se ordenan de 0 a la mitad del arreglo
        mergeSort(A, q + 1, r); //Se ordenan de la mitad al final del arreglo
        merge(A, p, q, r);      //Junta los mini arreglos que se van arreglando
    }
}

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
int main(int narg, char **varg)
{
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
    //Algoritmo de ordenamiento por Merge (Mezcla)
    mergeSort(numeros, 0, n - 1);

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
}
