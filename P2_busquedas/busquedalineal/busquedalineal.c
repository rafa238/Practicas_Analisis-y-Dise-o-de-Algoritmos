//Compilación: "gcc main.c tiempo.x  -o main(teimpo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./main n" (Linux y MAC OS)
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include <pthread.h>
//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	
	//Variables del main
    int array[5]; //declaracion de arreglo
    int numero; //declaracion de numero a buscar
    int bandera=0; //variable para indidcar que se encontro o no 

	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int i; //Variables para loops

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	for(int i=0; i<5; i++){ //inicializacion de for para llenar el arreglo 
    printf ("Ingresa el numero \n"); // mostramos en la pantalla que ingrese el numero
    scanf("%d", &array[i]); //realizamos la entrada de los numeros
}
    printf("Dame el numero que deseas encontrar \n"); //solicitamos el numero a buscar 
    scanf("%d",&numero );// ingresa el numero 

    for(int i=0; i<5; i++){ //inicializamos el for para recorrer el arreglo y buscar el numero

    if(numero == array[i]){ // comparamos el numero a buscar con todos los numeros del arreglo y si es que es igual a el nuero de ese arreglo
       bandera=1; //prendemos la bandera para indicar que se encontro el numero
       break;

    }else {//en caso de que no se haya encontrado el numero se le asignara el valor de 0
        bandera=0;
    }
}
if (bandera == 1){ //en caso de haber prendido la bandera

    printf("El numero se encontro"); //se mostrara en la pantalla que el numero se encontro
}
if (bandera==0){ //en caso de que siga apagada la bandera

    printf("El numero no existe en el arreglo"); //se mostrara en la pantalla que no existe ese numero en el arreglo
}


	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	
}