#ifndef ARBOL_PERSONA_H_INCLUDED
#define ARBOL_PERSONA_H_INCLUDED
#include "persona.h"

typedef struct
{
    persona personas;
    struct nodoArbol * izq;
    struct nodoArbol * der;

}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodoArbol(persona aux);
nodoArbol * insertar(nodoArbol * raiz,nodoArbol * nuevo);
nodoArbol * buscarNodo(nodoArbol * raiz,char nombre[]);
void preOrden(nodoArbol * raiz); /// RAIZ , IZQ , DER
void inOrden(nodoArbol * raiz);  /// IZQ , RAIZ, DER
void postOrden(nodoArbol * raiz); /// IZQ , DER , RAIZ
nodoArbol * copiarDatosArchiAarbol(nodoArbol * raiz,char nombre[]);
nodoArbol * nodoMasIzquierdo(nodoArbol * raiz);
nodoArbol * nodoMasDerecho(nodoArbol * raiz);
nodoArbol * borrarNodoArbol(nodoArbol * raiz,char nombre[]);


#endif // ARBOL_PERSONA_H_INCLUDED
