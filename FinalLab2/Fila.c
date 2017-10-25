#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicfila(Fila * fila)
{
    fila->primero = inicLista();
    fila->ultimo = inicLista();
}

persona primero(Fila * fila)
{
    persona dato = primeroLista(fila->primero);

    return dato;
}


void agregar(Fila * fila,persona cliente)
{
    if(fila->primero == NULL && fila->ultimo == NULL)
    {
        fila->primero = cargarDato(cliente);
        fila->ultimo = cargarDato(cliente);
    }
    else
    {
        fila->ultimo = agregarFinal(fila->primero,cargarDato(cliente));
    }
}

void mostrarFila(Fila * fila)
{
    printf("Inicio=>");
    if(fila!= NULL)
        {
            mostrarYrecorrer(fila->primero);
            printf("<=Final");
        }
}

persona extraer(Fila * fila)
{
    persona aux = primeroLista(fila->primero);
    fila->primero = borrarPrimero(fila->primero);
    if(fila->primero == NULL)
    {
        fila->ultimo = NULL;
    }
    return aux;
}

void leer(Fila * fila)
{
    persona dato = agregar1Persona();

    agregar(fila,dato);
}

bool filavacia(Fila * fila)
{
    bool flag = true;
    if(fila->primero != NULL)
    {
        flag= false;
    }
    return flag;
}
