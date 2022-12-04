//Librerias utilizadas
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

int num, n,encontrado = 0; //Variables globales


void busquedaBinaria(int *A, int inicio, int final, int numeroBuscado)
{
	while (encontrado == 0 && inicio <= final)
	{
		int medio = (inicio + final) / 2;
		if (A[medio] == numeroBuscado)
		{
			encontrado = 1;
		}

		else if (A[medio] < numeroBuscado)
		{
			inicio = medio + 1;
		}

		else if (A[medio] > numeroBuscado)
		{
			final = medio - 1;
		}
	}
}

/*
FuncionHiloBusquedaBinaria
La función llama a la función de busquedaBinaria para que un hilo  lo haga en la primera mitad del arreglo y el segundo lo haga en la segunda mitad en pararelo
*/
void *funcionHiloBusquedaBinaria(void *A)
{
	busquedaBinaria((int *)A, 0, n - 1, num);
}


int main(int narg, char **varg)
{
	int i, *primerMedio, *segundoMedio, *A, medio, j;	   //Variables auxiliares
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	pthread_t hilos1, hilos2;							   //Se crean dos hilos

	//Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
	if (narg != 3)
	{
		printf("\nIntroduce una n y tu elemento a buscar");
		exit(1);
	}

	num = atoi(varg[1]); //ELEMENTO A BUSCAR
	n = atoi(varg[2]);	 //TAMAÑO DEL PROBLEMA
	medio = n / 2;		 //Se obtiene la mitad

	//Reservar Memoria
	A = malloc(sizeof(int) * n);
	primerMedio = malloc(sizeof(int) * n);
	segundoMedio = malloc(sizeof(int) * n);

	//Ciclos para leer las entradas
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}

	for (i = 0; i <= medio; ++i)
	{
		*(primerMedio + i) = *(A + i);
	}
	i = 0;

	for (j = medio + 1; j < n; ++j, i++)
	{
		*(segundoMedio + i) = *(A + j);
	}

	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//Algoritmo de Busqueda Binaria con Hilos
	uswtime(&utime0, &stime0, &wtime0);
	//Errores en caso de que los hilos no se puedan crear
	if (pthread_create(&hilos1, NULL, funcionHiloBusquedaBinaria, (void *)primerMedio) != 0)
	{
		perror("El thread 1 no  pudo crearse");
		exit(-1);
	}
	if (pthread_create(&hilos2, NULL, funcionHiloBusquedaBinaria, (void *)segundoMedio) != 0)
	{
		perror("El thread 2 no  pudo crearse");
		exit(-1);
	}
	//Algoritmo de Busqueda Binaria en cada mitad
	pthread_join(hilos1, NULL);
	pthread_join(hilos2, NULL);
	uswtime(&utime1, &stime1, &wtime1);
	//Finaliza el conteo de tiempo

	printf("%d---------------------------------------------------------------------------------\n", n);
	printf("%d---------------------------------------------------------------------------------", num);

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
