// Arbol Binario de Busqueda y recorrido InOrden
/*
Compilación del programa: "gcc arbol.c tiempo.c -o "nombre ejecutable"

Ejecución del programa: "nombre ejecutable "n (numeros a ordenar)" >"nombre del archivo en donde se desee ver el resultado" < "nombre
del archivo que se obtendrán los datos a ordenar"
*/
//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "tiempo.h"

int posicion = 0; //Variable Global para ir almacenando en el arreglo los numeros ordenados

/*Funcion crearArbol
Recibe una estructura arbol y regresa un estructura arbol iniciada en nulo*/
struct arbol *crearArbol(struct arbol *a)
{
    a = NULL;
    return a;
}


/*Función insertarNumeros
Recibe una estructura arbol y el numero entero a insertar en el arbol ABB
La función como primer camino crea un nodo con el numero a insertar en caso de ser nulo y retorna el nodo creado con el numero con sus respectivos hijos derecho e izquierdo, en caso de que no fuera nulo se compara si se colocará el numero entero a insertar en la izquierda(si fuera menor que el padre) o en la derecha (si fuera mayor que el padre)
*/
struct arbol *insertarNumeros(struct arbol *a, int num)
{
    if (a == NULL)
    {
        struct arbol *aux = NULL;
        aux = (struct arbol *)malloc(sizeof(struct arbol));
        aux->nodo_izq = NULL;
        aux->nodo_der = NULL;
        aux->numero = num;

        return aux;
    }

    if (num < (a->numero))
        a->nodo_izq = insertarNumeros(a->nodo_izq, num);
    else
        a->nodo_der = insertarNumeros(a->nodo_der, num);

    return a;
}

/*Función guardarRecorridoInOrden
Recibe una estructura de arbolo binario y el arreglo de enteros donde se van almacenar los numeros ordenados
Esta función se verifica que no se nulo el arbol para poder empezar a guardar los valores, enseguida se aplica
el recorrido InOrden(I,R,D), entonces se guarda el hijo izquierdo, y se aumenta la posición, en seguida el padre y al final la derecha y asi sucesivamente hasta que no haya nodos por recorrer dentro del arbol binario. 
*/
void guardarRecorridoInOrden(struct arbol *a, int *arreglo)
{
    if (a != NULL)
    {
        guardarRecorridoInOrden(a->nodo_izq, arreglo);
        *(arreglo + posicion) = a->numero;
        posicion++;
        guardarRecorridoInOrden(a->nodo_der, arreglo);
    }
}

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int narg, char **varg)
{
    int n, *numeros;
    double utime0,stime0,wtime0,utime1,stime1,wtime1;  
    
    //Se crea el arbol
    struct arbol *a;
    a = crearArbol(a);

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecucion y cadena=n)
    if (narg != 2)
    {
        exit(1);
    }
    //Tomar el segundo argumento como tamanio del algoritmo
    n = atoi(varg[1]);

    //Reservar Memoria.
    numeros = malloc(sizeof(int) * (n));
    if (numeros == NULL)
    {
        exit(1);
    }

    //Ciclo para leer las entradas
    for (int i = 0; i < n; i++)
        scanf("%d", &numeros[i]);

    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento

    uswtime(&utime0,&stime0,&wtime0);
    //Algoritmo por Arbol de Busqueda Binario ABB. Recorrido Inorden
    for (int j = 0; j < n; j++)
        a = insertarNumeros(a, numeros[j]);

    guardarRecorridoInOrden(a, numeros);
    uswtime(&utime1, &stime1, &wtime1);
    //Finaliza el conteo de tiempo 

    /*for (int i = 0; i < n; i++)
        printf("\n%d", numeros[i]);*/

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
	// //******************************************************************

	//Terminar programa normalmente	
	exit (0);
}
