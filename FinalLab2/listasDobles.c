#include <stdio.h>
#include <stdlib.h>
#include "listasDobles.h"

nodo2 * inicLista() /// INICIALIZA LA LISTA
{
    return NULL;
}

nodo2 * cargarDato(persona nuevo) /// CREA Y CARGA EL NODO CON LOS DATOS
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

nodo2 * agregarFinal(nodo2 * lista,nodo2 * nuevoNodo) /// AGREGAR AL FINAL DE LA FILA
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

void mostrar(nodo2 * lista) /// MUESTRA UN NODO
{
    printf("\n_________________________________\n");
    printf("Id: %d \n",(*lista).cliente.id);
    printf("Nombres: %s \n",(*lista).cliente.nombres);
    printf("Apellido: %s \n",(*lista).cliente.apellido);
    printf("Cantidad de articulos: %d\n",(*lista).cliente.cantArticulos);
    printf("Medio de pago: %d\n",(*lista).cliente.medioPago);
    printf("Tipo de cliente: %d\n",(*lista).cliente.tipoCliente);

}

void mostrarYrecorrer(nodo2 * lista) /// RECORRE LA LISTA Y MUESTRA LOS NODOS QUE ALLA
{
    if(lista != NULL)
    {
        mostrar(lista);
        mostrarYrecorrer(lista->sig);
    }
}

nodo2 * borrarPrimero(nodo2 * lista) /// BORRA EL PRIMER NODO
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

nodo2 * borrarNodoCliente(nodo2 * lista,persona cliente) /// BORRA UN NODO EN ESPECIFICO POR EL NOMBRE DEL CLIENTE
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

nodo2 * ultimoNodo(nodo2 * lista) /// EL ULTIMO NODO
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

persona primeroLista(nodo2 * lista) /// RETORNA LA PRIMERA PERSONA DE LA LISTA
{
    persona primero = lista->cliente;

    return primero;
}

nodo2 * InsertarEnOrdenPorTipoCliente(nodo2 * lista,nodo2 * nuevo)/// inserta en la lista por el tipo de cliente
{
    if(lista == NULL || lista->cliente.tipoCliente >= nuevo->cliente.tipoCliente)
    {
        nuevo->sig = lista;
        if(lista != NULL)
        {
            lista->ant = nuevo;
        }
        lista = nuevo;
    }
    else
    {
        nodo2 * aux = lista;
        nodo2 * ante = aux->ant;
        while(aux && aux->cliente.tipoCliente <= nuevo->cliente.tipoCliente)
        {
            ante = aux;
            aux = aux->sig;
        }
        if(aux != NULL)
        {
            nuevo->sig = aux;
            nuevo->ant = ante;
            aux->ant = nuevo;
            ante->sig = nuevo;
        }
        else
        {
            ante->sig = nuevo;
            nuevo->ant = ante;
        }
    }
    return lista;
}

nodo2 * InsertarEnOrdenPorCantArticulos(nodo2 * lista,nodo2 * nuevo) /// inserta en la lista en orden por la cantidad de articulos
{
    if(lista == NULL || lista->cliente.cantArticulos >= nuevo->cliente.cantArticulos)
    {
        nuevo->sig = lista;
        if(lista != NULL)
        {
            lista->ant = nuevo;
        }
        lista = nuevo;
    }
    else
    {
        nodo2 * aux = lista;
        nodo2 * ante = aux->ant;
        while(aux && aux->cliente.cantArticulos <= nuevo->cliente.cantArticulos)
        {
            ante = aux;
            aux = aux->sig;
        }
        if(aux != NULL)
        {
            nuevo->sig = aux;
            nuevo->ant = ante;
            aux->ant = nuevo;
            ante->sig = nuevo;
        }
        else
        {
            ante->sig = nuevo;
            nuevo->ant = ante;
        }
    }
    return lista;
}
