#include "Arreglo_Filas.h"
#include <stdio.h>
#include <stdlib.h>


void abrirOcerrarCaja(caja cajita[],int indice) ///SI LA CAJA NO CIENTE CLIENTE CIERRA O  EN SU DEFECTO LA ABRE
{

    if(cajita[indice].filita.primero)
    {
        if(cajita[indice].abiertaOcerrada == 1)
            cajita[indice].abiertaOcerrada = 0;
        else
            cajita[indice].abiertaOcerrada = 1;
    }
    else
    {
        printf("La caja tiene clientes\n");
    }
}

caja buscarCaja(int tipo_pago,caja cajita[],int indice) /// BUSCA LA CAJA POR EL MEDIO DE PAGO Y SI ESTA ABIERTA
{
    caja aux;
    int i =0;
    while(i<indice)
    {
        if(tipo_pago == cajita[i].tipo_pago)
        {
            if(cajita[i].abiertaOcerrada == 1){aux = cajita[i];}
        }
        i++;
    }
    return aux;
}

void mostrar1Caja(caja cajita) /// MUESTRA UNA CAJA
{
    printf("\n_____________________________\n");
    printf("\n---Caja N-%d---\n",cajita.nro_de_caja);
    printf("Nombre: %s\n",cajita.nombreCajero);
    printf("Algoritmo: %s\n",cajita.algoritmoPlanificacion);
    if(cajita.tipo_pago == 1)
    {
        printf("Tipo de pago: Efectivo\n");
    }
    else if(cajita.tipo_pago ==2)
    {
        printf("Tipo de pago: Credito/Debito \n");
    }
    else
    {
        printf("Tipo de pago: Todos los medios de pago\n");
    }

    if(cajita.abiertaOcerrada == 1)
    {
        printf("La caja se encuentra: Abierta\n");
    }
    else
    {
        printf("La caja se encuentra: Cerrada\n");
    }
}

void mostrarCajasYFilas(caja cajita[]) /// MUESTRA LA CAJA Y FILAS QUE ESTEN ABIERTAS
{
    int i =0;
    while(i<8 ) /// CAMBIAR X UN 8 YA QUE SOLAMENTE CARGUE 2 CAJAs PARA PROBAR
    {
        if(cajita[i].abiertaOcerrada == 1)
        {
        mostrar1Caja(cajita[i]);
        mostrarFila(&cajita[i].filita);
        }
        i++;
    }
}

void FIFO(caja cajita[])
{

}


void agregarClienteACaja(caja cajita[],int i,persona aux) /// AGREGA CLIENTE A LA FILA
{

    if(cajita[i].abiertaOcerrada == 1)
    {
        if(cajita[i].tipo_pago == aux.medioPago || cajita[i].tipo_pago == 3)
        {
            if(strcmp(cajita[i].algoritmoPlanificacion,"SRJF") == 0)
                agregarFilaXCantArticulos(&cajita[i].filita,aux);
            else if(strcmp(cajita[i].algoritmoPlanificacion,"Prioridades")==0)
                agregarFilaXtipoCliente(&cajita[i].filita,aux);
            else
                agregar(&cajita[i].filita,aux);
        }
    }
}

int cajaConMenosCliente(int tipo_pago,caja cajita[8])
{
    int i =0;

    int rta = 0;
    while(i<7) /// CAMBIAR POR UN 7
    {
        if(tipo_pago == cajita[i].tipo_pago || cajita[i].tipo_pago == 3)
        {
            if(cantidadelementos(cajita[i+1].filita) < cantidadelementos(cajita[i].filita))
                rta = i+1;
            else
               rta = i;
        }
        i++;
    }
    return rta;
}
void cargarArchivoCaja(char nombre[]) /// CARGA UN ARCHIVO CON LA INFORMACION  DE CADA CAJA
{

    int i =0;
    caja cajita;
    FILE * archi = fopen(nombre,"ab");
    if(archi == NULL)
        archi = fopen(nombre,"wb");

    while(i<8) /// CAMBIAR POR UN 8
    {
        printf("\n\n");
        cajita.nro_de_caja = i+1;
        cajita.abiertaOcerrada = 1;
        printf("Ingrese el nombre del cajero: ");
        scanf("%s",&cajita.nombreCajero);
        printf("Ingrese el algoritmo: ");
        scanf("%s",&cajita.algoritmoPlanificacion);
        printf("Ingrese tipo de pago; "); /// 1-Efectivo 2-Credito/Debito 3-Todos
        scanf("%d",&cajita.tipo_pago);
        fwrite(&cajita,1,sizeof(caja),archi);
        i++;
    }

    fclose(archi);
}

void pasarDeArchiAcaja(char nombre[],caja cajita[]) /// PASA EL CONTENIDO DE UN ARCHIVO A UN ARREGLO DE CAJAS
{
    caja aux;
    int i =0;
    FILE * archi = fopen(nombre,"rb");
    while(fread(&aux,1,sizeof(caja),archi)>0)
    {
        cajita[i].abiertaOcerrada = aux.abiertaOcerrada;
        strcpy(cajita[i].algoritmoPlanificacion,aux.algoritmoPlanificacion);
        strcpy(cajita[i].nombreCajero,aux.nombreCajero);
        cajita[i].nro_de_caja = aux.nro_de_caja;
        cajita[i].tipo_pago = aux.tipo_pago;
        inicfila(&cajita[i].filita);
        i++;
    }
    fclose(archi);
}

void leerArchivoCaja(char nombre[]) /// MUESTRA EL CONTENDIO DEL ARCHIVO
{
    caja cajita;
    FILE * archi = fopen(nombre,"rb");
    while(fread(&cajita,1,sizeof(caja),archi)>0)
    {
        mostrar1Caja(cajita);
    }

    fclose(archi);
}
