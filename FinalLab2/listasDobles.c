#include <stdio.h>
#include <stdlib.h>
#include "listasDobles.h"


nodo2 * inicLista()
{
    return NULL;
}

nodo2 * cargarDato(persona nuevo)
{

    nodo2 * aux = (nodo2*)malloc(sizeof(nodo2));

    aux->cliente.id = nuevo.id;
    aux->cliente.cantArticulos = nuevo.cantArticulos;
    aux->cliente.medioPago = nuevo.medioPago;
    aux->cliente.eliminado = nuevo.eliminado;
    strcpy(aux->cliente.apellido,nuevo.apellido);
    strcpy(aux->cliente.nombres,nuevo.nombres);
    aux->cliente.tiempoEspera = nuevo.tiempoEspera;
    aux->cliente.tiempoProcesado = nuevo.tiempoProcesado;
    aux->cliente.tipoCliente = nuevo.tipoCliente;

    aux->sig = NULL;
    aux->ant = NULL;

    return aux;
}

nodo2 * agregarFinal(nodo2 * lista,nodo2 * nuevoNodo)
{
    if(lista == NULL)
    {
        lista= nuevoNodo;
    }
    else
    {
        if(lista->sig == NULL)
        {
            lista->sig = nuevoNodo;
            nuevoNodo->ant = lista;
        }
        else
        {
            lista = agregarFinal(lista->sig,nuevoNodo);
        }
    }
    return lista;
}


void mostrar(nodo2 * lista)
{
    printf("\n_________________________________\n");
    printf("Id: %d \n",(*lista).cliente.id);
    printf("Nombres: %s \n",(*lista).cliente.nombres);
    printf("Apellido: %s \n",(*lista).cliente.apellido);
    printf("Cantidad de articulos: %d\n",(*lista).cliente.cantArticulos);
    printf("Medio de pago: %d\n",(*lista).cliente.medioPago);
    printf("Tipo de cliente: %d\n",(*lista).cliente.tipoCliente);

}


void mostrarYrecorrer(nodo2 * lista)
{
    if(lista != NULL)
    {
        mostrar(lista);
        mostrarYrecorrer(lista->sig);
    }
}

nodo2 * borrarPrimero(nodo2 * lista)
{
    if(lista != NULL)
    {
        nodo2 * aBorrar = lista;
        lista = lista->sig;
        if(lista != NULL)
        {
            lista->ant = aBorrar->ant;
            free(aBorrar);
        }
    }
    return lista;
}

nodo2 * borrarNodoCliente(nodo2 * lista,persona cliente)
{
    nodo2 * aBorrar;
    if(lista)
    {
        if(strcmp(lista->cliente.nombres,cliente.nombres))
        {
            aBorrar = lista;
            lista = lista->sig;
            if(lista != NULL)
            {
                lista->ant = aBorrar->ant;
                free(aBorrar);
            }
        }
        else
        {
            lista->sig = borrarNodoCliente(lista->sig,cliente);
        }
    }
    return lista;
}

nodo2 * ultimoNodo(nodo2 * lista)
{
    nodo2 * aux;
    if(lista != NULL)
    {
        if(lista->sig == NULL)
        {
            mostrar(lista);
            aux = lista;
        }
        else
        {
            aux = ultimoNodo(lista->sig);
        }
    }
    return aux;
}

persona primeroLista(nodo2 * lista)
{
    persona primero = lista->cliente;

    return primero;
}

persona agregar1Persona()
{
        persona aux;

        printf("Ingrese id: ");
        fflush(stdin);
        scanf("%d",&aux.id);

        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s",&aux.nombres);

        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%s",&aux.apellido);

        printf("Ingrese tipo de cliente: ");
        fflush(stdin);
        scanf("%d",&aux.tipoCliente);

        printf("Ingrese medio de pago: ");
        fflush(stdin);
        scanf("%d",&aux.medioPago);

        printf("Ingrese la cantidad de articulos: ");
        fflush(stdin);
        scanf("%d",&aux.cantArticulos);

        aux.eliminado = 0;
        aux.tiempoEspera = 0;
        aux.tiempoProcesado = 0;

        return aux;
}
