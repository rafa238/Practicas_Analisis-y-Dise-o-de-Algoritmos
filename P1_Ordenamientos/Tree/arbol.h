struct arbol
{
    int numero; //Dato 
    struct arbol *nodo_izq; //Hijo izquierdo
    struct arbol *nodo_der; //Hijo Derecho
};

//Prototipos
struct arbol *crearArbol(struct arbol *a);
struct arbol *insertarNumeros(struct arbol *a, int num);
void guardarRecorridoInOrden(struct arbol *a, int *arreglo);



