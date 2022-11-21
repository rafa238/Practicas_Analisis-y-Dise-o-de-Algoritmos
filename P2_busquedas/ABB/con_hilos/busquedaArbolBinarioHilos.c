/*
Compilación del programa: "gcc busquedaArbolBinarioHilos.c tiempo.c -lpthread -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " num(numero a buscar) n(tamaño de la muestra donde se buscará)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos"
*/
//Librerias utilizadas

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"

struct arbol
{
	int numero;				//Dato
	struct arbol *nodo_izq; //Hijo izquierdo
	struct arbol *nodo_der; //Hijo Derecho
};

//Prototipos

struct arbol *insNum(struct arbol *a, int num);//Prototipo instertar numero
void busABH(struct arbol *a, int numBus);//Prototipo para busqueda solo de hijos
void busABR(struct arbol *a, int numBus);//Prototipo para busqueda solo de raiz
void *funHABR(void *a);//Funcion apuntador para hilos busqueda solo raiz
void *funHABH(void *a);//Funcion apuntador para hilos busqueda solo hijos

int encontrado, num; //Variables Globales

struct arbol *insNum(struct arbol *a, int num)//recibe una estructura de arbol y el numero a insertar en nuestro ABB
{
    if (a == NULL)//Si esta vacio nustro struct iniciara este if
    {
        struct arbol *aux = NULL;//Primero lo hace igual a null
        aux = (struct arbol *)malloc(sizeof(struct arbol));//Reserva la memoria para aux
        aux->nodo_izq = NULL;//Hace que nuestro hijo o nodo izquierdo sea Null
        aux->nodo_der = NULL;//Hace que nuestro hijo o nodo derecho sea Null
        aux->numero = num;//Crea el "Key" o "Nodo principal" como num
        return aux;//retorna aux osea ese Nodo
    }
    if (num < (a->numero))//En otro caso si el dato a insertar es menor al numero en el nodo padre, se asignara al hijo izquierdo
        a->nodo_izq = insNum(a->nodo_izq, num);//Aqui se asigna al hijo izquierdo dicho numero y vuelve a llamar a la funcion con dichos parametros
    else//En caso contrario
        a->nodo_der = insNum(a->nodo_der, num);//Se insera al hijo derecho y vuelve a llamar a la funcion con dichos parametros

    return a;//Al terminar ya retorna nuestra struct a
}


void busABH(struct arbol *a, int numBus)//recibe una estructura de arbol y el numero a buscar
{
	struct arbol *aux = a;//Se  crea una estructura auxiliar con el fin de recorrer el arbol
     encontrado = 0;//Se crea una variable igual auxiliar para saber si el numero fue encontrado o no
    while (aux != NULL && encontrado == 0)//Mientras nuestro auxiliar sea diferende de nulo y encontrado siga siendo 0
    {//se hara
        if (numBus == aux->numero)//Si el numro que buscamos ya esta en nuestro auxiliar 
        {
            encontrado = 1;//Se asignara 1 a encontrado rompiendo el ciclo ya que se encontro el numerp
        }
        else if (numBus < aux->numero)//Si no, el numero es menor al numero que esta en nuestro auxiliar
        {
            aux = aux->nodo_izq;//Descartamos el arbol que esta por la derecha y nos movemos a la izquierda
        }
        else if (numBus > aux->numero)//si no, encontes el numero que buscamos es mayor al auxiliar en ese momento
        {
            aux = aux->nodo_der;//Entonces movera el auxiliar a la derecha para buscar ahi
        }
    }
}


void busABR(struct arbol *a, int numBus)//Recibe una estructura árbol y el elemento a buscar dentro del árbol binario
{
	struct arbol *aux = a;// Inicia el struct de arbol apuntando al struct a
	encontrado = 0;//Crea bandera si fue encontrado
	if (aux != NULL)//Si el valor auxialiar es diferente de 0
	{
		if (numBus == aux->numero)//Si el numero buscado es igual al numedo con el cual l ocomparamos
		{
			encontrado = 1;//Cambiara la bandera a 1
		}
	}
}


void *funHABR(void *a)//Funcion que nos ayudara con los hilos a tomar la funcion raiz
{
	busABR((struct arbol *)a, num);//Llamado de la funcion de busqueda en raiz
}


void *funHABH(void *a)//Funcion que nos ayudara con los hilos a tomar la funcion hijos
{
	busABH((struct arbol *)a, num);//Llamado de la funcion de busqueda en hijos
}

int main(int narg, char **varg)
{
	int n, *numeros, num;							   //Variables auxiliares
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medir el tiempo
	pthread_t hilos1, hilos2, hilos3;					   //Se crean tres hilos
	struct arbol *a = NULL;								   //Se crea el arbol

	//Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
	if (narg != 3)
	{
		exit(1);
	}
	num = atoi(varg[1]); //Elemento a buscar

	n = atoi(varg[2]); //Tamaño del problema

	numeros = (int *)malloc(sizeof(int) * n);
	//Ciclo para leer las entradas y para insertar los elementos al arbol binario en este caso dividido
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numeros[i]);
	}
	for (int i = 0; i < n; i++)
	{
		a = insNum(a, numeros[i]);

		
	}

	uswtime(&utime0, &stime0, &wtime0);
	//Algoritmo de Busqueda en Arbol Binario de Busqueda con Hilos
	pthread_create(&hilos1, NULL, &funHABR,NULL);//creamos el pthread de hilso 1 para ver raiz (void *)a


	pthread_create(&hilos2, NULL, &funHABH, NULL);//creamos el pthread de hilso 1 para ver hijos (void *)a->nodo_izq


	pthread_create(&hilos3, NULL, &funHABH, NULL);//creamos el pthread de hilso 1 para ver hijos (void *)a->nodo_der
	

	pthread_join(hilos1, NULL);//Ejecuta el hilo 1
	pthread_join(hilos2, NULL);//Ejecuta el hilo 2
	pthread_join(hilos3, NULL);//Ejecuta el hilo 3
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
	//******************************************************************
	//Terminar programa normalmente
	exit(0);
}
