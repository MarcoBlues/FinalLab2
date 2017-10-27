#include <stdio.h>
#include <stdlib.h>
#include "arbol_persona.h"
#include "Fila.h"
#include "Arreglo_Filas.h"


void menuPasaje(Fila * filita,nodoArbol * raiz);
void pasarDeArbolAFila(caja cajita[8],nodoArbol * raiz,int x);
persona pasarAfilaPreOrden(nodoArbol * raiz);

int main()
{
    printf("Hello parcial Lab2\n");
    nodoArbol * raiz = inicArbol();
    caja cajita[8];

    char nombreArchivo[] = {"archivoPersona.bin"};
    char nombreArchivoCajas[] = {"archivoCajas.bin"};

    raiz = copiarDatosArchiAarbol(raiz,nombreArchivo); /// 39 elementos cargados

    cargarArchivoCaja(nombreArchivoCajas); /// cajas sin cargar... hasta tener los algoritmos
    leerArchivoCaja(nombreArchivoCajas);
    pasarDeArchiAcaja(nombreArchivoCajas,cajita);

    menuPasaje(cajita,raiz);

    mostrarCajasYFilas(cajita);

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

void pasarDeArbolAFila(caja cajita[8],nodoArbol * raiz,int x)
{
    int i =0;
    persona aux;
    switch(x)
    {
    case 1:

        while(i<8)
        {
            if(raiz)
            {
                aux = raiz->personas;
                agregarClienteACaja(cajita,cajaConMenosCliente(aux.medioPago,cajita),aux);
                pasarDeArbolAFila(cajita,raiz->izq,x);
                pasarDeArbolAFila(cajita,raiz->der,x);
            }
            i++;
        }
        break;

    case 2:
        while(i<8)
        {
            if(raiz)
            {
                pasarDeArbolAFila(cajita,raiz->izq,x);
                aux = raiz->personas;
                agregarClienteACaja(cajita,cajaConMenosCliente(aux.medioPago,cajita),aux);
                pasarDeArbolAFila(cajita,raiz->der,x);
            }
            i++;
        }
        break;

    case 3:
        while(i<8)
        {

            if(raiz)
            {
                pasarDeArbolAFila(cajita,raiz->izq,x);
                pasarDeArbolAFila(cajita,raiz->der,x);
                aux = raiz->personas;
                agregarClienteACaja(cajita,cajaConMenosCliente(aux.medioPago,cajita),aux);

            }
            i++;
        }
        break;
    }
}
