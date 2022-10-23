//Burbuja Optimizada 2
/*
Compilación del programa: "gcc BurbujaOptimizada2.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " n(numeros a ordenar)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos a ordenar"
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[]){
	 //Reservar Memoria.
	int n,j, aux=0;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medicion de tiempos.
	
	n = atoi(argv[1]); //Se convierte en int el argumento y se asigna a n.
	int *A = (int*) malloc(sizeof(int)*n);
	//Ciclo para leer las entradas
	for(int k = 0; k< n; k++){	
		scanf("%d",&A[k]);
	}	
	
	//******************************************************************	
	//Recepcion y decodificacion de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecucion y cadena=n)
	if (argc!=2){
		exit(1);
	} 
	//Tomar el segundo argumento como tamanio del algoritmo
	else{
		n=atoi(argv[1]);
	}
	int i=0;
	int cambios = 1; //Variable para la bandera del algoritmo
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	//******************************************************************	
	//Algoritmo ordenamiento burbuja Optimizada 2
	//******************************************************************	
	while(i<(n-1) && cambios==1){
		cambios = 0;
		for (j=0;j<(n-1)-i; j++){
			if (A[j] < A[j+1]){
				aux = A[j];	 
				A[j] = A[j+1];  
				A[j+1] = aux;
				cambios = 1;
			}
		}
		i++;
	}
	uswtime(&utime1, &stime1, &wtime1);
	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecucion 
	//******************************************************************
	
/*	for(i = 0; i < n; i++){	
		printf("%d\n",A[i]);
	}*/
	//Cálculo del tiempo de ejecucion del programa
	printf("%d---------------------------------------------------------------------------------", n);
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciones de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciones de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);
}
