#include <stdio.h>
#include <stdlib.h>
#include "arbol_persona.h"
#include "Fila.h"


void menuPasaje(Fila * filita,nodoArbol * raiz);
void pasarDeArbolAFila(Fila * filita,nodoArbol * raiz,int x);

int main()
{
    printf("Hello parcial Lab2\n");
    nodoArbol * raiz = inicArbol();

    char nombreArchivo[] = {"archivoPersona.bin"};
    char nombre[] = {"li"};
    raiz = copiarDatosArchiAarbol(raiz,nombreArchivo);

    Fila filita;
    inicfila(&filita);
    menuPasaje(&filita,raiz);
    mostrarFila(&filita);

    /*
    int x = 28;
    nodoArbol * raiz = inicArbol();

    char nombreArchivo[] = {"archivoPersona.bin"};
    char nombre[] = {"li"};
    raiz = copiarDatosArchiAarbol(raiz,nombreArchivo);

    nodoArbol * aBuscar = buscarNodo(raiz,nombre);
    raiz = borrarNodoArbol(raiz,nombre);
    */



    return 0;
}

void menuPasaje(Fila * filita,nodoArbol * raiz)
{
    int x;
    printf("Ingrese la forma que desea pasar los archivos");
    printf("\n1-Preorden\n2-Inorden\n3-PostOrden\n");
    scanf("%d",&x);
    pasarDeArbolAFila(filita,raiz,x);
}

void pasarDeArbolAFila(Fila * filita,nodoArbol * raiz,int x)
{
    switch(x)
    {
    case 1:
        if(raiz != NULL)
        {
            agregar(filita,raiz->personas);
            pasarDeArbolAFila(filita,raiz->izq,x);
            pasarDeArbolAFila(filita,raiz->der,x);
        }
        break;

    case 2:
        if(raiz)
        {
            pasarDeArbolAFila(filita,raiz->izq,x);
            agregar(filita,raiz->personas);
            pasarDeArbolAFila(filita,raiz->der,x);
        }
        break;

    case 3:
        if(raiz)
        {
            pasarDeArbolAFila(filita,raiz->izq,x);
            pasarDeArbolAFila(filita,raiz->der,x);
            agregar(filita,raiz->personas);
        }
        break;
    }
}
