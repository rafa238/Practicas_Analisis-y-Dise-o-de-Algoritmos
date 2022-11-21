/*
Compilación del programa: "gcc busquedaArbolBinario.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable " num(numero a buscar) n(tamaño de la muestra donde se buscará)  >"nombre del archivo en donde se desee ver el resultado" < "nombre del archivo que se obtendrán los datos"
*/
//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
struct arbol//struct para el arbol
{
    int numero;             //Dato
    struct arbol *nodo_izq; //Hijo izquierdo
    struct arbol *nodo_der; //Hijo Derecho
};

//Prototipos
struct arbol *insNum(struct arbol *a, int num);//Prototipo instertar numero
void busAB(struct arbol *a, int numBus);//prototipo busqueda en el arbl binario


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


void busAB(struct arbol *a, int numBus)//recibe una estructura de arbol y el numero a buscar
{
    struct arbol *aux = a;//Se  crea una estructura auxiliar con el fin de recorrer el arbol
    int encontrado = 0;//Se crea una variable igual auxiliar para saber si el numero fue encontrado o no
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

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg)//Inicio de nuestro programa
{
    int n, *numeros, num;  //Variables auxiliares n (n numeros que aniadiremos), *numeros (Numero que se a�adira), num (Numero que se buscara) 
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medir el tiempo

    struct arbol *a = NULL;//Struct de arbol igual a Null

    //Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3)
    {
        exit(1);//termina 
    }
    num = atoi(varg[1]); //Elemento a buscar

    n = atoi(varg[2]); //Tamanio del problema

    //Reservar Memoria para los numeros.
    numeros = malloc(sizeof(int) * (n));
    if (numeros == NULL)//Si no se dan numeros
    {
        exit(1);//Termina
    }

    //Ciclo para leer las entradas y para insertar los elementos al arbol binario
    for (int i = 0; i < n; i++)//For el cual terminara hasta que sea menor a n (n mumeros que a�adiremos)
    {
        scanf("%d", &numeros[i]);//Escanea los datos de entrada y los inserta en el arreglo de numeros
        a = insNum(a, numeros[i]);//Asigna a "a" la llamada de insNum para la creacion de nuestro arbol
    }

    uswtime(&utime0, &stime0, &wtime0);
    //Algoritmo de Busqueda en un arbol Binario de Busqueda
    busAB(a, num);//Ahora si inicia la busqueda del numero
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
