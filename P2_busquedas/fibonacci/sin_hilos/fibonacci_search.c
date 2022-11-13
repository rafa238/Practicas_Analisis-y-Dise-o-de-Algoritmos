#include <stdio.h>
 
// Helper que devuelve el minimo de 2 elementos
int min(int x, int y) { return (x <= y) ? x : y; }
 
/*
* 1- Realiza la busqueda del menor numero de fibonacci que es mayor o igual a nuestro arreglo
* 2-  
* un numero mayor a nuestro target y posteriormente hace una busqueda binaria en dicho rango
* ya delimitado
*/

int busquedaFibonacci(int arr[], int x, int n)
{
    /* Inicializamos los numero de fibonacci */
    int fibMMm2 = 0; // (m-2)'simo 
    int fibMMm1 = 1; // (m-1)'simo 
    int fibM = fibMMm2 + fibMMm1; // m'simo Fibonacci
 
    // Aqui encontraremos el menor numero de fibonacci  menor o igual a n
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
 
    // Marca que delimita nuestros elentos descartados
    int offset = -1;
 
    /* Inpeccionamos los elementos, fibM debe ser 1 ya que cuando fibM vale 1, entonces fib2 = 0 */
    while (fibM > 1) {
        // checar que el fib(m-2) es valido
        int i = min(offset + fibMMm2, n - 1);
 
        /*Si el target es mayor, cortamos nuestro arreglo y buscamos en el lado derecho */
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        /* Si target es menor cortamos nuestro arreglo y buscamos en el lado izquieroo  */
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        /* Retornamos el indice del elemento encontrado */
        else return i;
    }
 
    /* Esta condicion entra cuando hay 3 elementos en el arreglo */
    if (fibMMm1 && arr[offset + 1] == x) {
        printf("entro"); 
        return offset + 1;
    }
 
    /*Si el elemento no se encontro entonces retornamos -1 */
    return -1;
}
 

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int narg, char **varg){
    int n, num, buscar, *A;                                //Varibles auxiliares
    double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para la mediciÃ³n del tiempo

    //Si no se introducen exactamente 3 argumentos (Cadena de ejecucion, numero a buscar y cadena=n)
    if (narg != 3)
    {
        printf("\nIntroduce una n y tu elemento a buscar");
        exit(1);
    }
    num = atoi(varg[1]); //ELEMENTO A BUSCAR
    n = atoi(varg[2]);   //TAMAÃ‘O DEL PROBLEMA

    //Reservar Memoria
    A = malloc(sizeof(int) * n);

    //Ciclo para leer las entradas
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
    uswtime(&utime0, &stime0, &wtime0);
    //Algoritmo de Busqueda Fibonacci
    buscar = busquedaFibonacci(A, num, n);
    uswtime(&utime1, &stime1, &wtime1);
    //Finaliza el conteo de tiempo

    //(buscar == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", buscar);
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