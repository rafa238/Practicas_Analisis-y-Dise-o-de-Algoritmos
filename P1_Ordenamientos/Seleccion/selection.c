//Seleccion.
/*
Compilación del programa: "gcc selection.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable "n (numeros a ordenar) >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos a ordenar"
*/
//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	double utime0, stime0, wtime0, utime1, stime1, wtime1;
	int n;			  //variable para recibir la cantidad de numeros a acomodar
	int i, p, k, aux; //variables que ocupara por nuestro algoritmo
	int *A;

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

	//Si no nos da el espacio hay que salir del programa
	if (A == NULL)
		exit(1);

	//Leer Numeros
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

	//Inicio de conteo
	uswtime(&utime0, &stime0, &wtime0);

	//Algoritmo de ordenamieto por Selección
	//Recorre nuestro arreglo
	for (k = 0; k < n - 1; k++)
	{
		p = k; //variable que guarda k para hacer la comparacion con el valor no acomodado mas a la izquierda en nuestro arreglo
		//recorre nuestro arreglo de acuerdo a k, el cual nos marca desde donde empezara a recorrerlo este ciclo
		for (i = k + 1; i < n; i++)
		{
			//Compara si el ultimo valor no cambiada a la izquierda de nuestro arreglo es mayor al de los siguientes para encontrar el valor minimo
			if (A[i] < A[p])
				p = i; //guarda el valor minimo de la lista
		}

		//Se cambian de posicion con ayuda de una variable auxiliar para acomodar el valor minimo encontrado en el primero mas a la izq que no haya sido acomodado antes
		aux = A[p];
		A[p] = A[k];
		A[k] = aux;
	}

	//Evaluar los tiempos de ejecucion

	uswtime(&utime1, &stime1, &wtime1);

	//impresion de numeros
	/*for(i=0;i<n;i++){
        printf("%d \n",A[i]);
    }*/
	printf("%d---------------------------------------------------------------------------------", n);

	//Calculo del tiempo de ejecuciÃ³n del programa
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
