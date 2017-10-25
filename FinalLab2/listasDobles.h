#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include "persona.h"
typedef struct
{
    persona cliente;
    struct nodo2 * sig;
    struct nodo2 * ant;

}nodo2;

nodo2 * cargarLista(nodo2 * lista);

nodo2 * inicLista();

persona primeroLista(nodo2 * lista);

nodo2 * agregarFinal(nodo2 * lista,nodo2 * nuevoNodo);

void mostrarYrecorrer(nodo2 * lista);

nodo2 * InsertarEnOrdenPorTipoCliente(nodo2 * lista,nodo2 * nuevo);

nodo2 * borrarNodo(nodo2 * lista,char nombre[]);

nodo2 * ultimoNodo(nodo2 * lista);

nodo2 * borrarPrimero(nodo2 * lista);

nodo2 * InsertarEnOrdenPorCantArticulos(nodo2 * lista,nodo2 * nuevo);

#endif // LISTASDOBLES_H_INCLUDED
