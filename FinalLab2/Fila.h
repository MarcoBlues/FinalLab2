#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "stdbool.h"
#include "listasDobles.h"
#include "persona.h"
typedef struct
{
     struct nodo2 * primero;
     struct nodo2 * ultimo;

}Fila;

void inicfila(Fila * fila);
void agregar(Fila * fila,persona dato); //agrega un elemento al final de la lista
void agregarFilaXtipoCliente(Fila * fila,persona cliente);
void agregarFilaXCantArticulos(Fila * fila,persona cliente) ;
persona extraer(Fila * fila); //saca un elemento del inicio de la lista
void mostrarFila(Fila * fila);
void leer(Fila * fila);
int cantidadelementos(Fila f);
persona primero(Fila * fila); //similar a tope
bool filavacia(Fila * fila); //similar a pilavacia


#endif // FILA_H_INCLUDED
