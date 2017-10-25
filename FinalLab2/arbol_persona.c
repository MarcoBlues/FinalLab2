#include "stdlib.h"
#include "stdio.h"
#include "arbol_persona.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(persona nuevo)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->personas.id = nuevo.id;
    aux->personas.cantArticulos = nuevo.cantArticulos;
    aux->personas.medioPago = nuevo.medioPago;
    aux->personas.eliminado = nuevo.eliminado;
    strcpy(aux->personas.apellido,nuevo.apellido);
    strcpy(aux->personas.nombres,nuevo.nombres);
    aux->personas.tiempoEspera = nuevo.tiempoEspera;
    aux->personas.tiempoProcesado = nuevo.tiempoProcesado;
    aux->personas.tipoCliente = nuevo.tipoCliente;

    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * raiz,nodoArbol * arbol)
{
    if(raiz == NULL)
    {
        raiz = arbol;
    }
    else
    {
        if(strlen(raiz->personas.nombres) > strlen(arbol->personas.nombres))
        {
            raiz->izq = insertar(raiz->izq,arbol);
        }
        else
        {
            raiz->der = insertar(raiz->der,arbol);
        }
    }
    return raiz;
}

nodoArbol * buscarNodo(nodoArbol * raiz,char nombre[])
{
    nodoArbol * aBuscar = NULL;
    if(raiz != NULL)
    {
        if(strcmp(raiz->personas.nombres,nombre) == 0)
        {
            aBuscar = raiz;
        }
        else
        {
            if(strlen(nombre) < strlen(raiz->personas.nombres))
            {
                aBuscar = buscarNodo(raiz->izq,nombre);
            }
            else
            {
                aBuscar = buscarNodo(raiz->der,nombre);
            }
        }
    }
    return aBuscar;
}

void mostrarNodo(nodoArbol * raiz)
{
    if(raiz)
    {

        printf("\n_________________________________\n");
        printf("Id: %d \n",(*raiz).personas.id);
        printf("Nombres: %s \n",(*raiz).personas.nombres);
        printf("Apellido: %s \n",(*raiz).personas.apellido);
        printf("Cantidad de articulos: %d\n",(*raiz).personas.cantArticulos);
        printf("Medio de pago: %d\n",(*raiz).personas.medioPago);
        printf("Tipo de cliente: %d\n",(*raiz).personas.tipoCliente);

    }
}

void preOrden(nodoArbol * raiz)
{
    if(raiz != NULL)
    {
        mostrarNodo(raiz);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}

void inOrden(nodoArbol * raiz)
{
    if(raiz != NULL)
    {
        inOrden(raiz->izq);
        mostrarNodo(raiz);
        inOrden(raiz->der);
    }
}

void postOrden(nodoArbol * raiz)
{
    if(raiz)
    {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        mostrarNodo(raiz);
    }
}

nodoArbol * copiarDatosArchiAarbol(nodoArbol * raiz,char nombre[])
{
    persona aux;
    FILE * archi = fopen(nombre,"r+b");
    if(archi != NULL)
        while(fread(&aux,1,sizeof(persona),archi)>0)
        {
            raiz = insertar(raiz,crearNodoArbol(aux));
        }

    return raiz;
}

nodoArbol * nodoMasDerecho(nodoArbol * raiz)
{
    nodoArbol * aux = NULL;
    if(raiz != NULL)
    {
        if(raiz->der == NULL)
        {
            aux =  raiz;
        }
        else
        {
            aux = nodoMasDerecho(raiz->der);
        }
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * raiz)
{
    nodoArbol * aux = NULL;
    if(raiz)
    {
        if(raiz->izq == NULL)
        {
            aux = raiz;
        }
        else
        {
            aux = nodoMasIzquierdo(raiz->izq);
        }
    }
    return aux;
}

nodoArbol * borrarNodoArbol(nodoArbol * raiz,char nombre[])
{
    nodoArbol * a_borrar = NULL;
    if(raiz != NULL)
    {
       if(strcmp(nombre,raiz->personas.nombres)==0)
            if(raiz->izq != NULL)
            {
                a_borrar = nodoMasDerecho(raiz->izq);
                raiz->personas = a_borrar->personas;
                raiz->izq = borrarNodoArbol(raiz->izq,a_borrar->personas.nombres);
            }
            else if(raiz->der != NULL)
            {
                a_borrar = nodoMasIzquierdo(raiz->der);
                raiz->personas = a_borrar->personas;
                raiz->der = borrarNodoArbol(raiz->der,a_borrar->personas.nombres);
            }
            else
            {
                free(raiz);
                raiz = NULL;
            }
        else if(strlen(raiz->personas.nombres) < strlen(nombre))
        {
            raiz->der = borrarNodoArbol(raiz->der,nombre);
        }
        else
        {
            raiz->izq = borrarNodoArbol(raiz->izq,nombre);
        }
    }
    return raiz;
}

