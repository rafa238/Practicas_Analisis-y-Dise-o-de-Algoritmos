//Shell
/*
Compilación del programa: "gcc shell.c tiempo.c -o "nombre ejecutable"

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
int main (int argc, char* argv[]){

    double utime0,stime0,wtime0,utime1,stime1,wtime1;
    int n;
    int b,i,k,temp,j;
    int *A;
    
    //Lectura del argumento de entrada para n
    if (argc!=2) 
    {
        exit(1);
    } 
    else
    {
        n=atoi(argv[1]);
    }
    
    //Reservar la memoria dinamica de tamano de n enteros.
    A = malloc(sizeof(int)*n);
    
    //Si no nos da el espacio hay que salir del programa
    if(A == NULL){
        exit(1);
    }

    
    //Leer numeros
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    //Inicio de conteo
    uswtime(&utime0,&stime0,&wtime0);
    
    //Algoritmo de ordenamieto Shell
    k = n/2;
    while(k>=1){
        b=1;
        while(b!=0){
            b=0;
            for(i=k;i<=n-1;i++){
                if(A[i-k]>A[i]){
                    temp=A[i];
                    A[i]= A[i-k];
                    A[i-k]=temp;
                    b=b+1;
                }
            }
        }
        k=k/2;
    }
	//Evaluar los tiempos de ejecucion
	
	uswtime(&utime1, &stime1, &wtime1);

	//impresion de numeros
    /*for(i=0;i<n;i++){
        printf("%d \n",A[i]);
    }*/
    printf("%d---------------------------------------------------------------------------------", n);
	
    //Calculo del tiempo de ejecucion del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n",  stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    
    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
    printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n",  stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n\n");
	

	//Terminar programa normalmente	
	exit (0);

}
