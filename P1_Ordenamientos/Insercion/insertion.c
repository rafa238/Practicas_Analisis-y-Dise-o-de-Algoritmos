//Insercion
/*
Compilación del programa: "gcc insertion.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " n(numeros a ordenar)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos a ordenar"
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

int main(int argc, char *argv[]){

    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    //Declaracion de las variables para medir el tiempo

    int n;
    //Variable para recibir la cantidad de numeros a acomodar

    int i, temp, j;
    int *A;
    //Variables que ocupara por nuestro algoritmo

    //Lectura del argumento de entrada para n
    if (argc != 2)
    {
        exit(1);
    }
    else
    {
        n = atoi(argv[1]);
    }

    //Reserva de memoria dinamica
    A = malloc(sizeof(int) * n);

    if (A == NULL)
    {
        exit(1);
    }

    //Leer numeros
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    //Inicio de conteo
    uswtime(&utime0, &stime0, &wtime0);

    //Algoritmo de ordenamiento INSERCION
    for (i = 0; i <= n - 1; i++) //la posicion inicial del array hasta n-1
    {
        j = i; //la posicion de nuestra carta
        temp = A[i];    //el valor de nuestra carta
        //Seccion de recorrido de numeros en caso de que el termino anterior sea mayor
        while ((j > 0) && (temp < A[j - 1])) //vamos a recorrer hasta encontrar un valor menor o llegar al principio del array
        {
            A[j] = A[j - 1]; //cambiamos el elemento de enfrente hacia atras 
            j--;//nos recorremos
        }
        //Asignacion del lugar que ocupara el numero
        A[j] = temp;
    }
    uswtime(&utime1, &stime1, &wtime1);
    //Evaluar los tiempos de ejecucion

    //Impresion de numeros
    /*for(i=0;i<n;i++){
        printf("%d \n",A[i]);
    }*/

    printf("%d---------------------------------------------------------------------------------", n);
    //Calculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n\n");
    // //******************************************************************

    //Terminar programa normalmente
    exit(0);
}
